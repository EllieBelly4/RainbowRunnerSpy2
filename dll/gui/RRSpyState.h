//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYSTATE_H
#define RRSPY2TESTAPP_RRSPYSTATE_H

#include <memory>
#include <chrono>
#include "../gameobjects/World.h"
#include "entities/RRSpyGUIEntityWrapper.h"

struct ItemSelectState {
    ImGuiID LastIDClicked;
    std::chrono::milliseconds LastClickedTime = std::chrono::milliseconds(0);
};

class RRSpyState {
public:
    World* CurrentWorld;

    std::shared_ptr<RRSpyGUIEntityWrapper> CurrentSelectedEntity;
    ItemSelectState ItemSelectState;
    void ConfirmSelectedIsVisible(ImGuiID id);
    void SetSelectedEntity(std::shared_ptr<RRSpyGUIEntityWrapper> entity);
    bool IsSelectedEntityVisible();

    void OnFrameEnd();

private:
    bool _isCurrentSelectedEntityVisible;
};


#endif //RRSPY2TESTAPP_RRSPYSTATE_H
