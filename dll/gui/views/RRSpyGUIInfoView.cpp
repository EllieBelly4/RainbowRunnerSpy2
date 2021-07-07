//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyGUIInfoView.h"

#include "../../common.h"
#include "viewhandlers/GameClientStateManagerView.h"
#include "viewhandlers/ClientEntityManagerView.h"
#include "viewhandlers/EntityContainerView.h"

#define EntityManagerTypeText(string) ImGui::SameLine();\
ImGui::TextColored(titleAltText, string);

void RRSpyGUIInfoView::Render() {
    static bool openMain = true;
    int i = 0;

    ImGui::Begin("RRSpy2 Info", &openMain);

    try {
        RenderGeneralInfo();
        RenderGlobalObjects();
        RenderEntities();

    } catch (...) {
        ImGui::TextColored(ImVec4{1.000f, 0.443f, 0.384f, 1}, "Error");
    }

    ImGui::End();
}

RRSpyGUIInfoView::RRSpyGUIInfoView(std::shared_ptr<RRSpyState> state, std::shared_ptr<log::Log> logger) :
        _state(state), logger(logger) {
    entityList = std::make_shared<RRSpyGUIList>(state);
}

void RRSpyGUIInfoView::RenderGeneralInfo() {
    std::stringstream gameClientStateManagerText;

    char* gameClientStateManagerPtr = (char*) 0x9360C8;
    auto gameClientStateManager = (GameClientStateManager*) (gameClientStateManagerPtr);

    ImGui::Text("State: ");
    ImGui::SameLine();
    ImGui::TextColored(titleAltText, GetStateString(gameClientStateManager));

    ImGui::Text("Current Map");
    ImGui::SameLine();

    if (!IsBadReadPtr(_state->CurrentWorld) && !IsBadReadPtr(_state->CurrentWorld->MapName)) {
        ImGui::TextColored(titleAltText, _state->CurrentWorld->MapName->ToString().c_str());
    } else {
        ImGui::TextColored(textDisabled, "unknown");
    }

    int i = 0;

    GameClientStateManagerView::RenderListItem(gameClientStateManager, i++);
}

void RRSpyGUIInfoView::RenderEntities() {
    int i = 0;
    if (!IsBadReadPtr(_state->CurrentWorld) && !IsBadReadPtr(_state->CurrentWorld->EntityManager)) {
        EntityContainer* container;
        EntityManager* manager = _state->CurrentWorld->EntityManager;

        if ((int) _state->CurrentWorld->EntityManager->VFTable == 0x008A7C18) {
            auto pEntityManager = reinterpret_cast<ClientEntityManager*>(manager);
            ClientEntityManagerView::RenderListItem(
                    pEntityManager, i++);
            container = (EntityContainer*) ((char*) manager + 0x0A38);
        } else {
            container = (EntityContainer*) ((char*) manager + 0x0AC8);
        }

        EntityContainerView::RenderListItem(container, i++);
    }

    if (ImGui::TreeNodeEx("Managed Entities", ImGuiTreeNodeFlags_Framed)) {
        if (!IsBadReadPtr(_state->CurrentWorld) && !IsBadReadPtr(_state->CurrentWorld->EntityManager)) {
            auto manager = _state->CurrentWorld->EntityManager;
            EntityContainer* entities;

            if ((int) manager->VFTable == 0x008A7C18) {
                entities = (EntityContainer*) ((char*) manager + 0x0A38);
                ImGui::PushID("client");

                EntityManagerTypeText("ClientEntityManager");
            } else {
                entities = (EntityContainer*) ((char*) manager + 0x0AC8);
                ImGui::PushID("server");

                EntityManagerTypeText("ServerEntityManager");
            }

            entityList->Render(entities);
            ImGui::PopID();
        }
        ImGui::TreePop();
    } else {
        if (!IsBadReadPtr(_state->CurrentWorld) && !IsBadReadPtr(_state->CurrentWorld->EntityManager)) {
            auto manager = _state->CurrentWorld->EntityManager;

            if ((int) manager->VFTable == 0x008A7C18) {
                EntityManagerTypeText("ClientEntityManager");
            } else {
                EntityManagerTypeText("ServerEntityManager");
            }
        } else {
            EntityManagerTypeText("None");
        }
    }
}

void RRSpyGUIInfoView::RenderGlobalObjects() {
    int i = 0;

    if (ImGui::TreeNodeEx("Global Objects", ImGuiTreeNodeFlags_Framed)) {
        if (!IsBadReadPtr(_state->CurrentWorld)) {
            entityList->RenderItem((DFCNode*) _state->CurrentWorld, i++);

//            if (_state->CurrentWorld->EntityManager != nullptr) {
//                entityList->RenderItem((DFCNode*) _state->CurrentWorld->EntityManager, i++);
//            }
        }

        ImGui::TreePop();
    }
}
