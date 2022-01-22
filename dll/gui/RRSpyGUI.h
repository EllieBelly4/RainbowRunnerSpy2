//
// Created by Sophie on 26/06/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYGUI_H
#define RRSPY2TESTAPP_RRSPYGUI_H

#include <windows.h>
#include <utility>

#include "../../lib/imgui/imgui_impl_win32.h"
#include "../gameobjects/EntityManager.h"
#include "views/RRSpyGUIInfoView.h"
#include "views/RRSpyGUIPropertyView.h"
#include "entities/RRSpyGUIBaseEntityWrapper.h"

extern LRESULT CALLBACK windowProc_hook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class RRSpyGUI {
public:
    explicit RRSpyGUI(std::shared_ptr<RRLog::Log> logger) : logger(logger) {};

    RRSpyGUI(std::shared_ptr<RRSpyState> state, std::shared_ptr<RRLog::Log> logger);

    bool IsVisible = true;

    void Init();

    void Render();

    void ToggleVisible() {
        IsVisible = !IsVisible;
    }

    std::shared_ptr<RRSpyGUIBaseEntityWrapper> CurrentSelectedEntity;
private:
    std::shared_ptr<RRSpyState> _state;
    std::shared_ptr<RRLog::Log> logger;
    std::shared_ptr<RRSpyGUIInfoView> infoView;
    std::shared_ptr<RRSpyGUIPropertyView> propertyView;

    void RenderInfoBox();

    void RenderPropertyBox();
};

extern std::shared_ptr<RRSpyGUI> GUI;

extern ImFont* consolasNormal;
extern ImFont* consolasHeading;
extern ImFont* firaNormal;
extern ImFont* firaHeading;

#endif //RRSPY2TESTAPP_RRSPYGUI_H
