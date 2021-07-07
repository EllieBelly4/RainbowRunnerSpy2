//
// Created by Sophie on 06/07/2021.
//

#include "EntityContainerView.h"
#include "../../entities/RRSpyGUIBaseEntityWrapper.h"
#include "../../../common.h"
#include "../../general/structs.h"

void EntityContainerView::RenderListItem(EntityContainer* pEntity, int i) {
    const char* label = "EntityContainer";
    ImGuiID id = ImGui::GetID(label);

    if (RenderSelectableListItem(i, label, id) == ListItemClicked) {
        state->SetSelectedEntity(std::make_shared<RRSpyGUIBaseEntityWrapper>("EntityContainer", new EntityContainerView()), pEntity, id);
    }
}

void EntityContainerView::RenderProperties(EntityContainer* pEntity) {
    AddHeading("EntityContainer");

    BeginPropertyTable("entitycontainer");
    RenderProperty("MSG In Queue", std::to_string(pEntity->UpdateMessagesInQueue));
    RenderProperty("MSG Processed", std::to_string(pEntity->ProcessedMessagesThisMove));
    EndPropertyTable();

    RenderStructPropertyTable((char*) pEntity, GetClientEntityProperties());
}

void EntityContainerView::RenderProperties(void* pEntity) {
    RenderProperties((EntityContainer*) pEntity);
}
