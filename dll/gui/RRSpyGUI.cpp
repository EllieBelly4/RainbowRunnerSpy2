//
// Created by Sophie on 26/06/2021.
//

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <memory>
#include "RRSpyGUI.h"
#include "../gameobjects/GameClientStateManager.h"
#include "../../lib/imgui/imgui_impl_dx9.h"
#include "./GameObjectPanels.h"
#include "../gameobjects/World.h"

WNDPROC gameWndProcHandler;

ImFont* consolas;

void RRSpyGUI::Init() {
    gameWndProcHandler = (WNDPROC) SetWindowLongPtr(GetActiveWindow(), GWLP_WNDPROC, (LONG_PTR) windowProc_hook);

    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;

    consolas = io.Fonts->AddFontFromFileTTF("consola.ttf", 16);

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

    ImGui::PushFont(consolas);
    RenderInfoBox();
    ImGui::PopFont();

    ImGui::ShowDemoWindow();

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

void RRSpyGUI::RenderInfoBox() {
    static bool openMain = true;

    ImGui::Begin("RRSpy2", &openMain);

    try {
        RenderGameClientStateManager();
        RenderWorld();

        if (ImGui::TreeNodeEx("Entities", ImGuiTreeNodeFlags_Framed)) {
            if (CurrentWorld != nullptr && CurrentWorld->EntityManager != nullptr) {
                RenderEntityManagerEntities(CurrentWorld->EntityManager);
            }
            ImGui::TreePop();
        }
    } catch (...) {
        ImGui::TextColored(ImVec4{1.000f, 0.443f, 0.384f, 1}, "Error");
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

bool PasteToClipboard(const std::string &text) {
    std::cout << "Copy Value " << text << std::endl;

    bool succeeded = false;

    if (HANDLE clipdata = GlobalAlloc(GMEM_FIXED, text.length() + 1)) {
        memcpy(clipdata, text.data(), text.length() + 1);

        if (OpenClipboard(NULL)) {
            if (EmptyClipboard() && SetClipboardData(CF_TEXT, clipdata))
                succeeded = true;

            CloseClipboard();
        }

        if (!succeeded)
            GlobalFree(clipdata);
    }

    return succeeded;
}