//
// Created by Sophie on 04/07/2021.
//

#include "ViewHandler.h"
#include "../../../../lib/imgui/imgui.h"
#include "../../general/colours.h"
#include "../../general/gui_functions.h"

bool ViewHandler::BeginPropertyTable() {
    return ImGui::BeginTable("PropertiesLayoutTable", 2,
                             ImGuiTableFlags_NoBordersInBody | ImGuiTableFlags_SizingFixedFit);
}

void ViewHandler::EndPropertyTable(){
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
