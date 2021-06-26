//
// Created by Sophie on 26/06/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYGUI_H
#define RRSPY2TESTAPP_RRSPYGUI_H

#include <windows.h>
#include "../common.h"
#include "../../lib/imgui/imgui_impl_win32.h"

extern LRESULT CALLBACK windowProc_hook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class RRSpyGUI {
public:
    bool IsVisible = true;

    void Init();

    void Render();

    void ToggleVisible() {
        IsVisible = !IsVisible;
    }
private:
    void RenderInfoBox();
};

extern std::shared_ptr<RRSpyGUI> GUI;

#endif //RRSPY2TESTAPP_RRSPYGUI_H
