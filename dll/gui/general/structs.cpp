//
// Created by Sophie on 02/07/2021.
//

#include "../RRSpyGUI.h"
#include "../GameObjectPanels.h"
#include <vector>
#include "structs.h"

void
RenderStructPropertyTable(char* ptr, const std::vector<char*> &propertyNames, int numProperties, std::string label) {
    static ImGuiTableFlags tableFlags =
            ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit;

    char hexVal[128];

    if (ImGui::BeginTable("table1", 4, tableFlags)) {
        ImGui::TableSetupColumn("Address");
        ImGui::TableSetupColumn("Offset");
        ImGui::TableSetupColumn("Value");
        ImGui::TableSetupColumn("Name");
        ImGui::TableHeadersRow();

        for (int i = 0; i < numProperties; ++i) {
            ImGui::PushID(i);

            std::string index = "##" + std::to_string(i);
            ImGui::TableNextRow();

            char* valPtr = ptr + i * 4;

            ImGui::PushID("address");

            ImGui::TableSetColumnIndex(0);
            sprintf(hexVal, "0x%08x", (int) valPtr);

            ImGui::Text(hexVal);
            ImGui::SameLine();

            AddCopyText(hexVal);

            ImGui::PopID();

            ///////////////////////////////////////////////////////////

            ImGui::PushID("offset");

            ImGui::TableSetColumnIndex(1);
            sprintf(hexVal, "0x%04x", i * 4);

            ImGui::Text(hexVal);
            ImGui::SameLine();

            AddCopyText(hexVal);

            ImGui::PopID();

            ///////////////////////////////////////////////////////////

            ImGui::PushID(2);

            ImGui::TableSetColumnIndex(2);
            try {
                sprintf(hexVal, "0x%08x", *reinterpret_cast<int*>(valPtr));
            } catch (...) {
                sprintf(hexVal, "ERROR");
            }

            ImGui::Text(hexVal);
            ImGui::SameLine();

            AddCopyText(hexVal);

            ImGui::PopID();

            ///////////////////////////////////////////////////////////

            ImGui::PushID("desc");

            ImGui::TableSetColumnIndex(3);

            auto propName = i < propertyNames.size() ? propertyNames.at(i) : "";

            ImGui::Text(propName);

            // Column ID
            ImGui::PopID();

            // Row ID
            ImGui::PopID();
        }

        ImGui::EndTable();
    }
}