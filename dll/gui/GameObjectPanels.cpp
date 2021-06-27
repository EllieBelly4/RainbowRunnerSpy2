//
// Created by Sophie on 26/06/2021.
//

#include <iomanip>
#include <vector>
#include "../../lib/imgui/imgui_impl_dx9.h"
#include "../gameobjects/GameClientStateManager.h"
#include "../gameobjects/World.h"
#include "GameObjectPanels.h"
#include "RRSpyGUI.h"

void RenderGameClientStateManager() {
    std::stringstream gameClientStateManagerText;

    char* gameClientStateManagerPtr = (char*) 0x9360C8;
    auto gameClientStateManager = (GameClientStateManager*) (gameClientStateManagerPtr);

    ImGui::Text("State: ");
    ImGui::SameLine();
    ImGui::TextColored(ImVec4(0.8f, 0.8f, 0.1f, 1), GetStateString(gameClientStateManager));

    if (ImGui::TreeNode("GameClientStateManager")) {
        RenderStructPropertyTable(gameClientStateManagerPtr, GetGameClientStateManagerProperties());

        ImGui::TreePop();
    }
}

void RenderWorld() {
    if (World == nullptr) {
        return;
    }

    if (ImGui::TreeNode("World")) {
        RenderStructPropertyTable((char*) World, GetWorldProperties());

        ImGui::TreePop();
    }
}

void RenderStructPropertyTable(char* ptr, const std::vector<char*> &propertyNames) {
    if (ImGui::TreeNode("Raw Properties")) {
        static ImGuiTableFlags tableFlags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;

        char hexVal[128];

        if (ImGui::BeginTable("table1", 4, tableFlags)) {
            ImGui::TableSetupColumn("Address");
            ImGui::TableSetupColumn("Offset");
            ImGui::TableSetupColumn("Value");
            ImGui::TableSetupColumn("Name");
            ImGui::TableHeadersRow();

            for (int i = 0; i < 40; ++i) {
                ImGui::TableNextRow();

                char* valPtr = ptr + i * 4;

                ImGui::TableSetColumnIndex(0);
                sprintf(hexVal, "0x%08x", (int) valPtr);

                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.008f,0.094f,0.114f, 1});

                if (ImGui::Button(hexVal)) {
                    PasteToClipboard(hexVal);
                }

                ImGui::TableSetColumnIndex(1);
                sprintf(hexVal, "0x%04x", i * 4);

                if (ImGui::Button(hexVal)) {
                    PasteToClipboard(hexVal);
                }

                ImGui::TableSetColumnIndex(2);
                sprintf(hexVal, "0x%08x", *reinterpret_cast<int*>(valPtr));

                if (ImGui::Button(hexVal)) {
                    PasteToClipboard(hexVal);
                }

                ImGui::TableSetColumnIndex(3);

                auto propName = i < propertyNames.size() ? propertyNames.at(i) : "";

                ImGui::Text(propName);

                ImGui::PopStyleColor(1);
            }

            ImGui::EndTable();
        }

        ImGui::TreePop();
    }
}
