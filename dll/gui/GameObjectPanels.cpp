//
// Created by Sophie on 26/06/2021.
//

#include "../../lib/imgui/imgui_impl_dx9.h"
#include "../gameobjects/GameClientStateManager.h"
#include "../gameobjects/World.h"
#include "../datatypes/GCProperties.h"
#include "GameObjectPanels.h"
#include "general/structs.h"
#include "general/colours.h"

DFCNode* SelectedDFCNode;
ImGuiID SelectedDFCNodeID;

ImVec4 entityColour = defaultDFCNodeColour;
ImVec4 colourYellow = ImVec4(0.8f, 0.8f, 0.1f, 1);
ImVec4 entityActiveColour = ImVec4(0.929f, 0.682f, 0.286f, 1);
ImVec4 propertyColour = ImVec4(0.404f, 0.620f, 0.796f, 1);
ImVec4 gcPropertyColour = ImVec4(0.204f, 0.412f, 0.212f, 0.5f);
ImVec4 gcSuperclassColour = ImVec4(0.906f, 0.808f, 0.890f, 0.8f);
ImVec4 gcclassColour = ImVec4(0.643f, 0.318f, 0.588f, 0.5f);
ImVec4 tabColour = ImVec4(0.498f, 0.565f, 0.545f, 0.5f);
ImVec4 propertiesColour = ImVec4(0.498f, 0.565f, 0.545f, 0.5f);
ImVec4 tabSelectedColour = ImVec4(0.718f, 0.820f, 0.792f, 0.5f);
ImVec4 panelBg = ImVec4(0.239f, 0.239f, 0.239f, 1);
ImVec4 panelBgLt = ImVec4(0.322f, 0.322f, 0.322f, 1);
ImVec4 listAltBg = ImVec4(0.278f, 0.278f, 0.278f, 1);
ImVec4 listAltBgLt = ImVec4(0.368f, 0.368f, 0.368f, 1);
ImVec4 listSelected = ImVec4(0.941f, 0.576f, 0.392f, 1);
ImVec4 titleBg = ImVec4(0.706f, 0.173f, 0.384f, 1);
ImVec4 titleBgActive = ImVec4(0.773f, 0.188f, 0.420f, 1);
ImVec4 titleAltText = ImVec4(0.929f,0.851f,0.447f, 1);
ImVec4 textDisabled = ImVec4(0.439f, 0.439f, 0.439f, 1);;


//void RenderWorld() {
//    if (CurrentWorld == nullptr) {
//        return;
//    }
//
//    ImGui::PushID("CurrentWorld");
//    RenderItem((DFCNode*) CurrentWorld, 0);
//    ImGui::PopID();
//    if (ImGui::TreeNode("World")) {
//        if (CurrentWorld->MapName != nullptr) {
//            DRString mapName = *CurrentWorld->MapName;
//
//            RenderProperty("Map", mapName.ToString());
//        }
//
//        RenderStructPropertyTable((char*) CurrentWorld, GetWorldProperties(), 70);
//
//        std::string entityTreeLabel = "EntityManager ";
//
//        if (ImGui::TreeNode(entityTreeLabel.c_str())) {
//            ImGui::SameLine();
//            ImGui::TextColored(colourYellow, GetEntityManagerTypeName(CurrentWorld->EntityManager).c_str());
//            RenderEntityManager(CurrentWorld->EntityManager);
//            ImGui::TreePop();
//        } else {
//            ImGui::SameLine();
//            ImGui::TextColored(colourYellow, GetEntityManagerTypeName(CurrentWorld->EntityManager).c_str());
//        }
//
//        ImGui::TreePop();
//    }
//}

