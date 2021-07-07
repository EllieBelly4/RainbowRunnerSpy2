//
// Created by Sophie on 04/07/2021.
//

#include "ViewHandler.h"
#include "../../general/colours.h"
#include "../../general/gui_functions.h"
#include "../../../common.h"
#include "../../RRSpyGUI.h"

bool ViewHandler::BeginPropertyTable(std::string name) {
    return ImGui::BeginTable((std::string("PropertiesLayoutTable##") + name).c_str(), 2,
                             ImGuiTableFlags_NoBordersInBody | ImGuiTableFlags_SizingFixedFit);
}

void ViewHandler::EndPropertyTable() {
    ImGui::EndTable();
}

void ViewHandler::RenderProperty(const std::string &name, const std::string &value) {
    ImGui::PushID(name.c_str());

    ImGui::TableNextColumn();
    ImGui::PushID("PropertyName");
    ImGui::TextColored(propertyColour, name.c_str());
    ImGui::PopID();

    ImGui::TableNextColumn();
    ImGui::PushID("PropertyValue");
    ImGui::TextColored(titleAltText, value.c_str());
    ImGui::SameLine();
    AddCopyText(value);
    ImGui::PopID();

    ImGui::PopID();
}

ListItemResult ViewHandler::RenderSelectableListItem(int i, const char* label, ImGuiID id) {
    auto result = ListItemOK;
    auto textSize = ImGui::CalcTextSize(label);
    auto cursorPos = ImGui::GetCursorScreenPos();

    auto lineMax = Add(cursorPos, textSize);
    auto lineMin = cursorPos;

    lineMin.y -= 2;

    lineMax.x = ImGui::GetContentRegionAvailWidth() + cursorPos.x;
    lineMax.y += 2;

    bool hovered = ImGui::IsMouseHoveringRect(lineMin, lineMax);

    auto lineColour = TO_IMCOL32(panelBg);

    if (i % 2 == 0) {
        lineColour = hovered ? TO_IMCOL32(panelBgLt) : TO_IMCOL32(panelBg);
    } else {
        lineColour = hovered ? TO_IMCOL32(listAltBgLt) : TO_IMCOL32(listAltBg);
    }

    if (!IsBadReadPtr(state->CurrentSelectedEntity.get()) && state->CurrentID == id) {
        lineColour = TO_IMCOL32(listSelected);
        state->ConfirmSelectedIsVisible(id);
    }

    ImDrawList* windowDrawList = ImGui::GetWindowDrawList();
    windowDrawList->AddRectFilled(lineMin, lineMax, lineColour, 2);

    if (hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
        result = ListItemClicked;
    }

    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 2);
    ImGui::Text(label);

    return result;
}

void ViewHandler::AddHeading(std::string text) {
    ImGui::PushFont(firaHeading);

    ImGui::TextColored(entityColour, text.c_str());

    ImGui::PopFont();
}

void ViewHandler::RenderProperties(void*) {

}
