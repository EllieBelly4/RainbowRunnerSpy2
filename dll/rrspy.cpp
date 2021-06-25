#include "rrspy.h"
#include "common.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include "../lib/imgui/imgui_impl_dx9.h"

//Returns the last Win32 error, in string format. Returns an empty string if there is no error.
std::string GetLastErrorAsString() {
    //Get the error message ID, if any.
    DWORD errorMessageID = ::GetLastError();
    if (errorMessageID == 0) {
        return std::string(); //No error message has been recorded
    }

    LPSTR messageBuffer = nullptr;

    //Ask Win32 to give us the string version of that message ID.
    //The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
    size_t size = FormatMessageA(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR) &messageBuffer, 0, NULL);

    //Copy the error message into a std::string.
    std::string message(messageBuffer, size);

    //Free the Win32's string's buffer.
    LocalFree(messageBuffer);

    return message;
}

// RRSpy2TestApplication
//const DWORD ptr = 0x00401480;
//int bytesToPatch = 6;

void WorldUpdateHook() {
    asm (
    "pushad;"
    );

    OnWorldUpdate();

    asm(
    "popad;"
    // TestApplication
    //    "imul eax, 0x3E8;"
    // DR Client
    "mov ecx, [edi+0xF4];"
    "mov esp, ebp;"
    "pop ebp;"
    "push %0;"
    "ret;"
    :
    :"m" (worldUpdateReturnAddress)
    );
}

void GameExitInitResourcesHook() {
    asm (
    "pushad;"
    );

    OnGameExitInitResources();

    asm(
    "popad;"
    "mov eax, [eax+0x1FC];"
    "mov esp, ebp;"
    "pop ebp;"
    "push %0;"
    "ret;"
    :
    :"m" (gameExitInitResourcesReturnAddress)
    );
}

void RendererRenderHook() {
    asm (
    "pushad;"
    );

    OnRendererRender();

    asm(
    "popad;"
    "mov edx, [eax+0x8C];"
    "mov esp, ebp;"
    "pop ebp;"
    "push %0;"
    "ret;"
    :
    :"m" (rendererRenderReturnAddress)
    );
}

void OnRendererRender() {
//    std::cout << "Render" << std::endl;
}

void OnGameExitInitResources() {
    std::cout << "Init" << std::endl;
}

void OnWorldUpdate() {
//    std::cout << "World Update" << std::endl;
}

void SetupLog() {
    outLog.open("D:\\Work\\dungeon-runners\\Logs\\RRSpyOut.log", std::fstream::out | std::fstream::app);
}

void Inject(DWORD address, int bytesToPatch, DWORD func) {
    SetupLog();

    DWORD old;

    auto result = VirtualProtect((void*) address, bytesToPatch, PAGE_EXECUTE_READWRITE, &old);

    if (result == 0) {
        outLog << GetLastErrorAsString() << std::endl;
    }

    outLog << GetCurrentProcessId() << std::endl;

    BYTE* data = new BYTE[bytesToPatch];

    // Copy instructions at patch address for viewing
    memcpy(data, (void*) address, bytesToPatch);

    std::cerr << "RRSPY Patching" << std::endl;

    for (int i = 0; i < bytesToPatch; i++)
        outLog << std::hex << std::setfill('0') << std::setw(2) << (int) data[i] << " ";
    outLog << std::endl;

    auto dest = reinterpret_cast<char*>(address);

    dest[0] = (char) 0xE9;
    DWORD offset = ((DWORD) func - address - 5); // 5 == size of jump instruction
    memcpy(dest + 1, &offset, sizeof(DWORD));

    for (int i = 0; i < bytesToPatch - 5; ++i) {
        dest[i + 5] = (char) 0x90;
    }

    result = VirtualProtect((LPVOID) address, bytesToPatch, old, &old);

    if (result == 0) {
        outLog << GetLastErrorAsString() << std::endl;
    }
}

void DoIt() {
    std::cout << "I am alive" << std::endl;
}

void Stop() {
    outLog.close();
}