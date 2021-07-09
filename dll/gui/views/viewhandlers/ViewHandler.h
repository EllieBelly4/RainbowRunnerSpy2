//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_VIEWHANDLER_H
#define RRSPY2TESTAPP_VIEWHANDLER_H

#include <string>
#include <memory>
#include "../../../gameobjects/Entities/DFCNode.h"
#include "../../../../lib/imgui/imgui.h"
#include "../../general/colours.h"
#include "../../general/gui_functions.h"
#include "../../../common.h"

enum ListItemResult {
    ListItemOK, ListItemClicked
};

class ViewHandler {
public:

    static void RenderProperty(const std::string &name, const std::string &value);

    static bool BeginPropertyTable(std::string, int cols = 2);

    static bool BeginFullPropertyTable(std::string);

    static void EndPropertyTable();

    static void AddHeading(std::string);

    template<typename T>
    static void RenderPropertyWithHex(const std::string &name, T* value);

    static ListItemResult RenderSelectableListItem(int i, const char* label, ImGuiID id);

    virtual void RenderProperties(void*);
};

template<typename T>
void ViewHandler::RenderPropertyWithHex(const std::string &name, T* value) {
    if (IsBadReadPtr(value)) {
        ImGui::TableNextColumn();
        ImGui::PushID("PropertyName");
        ImGui::TextColored(propertyColour, name.c_str());
        ImGui::PopID();

        ImGui::TableNextColumn();
        ImGui::TextColored(ImVec4(0.95, 0.1, 0.15, 1), "error");
        return;
    }

    ImGui::PushID(name.c_str());
    char hexVal[32];

    sprintf(hexVal, (std::string("0x%0") + std::to_string(sizeof(T)) + "X").c_str(), *value);

    RenderProperty(name, std::to_string(*value));

    ImGui::TableNextColumn();
    ImGui::PushID("PropertyHex");
    ImGui::TextColored(titleAltText, hexVal);
    ImGui::SameLine();
    AddCopyText(hexVal);
    ImGui::PopID();

    sprintf(hexVal, "0x%08X", reinterpret_cast<unsigned int>(value));

    ImGui::TableNextColumn();
    ImGui::PushID("PropertyLocation");
    ImGui::TextColored(titleAltText, hexVal);
    ImGui::SameLine();
    AddCopyText(hexVal);
    ImGui::PopID();

    ImGui::PopID();
}


#endif //RRSPY2TESTAPP_VIEWHANDLER_H
