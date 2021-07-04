//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyState.h"

void RRSpyState::ConfirmSelectedIsVisible(ImGuiID id) {
    if (CurrentSelectedEntity == nullptr || id != CurrentSelectedEntity->ImGui_ID) {
        return;
    }

    _isCurrentSelectedEntityVisible = true;
}

bool RRSpyState::IsSelectedEntityVisible() {
    return CurrentSelectedEntity != nullptr && _isCurrentSelectedEntityVisible;
}

void RRSpyState::SetSelectedEntity(std::shared_ptr<RRSpyGUIEntityWrapper> entity) {
    _isCurrentSelectedEntityVisible = true;
    CurrentSelectedEntity = entity;
}

void RRSpyState::OnFrameEnd() {
    _isCurrentSelectedEntityVisible = false;
}
