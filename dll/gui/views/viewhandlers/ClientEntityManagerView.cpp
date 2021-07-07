//
// Created by Sophie on 06/07/2021.
//

#include "ClientEntityManagerView.h"
#include "../../../common.h"
#include "../../general/structs.h"
#include "../../../gameobjects/map.h"


void ClientEntityManagerView::RenderListItem(ClientEntityManager* pEntity, int i) {
    const char* label = "ClientEntityManager";
    ImGuiID id = ImGui::GetID(label);

    if (RenderSelectableListItem(i, label, id) == ListItemClicked) {
        state->SetSelectedEntity(EntityMap[(int)pEntity->VFTable], pEntity, id);
    }
}

void ClientEntityManagerView::RenderProperties(ClientEntityManager* pEntity) {
    AddHeading("ClientEntityManager");

//    BeginPropertyTable();
//    EndPropertyTable();

    RenderStructPropertyTable((char*) pEntity, GetClientEntityManagerProperties());
}
