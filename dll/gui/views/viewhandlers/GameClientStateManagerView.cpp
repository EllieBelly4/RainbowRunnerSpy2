//
// Created by Sophie on 05/07/2021.
//

#include "GameClientStateManagerView.h"
#include "../../general/structs.h"
#include "../../entities/RRSpyGUIBaseEntityWrapper.h"
#include "../../../common.h"
#include "../../../gameobjects/map.h"
#include "../../general/colours.h"
#include "../../general/gui_functions.h"
#include "ViewHandler.h"
#include "../../../state.h"

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

    if(BeginFullPropertyTable("gameclientstatemanager")){

        RenderPropertyWithHex("Frame", &pEntity->CurrentFrame);
        RenderPropertyWithHex("field_4", (unsigned int*) &pEntity->field_4);
        RenderPropertyWithHex("field_8", &pEntity->field_8);
        RenderPropertyWithHex("State0", &pEntity->State0);
        RenderPropertyWithHex("State1", &pEntity->State1);
        RenderPropertyWithHex("State2", &pEntity->State2);
        RenderPropertyWithHex("State3", &pEntity->State3);
        RenderPropertyWithHex("field_18", &pEntity->field_18);
        RenderPropertyWithHex("IEventHandlerVFTable", &pEntity->IEventHandlerVFTable);
        RenderPropertyWithHex("SomeMap", &pEntity->SomeMap);
        RenderPropertyWithHex("field_2C", &pEntity->field_2C);
        RenderPropertyWithHex("field_30", &pEntity->field_30);
        RenderPropertyWithHex("field_34", &pEntity->field_34);
        RenderPropertyWithHex("UpdatingText", (unsigned int*) &pEntity->UpdatingText);
        RenderPropertyWithHex("CheckingForUpdatesText", (unsigned int*) &pEntity->CheckingForUpdatesText);
        RenderPropertyWithHex("field_40", (unsigned int*) &pEntity->field_40);
        RenderPropertyWithHex("field_44", (unsigned int*) &pEntity->field_44);
        RenderPropertyWithHex("field_48", (unsigned int*) &pEntity->field_48);
        RenderPropertyWithHex("field_4C", (unsigned int*) &pEntity->field_4C);
        RenderPropertyWithHex("field_50", (unsigned int*) &pEntity->field_50);
        RenderPropertyWithHex("WorldUI", (unsigned int*) &pEntity->WorldUI);
        RenderPropertyWithHex("WorldUIBanner", (unsigned int*) &pEntity->WorldUIBanner);
        RenderPropertyWithHex("LoadingScreen", (unsigned int*) &pEntity->LoadingScreen);
        RenderPropertyWithHex("GatewayClient", (unsigned int*) &pEntity->GatewayClient);
        RenderPropertyWithHex("ZoneClient", (unsigned int*) &pEntity->ZoneClient);
        RenderPropertyWithHex("SomeMap2", (unsigned int*) &pEntity->SomeMap2);
        RenderPropertyWithHex("field_74", &pEntity->field_74);
        RenderPropertyWithHex("field_7C", &pEntity->field_7C);
        RenderPropertyWithHex("field_7D", &pEntity->field_7D);
        RenderPropertyWithHex("field_7E", &pEntity->field_7E);
        RenderPropertyWithHex("field_7F", &pEntity->field_7F);
        RenderPropertyWithHex("field_80", &pEntity->field_80);

        EndPropertyTable();
    }
}

void GameClientStateManagerView::RenderProperties(void* pVoid) {
    GameClientStateManagerView::RenderProperties((GameClientStateManager*) pVoid);
}
