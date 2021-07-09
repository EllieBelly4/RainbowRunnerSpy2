//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyGUIPropertyView.h"
#include "../../common.h"
#include "../general/gui_functions.h"

RRSpyGUIPropertyView::RRSpyGUIPropertyView(std::shared_ptr<RRSpyState> state, std::shared_ptr<log::Log> logger)
        : _state(state), logger(logger) {
}

void RRSpyGUIPropertyView::Render() {
    ImGui::Begin("Properties", &_state->PropertiesOpen);

    auto currentSelectedEntity = _state->CurrentSelectedEntity;
    auto entity = _state->CurrentSelectedDREntity;

    if (currentSelectedEntity != nullptr && !IsBadReadPtr(entity)) {
        char hexStr[16];

        sprintf(hexStr, "0x%08X", (int)entity);

        ImGui::Text("Location:");
        ImGui::SameLine();
        ImGui::Text(hexStr);
        ImGui::SameLine();
        AddCopyText(hexStr);

        currentSelectedEntity->RenderProperties(entity);
    }

    ImGui::End();
}
