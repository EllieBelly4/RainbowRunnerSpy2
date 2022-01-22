//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyGUIPropertyView.h"

RRSpyGUIPropertyView::RRSpyGUIPropertyView(std::shared_ptr<RRSpyState> state, std::shared_ptr<RRLog::Log> logger)
        : _state(state), logger(logger) {
}

void RRSpyGUIPropertyView::Render() {
    ImGui::Begin("Properties", &_state->PropertiesOpen);

    auto currentSelectedEntity = _state->CurrentSelectedEntity;
    auto entity = _state->CurrentSelectedDREntity;

    if (currentSelectedEntity != nullptr && !IsBadReadPtr(entity)) {
        char hexStr[16];

        sprintf(hexStr, "0x%08X", (int) entity);

        ImGui::Text("Location:");
        ImGui::SameLine();
        ImGui::Text(hexStr);
        ImGui::SameLine();
        AddCopyText(hexStr);

        ImGui::PushStyleColor(ImGuiCol_Tab, tabColour);
        ImGui::PushStyleColor(ImGuiCol_TabActive, tabSelectedColour);

        if (dynamic_cast<DFCNodeView*>(currentSelectedEntity->View) != nullptr) {
            DFCNodeView::RenderNodeCrumblebar((DFCNode*) entity);
        }

        if (ImGui::BeginTabBar("propertyview")) {
            currentSelectedEntity->RenderProperties(entity);
            ImGui::EndTabBar();
        }

        ImGui::PopStyleColor(2);
    }

    ImGui::End();
}
