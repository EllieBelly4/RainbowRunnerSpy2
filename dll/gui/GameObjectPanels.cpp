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
#include "../gameobjects/EntityManager.h"
#include "../gameobjects/ClientEntity.h"
#include "../gameobjects/Entities/Entity.h"
#include "../gameobjects/Entities/Avatar.h"

const ImVec4 &colourYellow = ImVec4(0.8f, 0.8f, 0.1f, 1);
const ImVec4 &propertyColour = ImVec4(0.424f, 0.702f, 1.000f, 1);

void RenderEntities(ClientEntity* string);

void AddCopyText(const std::string &basicString);

void RenderProperty(const std::string &propertyName, const std::string &hexStr);

void RenderEntity(Entity* pEntity);

void RenderEntityProperties(Entity* pEntity);

void RenderAvatarProperties(Avatar* pAvatar);

void RenderGameClientStateManager() {
    std::stringstream gameClientStateManagerText;

    char* gameClientStateManagerPtr = (char*) 0x9360C8;
    auto gameClientStateManager = (GameClientStateManager*) (gameClientStateManagerPtr);

    ImGui::Text("State: ");
    ImGui::SameLine();
    ImGui::TextColored(colourYellow, GetStateString(gameClientStateManager));

    if (ImGui::TreeNode("GameClientStateManager")) {
        RenderStructPropertyTable(gameClientStateManagerPtr, GetGameClientStateManagerProperties());

        ImGui::TreePop();
    }
}

void RenderWorld() {
    if (CurrentWorld == nullptr) {
        return;
    }

    if (ImGui::TreeNode("World")) {
        if (CurrentWorld->MapName != nullptr) {
            DRString mapName = *CurrentWorld->MapName;
            char* addr = (char*) CurrentWorld->MapName + 4;

            std::string strName;

            for (int i = 0; i < mapName.Length; ++i) {
                strName += *(addr + i);
            }

            RenderProperty("Map", strName);
        }

        RenderStructPropertyTable((char*) CurrentWorld, GetWorldProperties(), 70);

        std::string entityTreeLabel = "EntityManager ";

        if (ImGui::TreeNode(entityTreeLabel.c_str())) {
            ImGui::SameLine();
            ImGui::TextColored(colourYellow, GetEntityManagerTypeName(CurrentWorld->EntityManager).c_str());
            RenderEntityManager(CurrentWorld->EntityManager);
            ImGui::TreePop();
        } else {
            ImGui::SameLine();
            ImGui::TextColored(colourYellow, GetEntityManagerTypeName(CurrentWorld->EntityManager).c_str());
        }

        ImGui::TreePop();
    }
}

void RenderEntityManager(EntityManager* entityManager) {
    if (entityManager == nullptr) {
        ImGui::Text("null");
        return;
    }

    if ((int) entityManager->VFTable == 0x008A7C18) {
        RenderStructPropertyTable((char*) entityManager, GetClientEntityManagerProperties(), 70);

        if (ImGui::TreeNode("Entities")) {
            RenderEntities((ClientEntity*) ((char*) entityManager + 0x0A38));
            ImGui::TreePop();
        }
    } else {
        RenderStructPropertyTable((char*) entityManager, GetEntityManagerProperties(), 70);
    }
}

void RenderEntities(ClientEntity* entitiesPtr) {
    RenderStructPropertyTable((char*) entitiesPtr, GetClientEntityProperties(), 60);

    auto count = ((int) entitiesPtr->OwnedObjectsEnd - (int) entitiesPtr->OwnedObjectsStart) / 4;

    for (int i = 0; i < count; ++i) {
        auto entityPtr = *(Entity**) (entitiesPtr->OwnedObjectsStart + i * 4);
        ImGui::PushID(i);
        RenderEntity(entityPtr);
        ImGui::PopID();
    }
}

void RenderEntity(Entity* pEntity) {
    auto vftable = (int) pEntity->VFTable;

    if (vftable == 0x0089B468) {
        if (ImGui::CollapsingHeader("Player")) {
            RenderEntityProperties(pEntity);
            RenderStructPropertyTable((char*) pEntity, GetEntityProperties(), 50);
        }
    } else if (vftable == 0x0086DE00) {
        if (ImGui::CollapsingHeader("Avatar")) {
            RenderAvatarProperties((Avatar*) pEntity);
            RenderEntityProperties(pEntity);
            RenderStructPropertyTable((char*) pEntity, GetAvatarProperties(), 50);
        }
    } else {
        if (ImGui::CollapsingHeader("UnknownEntity")) {
            RenderEntityProperties(pEntity);
            RenderStructPropertyTable((char*) pEntity, GetEntityProperties(), 50);
        }
    }
}

void RenderAvatarProperties(Avatar* pAvatar) {
    std::string posString;

    posString += "X: " + std::to_string(pAvatar->posX_maybe);
    posString += " Y: " + std::to_string(pAvatar->posY_maybe);
    posString += " Z: " + std::to_string(pAvatar->posZ_maybe);

    RenderProperty("Position", posString.c_str());
}

void RenderEntityProperties(Entity* pEntity) {
    auto vftable = (int) pEntity->VFTable;

    char hexBuf[64];

    sprintf(hexBuf, "0x%08x", vftable);
    std::string hexStr = hexBuf;
    RenderProperty("VFTable", hexStr);
}

void RenderProperty(const std::string &propertyName, const std::string &hexStr) {
    ImGui::TextColored(propertyColour, propertyName.c_str());
    ImGui::SameLine();
    ImGui::Text(hexStr.c_str());
    ImGui::SameLine();
    ImGui::PushID(propertyName.c_str());
    AddCopyText(hexStr);
    ImGui::PopID();
}

void AddCopyText(const std::string &basicString) {
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.008f, 0.094f, 0.114f, 1});

    if (ImGui::Button("Copy")) {
        PasteToClipboard(basicString);
    }

    ImGui::PopStyleColor(1);
}

void RenderStructPropertyTable(char* ptr, const std::vector<char*> &propertyNames, int numProperties) {
    if (ImGui::TreeNode("Raw Properties")) {
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

        ImGui::TreePop();
    }
}
