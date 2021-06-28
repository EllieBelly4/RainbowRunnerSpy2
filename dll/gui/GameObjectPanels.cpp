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
#include "../gameobjects/Entities/MeleeWeapon.h"
#include "../gameobjects/Entities/GCClass.h"

const ImVec4 &colourYellow = ImVec4(0.8f, 0.8f, 0.1f, 1);
const ImVec4 &entityColour = ImVec4(0.082f, 0.541f, 0.220f, 0.8);
const ImVec4 &propertyColour = ImVec4(0.424f, 0.702f, 1.000f, 0.8);
const ImVec4 &gcPropertyColour = ImVec4(0.204f, 0.412f, 0.212f, 0.5f);
const ImVec4 &gcSuperclassColour = ImVec4(0.247f,0.412f,0.298f, 0.5f);
const ImVec4 &gcclassColour = ImVec4(0.565f, 0.486f, 0.157f, 0.5f);
const ImVec4 &tabColour = ImVec4(0.498f, 0.565f, 0.545f, 0.5f);
const ImVec4 &tabSelectedColour = ImVec4(0.718f, 0.820f, 0.792f, 0.5f);

void RenderEntityList(unsigned int pStart, unsigned int pEnd);

void RenderEntityLinkedList(unsigned int child, unsigned int child1);

void RenderMeleeWeaponProperties(MeleeWeapon* pWeapon);

void RenderGCClassProperties(GCClass* pClass);

void RenderGCCLass(GCClass* pClass);

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

            RenderProperty("Map", mapName.ToString());
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

    if (ImGui::TreeNode("Raw Properties")) {
        RenderStructPropertyTable((char*) entityManager, GetEntityManagerProperties(), 70);
        ImGui::TreePop();
    }

    if (ImGui::TreeNode("Entities")) {
        RenderEntityManagerEntities(entityManager);
        ImGui::TreePop();
    }
}

void RenderEntityManagerEntities(EntityManager* manager) {
    if ((int) manager->VFTable == 0x008A7C18) {
        auto* entityContainer = (ClientEntity*) ((char*) manager + 0x0A38);
        RenderDFCNodes(entityContainer);
    } else {
        auto* entityContainer = (ServerEntity*) ((char*) manager + 0x0AC8);
        RenderEntities(entityContainer);
    }
}

void RenderEntityList(unsigned int pStart, unsigned int pEnd) {
    for (auto i = pStart; i < pEnd; i += 4) {
        auto entityPtr = *(DFCNode**) (i);
        ImGui::PushID(i);

        ImGui::PushStyleColor(ImGuiCol_Header, entityColour);
        RenderDFCNode(entityPtr);
        ImGui::PopStyleColor(1);

        ImGui::PopID();
    }
}

void RenderEntityLinkedList(unsigned int firstChild, unsigned int lastChild) {
    auto currentChild = reinterpret_cast<DFCNode*>(firstChild);

    int i = 0;

    while (currentChild != nullptr) {
        ImGui::PushID(i);
        RenderDFCNode(currentChild);
        currentChild = reinterpret_cast<DFCNode*>(currentChild->NextSibling);
        ImGui::PopID();
        i++;
    }
}

void RenderEntities(ServerEntity* entitiesPtr) {
    ImGui::PushID("serverEntities");

    if (ImGui::TreeNode("Raw Properties")) {
        RenderStructPropertyTable((char*) entitiesPtr, GetServerEntityProperties(), 60);
        ImGui::TreePop();
    }

    RenderEntityList(entitiesPtr->OwnedObjectsStart, entitiesPtr->OwnedObjectsEnd);

    ImGui::PopID();
}

void RenderDFCNodes(ClientEntity* entitiesPtr) {
    ImGui::PushID("clientEntities");

    if (ImGui::TreeNode("Raw Properties")) {
        RenderStructPropertyTable((char*) entitiesPtr, GetServerEntityProperties(), 60);
        ImGui::TreePop();
    }

    RenderEntityList(entitiesPtr->OwnedObjectsStart, entitiesPtr->OwnedObjectsEnd);

    ImGui::PopID();
}

void RenderDFCNode(DFCNode* pEntity) {
    auto vftable = (int) pEntity->VFTable;

    if (ImGui::TreeNodeEx(pEntity->GetTypeString().c_str(), ImGuiTreeNodeFlags_Framed)) {
        ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
        ImGui::PushStyleColor(ImGuiCol_Tab, tabColour);
        ImGui::PushStyleColor(ImGuiCol_TabActive, tabSelectedColour);

        if (ImGui::BeginTabBar("DFCNodeProperties", tab_bar_flags)) {
            if (ImGui::BeginTabItem("Properties")) {
                switch (vftable) {
                    case 0x0089B468:
                        RenderPlayerProperties((Player*) pEntity);
                        break;
                    case 0x0086DE00:
                        RenderAvatarProperties((Avatar*) pEntity);
                        break;
                    case 0x00893490:
                        RenderMeleeWeaponProperties((MeleeWeapon*) pEntity);
                        break;
                }

                RenderDFCNodeProperties(pEntity);

                if (pEntity->SuperClass != nullptr) {
                    ImGui::PushStyleColor(ImGuiCol_Header, gcSuperclassColour);
                    RenderDFCNode(pEntity->SuperClass);
                    ImGui::PopStyleColor(1);
                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Desc")) {
                if (pEntity->Desc != nullptr) {
                    RenderDFCNode(pEntity->Desc);
                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("Children")) {
                if (pEntity->FirstChild != 0) {
                    ImGui::PushStyleColor(ImGuiCol_Header, entityColour);
                    RenderEntityLinkedList(pEntity->FirstChild, pEntity->LastChild);
                    ImGui::PopStyleColor(1);
                }
                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("RawProperties")) {
                RenderStructPropertyTable((char*) pEntity, GetPlayerProperties(), 40);
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }

        ImGui::PopStyleColor(2);
        ImGui::TreePop();
    }
}

void RenderMeleeWeaponProperties(MeleeWeapon* pWeapon) {
}

void RenderGCCLass(GCClass* pClass) {
    ImGui::PushStyleColor(ImGuiCol_Header, gcclassColour);

    if (pClass->TypeName != nullptr) {
        RenderProperty("TypeName", pClass->TypeName->ToString());
    }

    if (ImGui::TreeNode("GCCLass Raw Properties")) {
        RenderStructPropertyTable((char*) pClass, GetEntityProperties(), 40, "GCCLassRawProperties");
        ImGui::TreePop();
    }

    ImGui::PopStyleColor(1);
}

void RenderPlayerProperties(Player* pPlayer) {
    if (pPlayer->Name != nullptr) {
        RenderProperty("Name", pPlayer->Name->ToString());
    }
}

void RenderAvatarProperties(Avatar* pAvatar) {
    std::string stateString;

    if ((pAvatar->SomeState2 & 0x40) > 0) {
        stateString += "Moving |";
    } else {
        stateString = "Standing |";
    }

    stateString = stateString.substr(0, stateString.length() - 2);

    RenderProperty("State", stateString);

    std::string posString;

    posString += "X: " + std::to_string(pAvatar->posX_maybe);
    posString += " Y: " + std::to_string(pAvatar->posY_maybe);
    posString += " Z: " + std::to_string(pAvatar->posZ_maybe);

    RenderProperty("Position", posString.c_str());
}

void RenderDFCNodeProperties(DFCNode* pEntity) {
    auto vftable = (int) pEntity->VFTable;

    char hexBuf[64];

    std::string hexStr;

    sprintf(hexBuf, "0x%08x", reinterpret_cast<int>(pEntity));
    hexStr = hexBuf;
    RenderProperty("Location", hexStr);

    sprintf(hexBuf, "0x%08x", vftable);
    hexStr = hexBuf;
    RenderProperty("VFTable", hexStr);

    if (pEntity->GCClass != nullptr) {
        RenderGCCLass(pEntity->GCClass);
    }
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
