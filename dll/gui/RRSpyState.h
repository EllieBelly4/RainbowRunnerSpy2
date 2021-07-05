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

struct PropertyViewState {
    int SelectedSuperClassIndex = 0;
};

class RRSpyState {
public:
    World* CurrentWorld;
    bool PropertiesOpen;

    std::shared_ptr<RRSpyGUIEntityWrapper> CurrentSelectedEntity;
    ItemSelectState ItemSelectState;

    PropertyViewState PropertyViewState;

    void ConfirmSelectedIsVisible(ImGuiID id);

    template <class T>
    inline void SetSelectedEntity(T entity) {
        _isCurrentSelectedEntityVisible = true;
        PropertiesOpen = true;
        CurrentSelectedEntity = std::static_pointer_cast<RRSpyGUIEntityWrapper>(entity);
    }

    void DeselectEntity();

    bool IsSelectedEntityVisible();

    void OnFrameEnd();

private:
    bool _isCurrentSelectedEntityVisible;
};


#endif //RRSPY2TESTAPP_RRSPYSTATE_H
