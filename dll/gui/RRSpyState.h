//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYSTATE_H
#define RRSPY2TESTAPP_RRSPYSTATE_H

#include <memory>
#include <chrono>
#include "../gameobjects/World.h"
#include "entities/RRSpyGUIBaseEntityWrapper.h"
#include "views/viewhandlers/UnknownView.h"

struct ItemSelectState {
    ImGuiID LastIDClicked;
    std::chrono::milliseconds LastClickedTime = std::chrono::milliseconds(0);
};

struct PropertyViewState {
    int SelectedSuperClassIndex = 0;
};

class RRSpyState {
public:
    World* CurrentWorld;
    bool PropertiesOpen;

    std::shared_ptr<RRSpyGUIBaseEntityWrapper> CurrentSelectedEntity;
    void* CurrentSelectedDREntity;
    ImGuiID CurrentID;
    ItemSelectState ItemSelectState;

    PropertyViewState PropertyViewState;

    void ConfirmSelectedIsVisible(ImGuiID id);

    inline void SetSelectedEntity(std::shared_ptr<RRSpyGUIBaseEntityWrapper> entity, void* drEntity, ImGuiID id) {
        _isCurrentSelectedEntityVisible = true;
        PropertiesOpen = true;
        CurrentSelectedEntity = entity;
        CurrentSelectedDREntity = drEntity;
        CurrentID = id;
    }

    void DeselectEntity();

    bool IsSelectedEntityVisible();

    void OnFrameEnd();

private:
    bool _isCurrentSelectedEntityVisible;
};


#endif //RRSPY2TESTAPP_RRSPYSTATE_H
