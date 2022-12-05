//
// Created by Sophie on 04/07/2021.
//

#include "../../../gameobjects/map.h"
#include "../../general/structs.h"
#include "../../RRSpyGUI.h"
#include "../../../state.h"
#include "ViewHandler.h"


bool ViewHandler::BeginPropertyTable(std::string name, int cols) {
    ImGui::PushFont(firaHeading);
    ImGui::TextColored(entityColour, (name + " properties").c_str());
    ImGui::PopFont();

    return ImGui::BeginTable((std::string("PropertiesLayoutTable##") + name).c_str(), cols,
                             ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_SizingFixedFit);
}

bool ViewHandler::BeginFullPropertyTable(std::string name) {
    auto open = ImGui::BeginTabItem(name.c_str());

    if (open) {
        if (ImGui::BeginTable((std::string("PropertiesLayoutTable##") + name).c_str(), 5,
                              ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_SizingFixedFit)) {
            ImGui::TableSetupColumn("Name");
            ImGui::TableSetupColumn("ValueInt");
            ImGui::TableSetupColumn("ValueFloat");
            ImGui::TableSetupColumn("ValueHex");
            ImGui::TableSetupColumn("Location");
            ImGui::TableHeadersRow();
        }
    }

    return open;
}

void ViewHandler::EndPropertyTable() {
    ImGui::EndTable();
    ImGui::EndTabItem();
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

ListItemResult ViewHandler::RenderSelectableListItem(int i, const char *label, ImGuiID id) {
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

    ImDrawList *windowDrawList = ImGui::GetWindowDrawList();
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

void ViewHandler::RenderProperties(void *) {

}

void ViewHandler::RenderCustomView(DFCNode *) {

}

template<>
void ViewHandler::writeStringValue<float>(const char *stringValue, float *value) {
    float newFloatVal;

    try {
        newFloatVal = std::stof(stringValue);
    }
    catch (std::invalid_argument &e) {
        logger->Write("Failed to parse float from string");
        return;
    }

    *value = newFloatVal;
}

template<>
void ViewHandler::writeStringValue<unsigned int>(const char *stringValue, unsigned int *value) {
    unsigned int newFloatVal;

    try {
        newFloatVal = std::stoi(stringValue);
    }
    catch (std::invalid_argument &e) {
        logger->Write("Failed to parse unsigned int from string");
        return;
    }

    *value = reinterpret_cast<unsigned int>(newFloatVal);
}

template<>
void ViewHandler::writeStringValue<int>(const char *stringValue, int *value) {
    int newFloatVal;

    try {
        newFloatVal = std::stoi(stringValue);
    }
    catch (std::invalid_argument &e) {
        logger->Write("Failed to parse int from string");
        return;
    }

    *value = reinterpret_cast<int>(newFloatVal);
}

void ViewHandler::RenderErrorRow(const std::string &name) {
    ImGui::TableNextColumn();
    ImGui::PushID("PropertyName");
    ImGui::TextColored(propertyColour, name.c_str());
    ImGui::PopID();

    ImGui::TableNextColumn();
    ImGui::TextColored(ImVec4(0.95, 0.1, 0.15, 1), "error");
    ImGui::TableNextRow();
}

void ViewHandler::SelectEntity(void *entity, ImGuiID id) {
    state->SetSelectedEntity(GetEntityWrapper((void *) reinterpret_cast<unsigned int *>(entity)[0]), entity, id);
}