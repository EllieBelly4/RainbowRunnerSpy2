//
// Created by Sophie on 26/06/2021.
//

#include <windows.h>
#include <iostream>
#include "RRSpyGUI.h"
#include "../../lib/imgui/imgui_impl_dx9.h"
#include "./GameObjectPanels.h"
#include "../gameobjects/World.h"
#include "entities/properties.h"

//const ImVec4 &windowBackground = ImVec4(0.102f,0.071f,0.102f, 0.95);
ImVec4 windowBackground = ImVec4(0.153f,0.153f,0.153f, 0.99);
ImVec4 windowTitleBg = ImVec4(0.855f,0.255f,0.404f, 0.99);

ImFont* consolasNormal;
ImFont* consolasHeading;
ImFont* firaNormal;
ImFont* firaHeading;

WNDPROC gameWndProcHandler;

void RRSpyGUI::Init() {
    logger->Write<std::string>("Init");
    gameWndProcHandler = (WNDPROC) SetWindowLongPtr(GetActiveWindow(), GWLP_WNDPROC, (LONG_PTR) windowProc_hook);

    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    (void) io;

    consolasNormal = io.Fonts->AddFontFromFileTTF("consola.ttf", 16);
    consolasHeading = io.Fonts->AddFontFromFileTTF("consola.ttf", 20);
    firaNormal = io.Fonts->AddFontFromFileTTF("FiraSansCondensed-Medium.ttf", 18);
    firaHeading = io.Fonts->AddFontFromFileTTF("FiraSansCondensed-Medium.ttf", 22);

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

    ImGui::PushStyleColor(ImGuiCol_WindowBg, windowBackground);
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, windowTitleBg);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 2);
    ImGui::PushStyleColor(ImGuiCol_Header, titleBg);
    ImGui::PushStyleColor(ImGuiCol_HeaderActive, titleBgActive);
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, titleBgActive);


    ImGui::PushFont(firaNormal);
    RenderInfoBox();
    ImGui::PopFont();

    ImGui::PushFont(firaNormal);
    RenderPropertyBox();
    ImGui::PopFont();

    ImGui::ShowDemoWindow();
    ImGui::PopStyleColor(5);
    ImGui::PopStyleVar(1);

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

void RRSpyGUI::RenderPropertyBox() {
    static bool openProperties = true;

    ImGui::Begin("Properties", &openProperties);

    if (SelectedDFCNode != nullptr){
        RenderPropertiesForDFCNode(SelectedDFCNode);
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

