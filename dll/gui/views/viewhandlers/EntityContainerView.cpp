//
// Created by Sophie on 06/07/2021.
//

#include "EntityContainerView.h"
#include "../../entities/RRSpyGUIBaseEntityWrapper.h"
#include "../../../common.h"
#include "../../general/structs.h"
#include "../../../state.h"

void EntityContainerView::RenderListItem(EntityContainer* pEntity, int i) {
    const char* label = "EntityList";
    ImGuiID id = ImGui::GetID(label);

    if (RenderSelectableListItem(i, label, id) == ListItemClicked) {
        state->SetSelectedEntity(
                std::make_shared<RRSpyGUIBaseEntityWrapper>("EntityList", new EntityContainerView()), pEntity, id);
    }
}

void EntityContainerView::RenderProperties(EntityContainer* pEntity) {
    AddHeading("EntityList");

    if(BeginFullPropertyTable("entitycontainer")){
        RenderPropertyWithHex("OwnedObjectsStart", &pEntity->OwnedObjectsStart);
        RenderPropertyWithHex("OwnedObjectsEnd", &pEntity->OwnedObjectsEnd);
        RenderPropertyWithHex("OwnedObjectsEnd_2", &pEntity->OwnedObjectsEnd_2);
        RenderPropertyWithHex("Unk4", &pEntity->Unk4);
        RenderPropertyWithHex("Unk5", &pEntity->Unk5);
        RenderPropertyWithHex("Unk6", &pEntity->Unk6);
        RenderPropertyWithHex("Unk7", &pEntity->Unk7);

        EndPropertyTable();
    }
}

void EntityContainerView::RenderProperties(void* pEntity) {
    RenderProperties((EntityContainer*) pEntity);
}
