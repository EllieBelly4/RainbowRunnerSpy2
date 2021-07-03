//
// Created by Sophie on 26/06/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYGUI_H
#define RRSPY2TESTAPP_RRSPYGUI_H

#include <windows.h>

#include <utility>
#include "../common.h"
#include "../../lib/imgui/imgui_impl_win32.h"
#include "../gameobjects/EntityManager.h"

extern LRESULT CALLBACK windowProc_hook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class RRSpyGUI {
public:
    explicit RRSpyGUI(std::shared_ptr<log::Log> logger) : logger(std::move(logger)) {};

    bool IsVisible = true;

    void Init();

    void Render();

    void ToggleVisible() {
        IsVisible = !IsVisible;
    }

private:
    std::shared_ptr<log::Log> logger;

    void RenderInfoBox();

    void RenderPropertyBox();
};

bool PasteToClipboard(const std::string &text);

extern std::shared_ptr<RRSpyGUI> GUI;

extern ImFont* consolasNormal;
extern ImFont* consolasHeading;
extern ImFont* firaNormal;
extern ImFont* firaHeading;

#endif //RRSPY2TESTAPP_RRSPYGUI_H
