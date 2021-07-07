//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyState.h"

void RRSpyState::ConfirmSelectedIsVisible(ImGuiID id) {
    if (CurrentSelectedEntity == nullptr || id != CurrentID) {
        return;
    }

    _isCurrentSelectedEntityVisible = true;
}

bool RRSpyState::IsSelectedEntityVisible() {
    return CurrentSelectedEntity != nullptr && _isCurrentSelectedEntityVisible;
}

void RRSpyState::OnFrameEnd() {
    _isCurrentSelectedEntityVisible = false;
}

void RRSpyState::DeselectEntity() {
    CurrentSelectedEntity = nullptr;
    PropertiesOpen = false;
}
