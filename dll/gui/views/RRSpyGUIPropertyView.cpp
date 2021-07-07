//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyGUIPropertyView.h"
#include "../../common.h"

RRSpyGUIPropertyView::RRSpyGUIPropertyView(std::shared_ptr<RRSpyState> state, std::shared_ptr<log::Log> logger)
        : _state(state), logger(logger) {
}

void RRSpyGUIPropertyView::Render() {
    ImGui::Begin("Properties", &_state->PropertiesOpen);

    auto currentSelectedEntity = _state->CurrentSelectedEntity;
    auto entity = _state->CurrentSelectedDREntity;

    if (currentSelectedEntity != nullptr && !IsBadReadPtr(entity)) {
        currentSelectedEntity->RenderProperties(entity);
    }

    ImGui::End();
}
