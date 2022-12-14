//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyGUIInfoView.h"

#include "../../common.h"

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

    }
    catch (...) {
        ImGui::TextColored(ImVec4{1.000f, 0.443f, 0.384f, 1}, "Error");
    }

    ImGui::End();
}

RRSpyGUIInfoView::RRSpyGUIInfoView(std::shared_ptr<RRSpyState> state, std::shared_ptr<RRLog::Log> logger) :
        _state(state), logger(logger) {
    entityList = std::make_shared<RRSpyGUIList>(state);
}

void RRSpyGUIInfoView::RenderGeneralInfo() {
    std::stringstream gameClientStateManagerText;

    auto gameClientStateManager = _state->GameClientStateManager;

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

    EntityContainer *entityContainer = nullptr;
    EntityContainer *componentList = nullptr;
    const char *managerTypeText;

    if (!IsBadReadPtr(_state->CurrentWorld)) {
        if (!IsBadReadPtr(_state->CurrentWorld->EntityManager)) {
            managerTypeText = AddEntityManagerListItem(
                    &entityContainer,
                    &componentList,
                    i
            );
        }

//        if (!IsBadReadPtr(entityContainer)) {
//            EntityContainerView::RenderListItem(entityContainer, i++);
//        }
//
//        if (!IsBadReadPtr(componentList)) {
//            EntityContainerView::RenderListItem(componentList, i++);
//        }
    }

    if (ImGui::TreeNodeEx("Entities", ImGuiTreeNodeFlags_Framed)) {
        if (!IsBadReadPtr(_state->CurrentWorld) && !IsBadReadPtr(_state->CurrentWorld->EntityManager)) {
            auto manager = _state->CurrentWorld->EntityManager;

            if ((int) manager->VFTable == 0x008A7C18) {
                ImGui::PushID("client");
            } else {
                ImGui::PushID("server");
            }

            EntityManagerTypeText(managerTypeText);

            if (!IsBadReadPtr(reinterpret_cast<void *>(entityContainer))) {
                entityList->Render(entityContainer);
            }

            ImGui::PopID();
        }
        ImGui::TreePop();
    } else {
        if (!IsBadReadPtr(_state->CurrentWorld) && !IsBadReadPtr(_state->CurrentWorld->EntityManager)) {
            EntityManagerTypeText(managerTypeText);
        } else {
            EntityManagerTypeText("None");
        }
    }

    if (ImGui::TreeNodeEx("Components", ImGuiTreeNodeFlags_Framed)) {
        if (!IsBadReadPtr(_state->CurrentWorld) && !IsBadReadPtr(_state->CurrentWorld->EntityManager)) {
            auto manager = _state->CurrentWorld->EntityManager;

            if ((int) manager->VFTable == 0x008A7C18) {
                ImGui::PushID("clientComponents");
            } else {
                ImGui::PushID("clientComponents");
            }

            EntityManagerTypeText(managerTypeText);

            if (!IsBadReadPtr(reinterpret_cast<void *>(componentList))) {
                entityList->Render(componentList);
            }

            ImGui::PopID();
        }
        ImGui::TreePop();
    } else {
        if (!IsBadReadPtr(_state->CurrentWorld) && !IsBadReadPtr(_state->CurrentWorld->EntityManager)) {
            EntityManagerTypeText(managerTypeText);
        } else {
            EntityManagerTypeText("None");
        }
    }
}

void RRSpyGUIInfoView::RenderGlobalObjects() {
    int i = 0;

    if (ImGui::TreeNodeEx("Global Objects", ImGuiTreeNodeFlags_Framed)) {
        if (!IsBadReadPtr(_state->CurrentWorld)) {
            entityList->RenderItem((DFCNode *) _state->CurrentWorld, i++);

//            if (_state->CurrentWorld->EntityManager != nullptr) {
//                entityList->RenderItem((DFCNode*) _state->CurrentWorld->EntityManager, i++);
//            }

            if (!IsBadReadPtr(_state->CurrentWorld->path_manager)) {
                RenderListItem("PathManager", _state->CurrentWorld->path_manager, i);
            }
        }

        ImGui::TreePop();
    }
}

const char *RRSpyGUIInfoView::AddEntityManagerListItem(
        EntityContainer **pEntityContainer,
        EntityContainer **pComponentList,
        int i
) {
    EntityManager *manager = _state->CurrentWorld->EntityManager;

    if ((int) _state->CurrentWorld->EntityManager->VFTable == 0x008A7C18) {
        auto pEntityManager = reinterpret_cast<ClientEntityManager *>(manager);
        ClientEntityManagerView::RenderListItem(pEntityManager, i);
        *pEntityContainer = &pEntityManager->EntityList;
        *pComponentList = &pEntityManager->ComponentList;
        return "ClientEntityManager";
    }

    *pEntityContainer = (EntityContainer *) ((char *) manager + 0x0AC8 + 0x04);
    *pComponentList = (EntityContainer *) ((char *) manager + 0x0AC8 + sizeof(EntityContainer));
    return "ServerEntityManager";
}
