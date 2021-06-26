//
// Created by Sophie on 26/06/2021.
//

#include <windows.h>
#include <iostream>
#include <iomanip>
#include "RRSpyGUI.h"
#include "../gameobjects/GameClientStateManager.h"
#include "../../lib/imgui/imgui_impl_dx9.h"

WNDPROC gameWndProcHandler;

void RRSpyGUI::Init() {
    gameWndProcHandler = (WNDPROC) SetWindowLongPtr(GetActiveWindow(), GWLP_WNDPROC, (LONG_PTR) windowProc_hook);

    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;

    ImGui_ImplWin32_Init(GetActiveWindow());
    ImGui_ImplDX9_Init(rrSpyDirect3D9->GetRealDevice());

    std::cout << "Init" << std::endl;
}

void RRSpyGUI::Render() {
    if (!IsVisible) {
        return;
    }

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

//    std::cout << "Drawing Scene" << std::endl;
    RenderInfoBox();
    ImGui::ShowDemoWindow();

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

void RRSpyGUI::RenderInfoBox() {
    static bool openMain = true;

    ImGui::Begin("RRSpy2", &openMain);
    std::stringstream gameClientStateManagerText;

    char* gameClientStateManagerPtr = (char*) 0x9360C8;
//    gameClientStateManagerText << "GameClientStateManager: 0x"
//                               << std::hex << std::setfill('0') << std::setw(2)
//                               << *(int*) gameClientStateManagerPtr;

//    asm("INT3");

    auto gameClientStateManager = (GameClientStateManager*) (gameClientStateManagerPtr);

    ImGui::Text("State: ");
    ImGui::SameLine();
    ImGui::TextColored(ImVec4(0.8f, 0.8f, 0.1f, 1), GetStateString(gameClientStateManager));

    ImGui::SetNextItemOpen(true);
    if (ImGui::TreeNode("GameClientStateManager")) {
        static ImGuiTableFlags tableFlags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;

        char hexVal[128];

        if (ImGui::BeginTable("table1", 4, tableFlags)) {
            ImGui::TableSetupColumn("Address");
            ImGui::TableSetupColumn("Offset");
            ImGui::TableSetupColumn("Value");
            ImGui::TableSetupColumn("Name");
            ImGui::TableHeadersRow();

            for (int i = 0; i < 32; ++i) {
                ImGui::TableNextRow();

                char* valPtr = gameClientStateManagerPtr + i * 4;

                ImGui::TableSetColumnIndex(0);
                sprintf(hexVal, "0x%08x", (int) valPtr);
                ImGui::Text(hexVal);

                ImGui::TableSetColumnIndex(1);
                sprintf(hexVal, "0x%04x", i * 4);
                ImGui::Text(hexVal);

                ImGui::TableSetColumnIndex(2);
                sprintf(hexVal, "0x%08x", (int) *valPtr);
                ImGui::Text(hexVal);

                ImGui::TableSetColumnIndex(3);
                ImGui::Text(GetGameClientStateManagerProperty(i));
            }

            ImGui::EndTable();
        }

        ImGui::TreePop();
    }

    ImGui::End();
}

LRESULT CALLBACK windowProc_hook(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_KEYDOWN && wParam == VK_F1) {
        GUI->ToggleVisible();
        return false;
    }

    auto io = ImGui::GetIO();

    if (GUI->IsVisible && io.WantCaptureMouse || io.WantCaptureKeyboard) {
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
        return true;
    }

    // Otherwise call the game's wndProc function
    CallWindowProc(gameWndProcHandler, hWnd, uMsg, wParam, lParam);
    return true;
}