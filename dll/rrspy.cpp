#include "rrspy.h"
#include "common.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include "../lib/imgui/imgui_impl_dx9.h"
#include "../lib/imgui/imgui_impl_win32.h"

WNDPROC gameWndProcHandler;

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

    OnInit();

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

    OnRender();

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

void WorldUIOnDrawHook() {
    asm (
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
    :
    :"m" (worldUIOnDrawReturnAddress)
    );
}

void DFCRootControlRenderHook() {
    asm (
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
    :
    :"m" (DFCRootControlRenderReturnAddress)
    );
}

void OnRender() {
//    std::cout << "Render" << std::endl;

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    { //using brackets to control scope makes formatting and checking where the ImGui::Render(); is easier.

//        ImGui::Begin("Framerate", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
//        ImGui::SetWindowSize(ImVec2(200, 30), ImGuiCond_FirstUseEver);
//        ImGui::SetWindowPos(ImVec2(2, 2), ImGuiCond_FirstUseEver);
//        ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//        ImGui::End();
        ImGui::ShowDemoWindow();
    }
    ImGui::EndFrame();
    IDirect3DDevice9* realDevice = rrSpyDirect3D9->GetRealDevice();

//    realDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
//    realDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
//    realDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
//    D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int) (clear_color.x * clear_color.w * 255.0f),
//                                          (int) (clear_color.y * clear_color.w * 255.0f),
//                                          (int) (clear_color.z * clear_color.w * 255.0f),
//                                          (int) (clear_color.w * 255.0f));
//    realDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);

//    if (realDevice->BeginScene() >= 0) {
    std::cout << "Drawing Scene" << std::endl;
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
//        realDevice->EndScene();
//    }
}

void OnInit() {
    gameWndProcHandler = (WNDPROC) SetWindowLongPtr(GetActiveWindow(), GWLP_WNDPROC, (LONG_PTR) windowProc_hook);

    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;

    ImGui_ImplWin32_Init(GetActiveWindow());
    ImGui_ImplDX9_Init(rrSpyDirect3D9->GetRealDevice());

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

LRESULT CALLBACK windowProc_hook(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    // Toggle the overlay using the delete key
//    if (uMsg == WM_KEYDOWN && wParam == VK_DELETE) {
//        menuShown = !menuShown;
//        return false;
//    }
//    asm("INT3");

    auto io = ImGui::GetIO();

    if (io.WantCaptureMouse || io.WantCaptureKeyboard) {
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
        return true;
    }

    // Otherwise call the game's wndProc function
    CallWindowProc(gameWndProcHandler, hWnd, uMsg, wParam, lParam);
    return true;
}
