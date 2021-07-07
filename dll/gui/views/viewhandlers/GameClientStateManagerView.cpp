//
// Created by Sophie on 05/07/2021.
//

#include "GameClientStateManagerView.h"
#include "../../general/structs.h"
#include "../../entities/RRSpyGUIBaseEntityWrapper.h"
#include "../../../common.h"
#include "../../../gameobjects/map.h"

void GameClientStateManagerView::RenderListItem(GameClientStateManager* pEntity, int i) {
    const char* label = "GameClientStateManager";
    ImGuiID id = ImGui::GetID(label);

    if (RenderSelectableListItem(i, label, id) == ListItemClicked) {
        state->SetSelectedEntity(
                std::make_shared<RRSpyGUIBaseEntityWrapper>("GameClientStateManager", new GameClientStateManagerView()),
                pEntity, id);
    }
}

void GameClientStateManagerView::RenderProperties(GameClientStateManager* pEntity) {
    AddHeading("GameClientStateManager");

    BeginPropertyTable("gameclientstatemanager");

    RenderProperty("Frame", std::to_string(pEntity->SomeTimer));

    EndPropertyTable();

    RenderStructPropertyTable((char*) pEntity, GetGameClientStateManagerProperties());
}

void GameClientStateManagerView::RenderProperties(void* pVoid) {
    GameClientStateManagerView::RenderProperties((GameClientStateManager*)pVoid);
}
