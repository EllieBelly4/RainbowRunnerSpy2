//
// Created by Sophie on 05/07/2021.
//

#include "GameClientStateManagerView.h"
#include "../../general/structs.h"
#include "../../entities/RRSpyGUIEntityWrapper.h"
#include "../../../common.h"

void GameClientStateManagerView::RenderListItem(GameClientStateManager* pEntity, int i) {
    const char* label = "GameClientStateManager";
    ImGuiID id = ImGui::GetID(label);

    if(RenderSelectableListItem(i, label, id) == ListItemClicked){
        state->SetSelectedEntity(std::make_shared<RRSpyGameClientStateManager>(pEntity, id));
    }
}

void GameClientStateManagerView::RenderProperties(GameClientStateManager* pEntity) {
    RenderStructPropertyTable((char*)pEntity, GetGameClientStateManagerProperties());
}
