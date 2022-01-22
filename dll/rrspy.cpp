#include "common.h"
#include "rrspy.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include "gameobjects/World.h"

std::shared_ptr<RRSpyGUI> GUI;
std::shared_ptr<RRLog::Log> logger;
std::shared_ptr<RRLog::DataStream> dataStream;
std::shared_ptr<RRLog::MemoryDataStream> memoryDataStream;
std::shared_ptr<RRSpyState> state;

//Returns the last Win32 error, in string format. Returns an empty string if there is no error.
std::string GetLastErrorAsString()
{
	//Get the error message ID, if any.
	DWORD errorMessageID = ::GetLastError();
	if (errorMessageID == 0)
	{
		return {}; //No error message has been recorded
	}

	LPSTR messageBuffer = nullptr;

	//Ask Win32 to give us the string version of that message ID.
	//The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
	size_t size = FormatMessageA(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

	//Copy the error message into a std::string.
	std::string message(messageBuffer, size);

	//Free the Win32's string's buffer.
	LocalFree(messageBuffer);

	return message;
}

void WorldUpdateHook()
{
	asm (
	".intel_syntax;"
	"pushad;"
	);

	OnWorldUpdate();

	asm(
	"popad;"
	"mov ecx, [edi+0xF4];"
	"mov esp, ebp;"
	"pop ebp;"
	"push %0;"
	"ret;"
	".att_syntax"
	:
	:"m" (worldUpdateReturnAddress)
	);
}

void GameExitInitResourcesHook()
{
	asm (
	".intel_syntax;"
	"pushad;"
	);

	OnInit();

	asm(
	"popad;"
	"mov eax, [eax+0x1FC];"
	"mov esp, ebp;"
	"pop ebp;"
	"push %0;"
	"ret;"
	".att_syntax"
	:
	:"m" (gameExitInitResourcesReturnAddress)
	);
}

void RendererRenderHook()
{
	asm (
	".intel_syntax;"
	"pushad;"
	);

	OnRender();

	asm(
	"popad;"
	"mov edx, [eax+0x8C];"
	"mov esp, ebp;"
	"pop ebp;"
	"push %0;"
	"ret;"
	".att_syntax"
	:
	:"m" (rendererRenderReturnAddress)
	);
}

void WorldUIOnDrawHook()
{
	asm (
	".intel_syntax;"
	"pushad;"
	);

	OnRender();

	asm(
	"popad;"
	"mov eax,fs:0x0;"
	"mov esp, ebp;"
	"pop ebp;"
	"push %0;"
	"ret;"
	".att_syntax"
	:
	:"m" (worldUIOnDrawReturnAddress)
	);
}

void DFCRootControlRenderHook()
{
	asm (
	".intel_syntax;"
	"pushad;"
	);

	OnRender();

	asm(
	"popad;"
	"mov fs:0x0, ecx;"
	"mov esp, ebp;"
	"pop ebp;"
	"push %0;"
	"ret;"
	".att_syntax"
	:
	:"m" (DFCRootControlRenderReturnAddress)
	);
}

// C7 40 48 00 00 00 00
void GameClientUpdateAppHook()
{
	asm (
	".intel_syntax;"
	"pushad;"
	);

	OnUpdate();

	asm(
	"popad;"
	"mov DWORD PTR [eax+0x48], 0x00000000;"
	"mov esp, ebp;"
	"pop ebp;"
	"push %0;"
	"ret;"
	".att_syntax"
	:
	:"m" (GameClientUpdateAppReturnAddress)
	);
}

extern "C" int exc(_In_ EXCEPTION_POINTERS* lpEP);

int exc(_In_ EXCEPTION_POINTERS* lpEP)
{
	printf("Exception code: %u  Flags: %u\n", lpEP->ExceptionRecord->ExceptionCode,
			lpEP->ExceptionRecord->ExceptionFlags);
	return EXCEPTION_EXECUTE_HANDLER;
}

void OnRender()
{
	GUI->Render();
}

void OnUpdate()
{
	if(IsBadReadPtr(state->GameClientStateManager)) {
		return;
	}

	memoryDataStream->Tick(state->GameClientStateManager->CurrentFrame);
}

void OnInit()
{
	state = std::make_shared<RRSpyState>();
	logger = std::make_shared<RRLog::Log>("logs/runlog.txt");
	dataStream = std::make_shared<RRLog::DataStream>(R"(F:\Projects\DungeonRunners\Logs)");

	const std::string& fileName = dataStream->OpenTimed();

	memoryDataStream = std::make_shared<RRLog::MemoryDataStream>(dataStream);

	logger->Write("Datastream created: " + fileName);

	GUI = std::make_shared<RRSpyGUI>(state, logger);
	GUI->Init();
}

struct World* CurrentWorld = nullptr;

void OnWorldUpdate()
{
	asm (
	".intel_syntax noprefix;"
	"mov %0, ecx;"
	".att_syntax"
	: "=r"(CurrentWorld)
	:
	);

	state->CurrentWorld = CurrentWorld;

	char* gameClientStateManagerPtr = (char*)0x9360C8;
	state->GameClientStateManager = (GameClientStateManager*)(gameClientStateManagerPtr);
}

void SetupLog()
{
	outLog.open("D:\\Work\\dungeon-runners\\Logs\\RRSpyOut.log", std::fstream::out | std::fstream::app);
}

void Inject(DWORD address, int bytesToPatch, DWORD func)
{
	SetupLog();

	DWORD old;

	auto result = VirtualProtect((void*)address, bytesToPatch, PAGE_EXECUTE_READWRITE, &old);

	if (result == 0)
	{
		outLog << GetLastErrorAsString() << std::endl;
	}

	outLog << GetCurrentProcessId() << std::endl;

	BYTE* data = new BYTE[bytesToPatch];

	// Copy instructions at patch address for viewing
	memcpy(data, (void*)address, bytesToPatch);

	std::cerr << "RRSPY Patching" << std::endl;

	for (int i = 0; i < bytesToPatch; i++)
		outLog << std::hex << std::setfill('0') << std::setw(2) << (int)data[i] << " ";
	outLog << std::endl;

	auto dest = reinterpret_cast<char*>(address);

	dest[0] = (char)0xE9;
	DWORD offset = ((DWORD)func - address - 5); // 5 == size of jump instruction
	memcpy(dest + 1, &offset, sizeof(DWORD));

	for (int i = 0; i < bytesToPatch - 5; ++i)
	{
		dest[i + 5] = (char)0x90;
	}
//	[ 22-01-2022 19:34:20 ] [ DEBUG ] - ffffff80010000

	result = VirtualProtect((LPVOID)address, bytesToPatch, old, &old);

	if (result == 0)
	{
		outLog << GetLastErrorAsString() << std::endl;
	}
}

void DoIt()
{
	std::cout << "I am alive" << std::endl;
}

void Stop()
{
	outLog.close();
}
