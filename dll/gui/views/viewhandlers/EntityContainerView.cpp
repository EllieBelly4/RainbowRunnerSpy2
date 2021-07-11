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

    BeginFullPropertyTable("entitycontainer");

//    RenderPropertyWithHex("Unk0", &pEntity->Unk0);
    RenderPropertyWithHex("OwnedObjectsStart", &pEntity->OwnedObjectsStart);
    RenderPropertyWithHex("OwnedObjectsEnd", &pEntity->OwnedObjectsEnd);
    RenderPropertyWithHex("OwnedObjectsEnd_2", &pEntity->OwnedObjectsEnd_2);
    RenderPropertyWithHex("Unk4", &pEntity->Unk4);
    RenderPropertyWithHex("Unk5", &pEntity->Unk5);
    RenderPropertyWithHex("Unk6", &pEntity->Unk6);
    RenderPropertyWithHex("Unk7", &pEntity->Unk7);
//    RenderPropertyWithHex("Unk8", &pEntity->Unk8);
//    RenderPropertyWithHex("Unk9", &pEntity->Unk9);
//    RenderPropertyWithHex("Unk10", &pEntity->Unk10);
//    RenderPropertyWithHex("Unk11", &pEntity->Unk11);
//    RenderPropertyWithHex("Unk12", &pEntity->Unk12);
//    RenderPropertyWithHex("SomeMap", &pEntity->Unk13);
//    RenderPropertyWithHex("Unk14", &pEntity->Unk14);
//    RenderPropertyWithHex("Unk15", &pEntity->Unk15);
//    RenderPropertyWithHex("Unk16", &pEntity->Unk16);
//    RenderPropertyWithHex("Unk17", &pEntity->Unk17);
//    RenderPropertyWithHex("Unk18", &pEntity->Unk18);
//    RenderPropertyWithHex("Unk19", &pEntity->Unk19);
//    RenderPropertyWithHex("SomeTimer", &pEntity->SomeTimer);
//    RenderPropertyWithHex("Unk21", &pEntity->Unk21);
//    RenderPropertyWithHex("FrameThisSecond", &pEntity->FrameThisSecond);
//    RenderPropertyWithHex("SomeCounter", &pEntity->SomeCounter);
//    RenderPropertyWithHex("Unk24", &pEntity->Unk24);
//    RenderPropertyWithHex("Unk25", &pEntity->Unk25);
//    RenderPropertyWithHex("Unk26", &pEntity->Unk26);
//    RenderPropertyWithHex("Unk27", &pEntity->Unk27);
//    RenderPropertyWithHex("Unk28", &pEntity->Unk28);
//    RenderPropertyWithHex("Unk29", &pEntity->Unk29);
//    RenderPropertyWithHex("Unk30", &pEntity->Unk30);
//    RenderPropertyWithHex("ProcessedMessagesThisMove", &pEntity->ProcessedMessagesThisMove);
//    RenderPropertyWithHex("UpdateMessagesInQueue", &pEntity->UpdateMessagesInQueue);
//    RenderPropertyWithHex("Unk33", &pEntity->Unk33);
//    RenderPropertyWithHex("Unk34", &pEntity->Unk34);
//    RenderPropertyWithHex("Unk35", &pEntity->Unk35);
//    RenderPropertyWithHex("Unk36", &pEntity->Unk36);
//    RenderPropertyWithHex("Unk37", &pEntity->Unk37);
//    RenderPropertyWithHex("Unk38", &pEntity->Unk38);
//    RenderPropertyWithHex("Unk39", &pEntity->Unk39);
//    RenderPropertyWithHex("Unk40", &pEntity->Unk40);
//    RenderPropertyWithHex("Unk41", &pEntity->Unk41);
//    RenderPropertyWithHex("Unk42", &pEntity->Unk42);
//    RenderPropertyWithHex("Unk43", &pEntity->Unk43);
//    RenderPropertyWithHex("Unk44", &pEntity->Unk44);
//    RenderPropertyWithHex("Unk45", &pEntity->Unk45);
//    RenderPropertyWithHex("Unk46", &pEntity->Unk46);
//    RenderPropertyWithHex("Unk47", &pEntity->Unk47);
//    RenderPropertyWithHex("Unk48", &pEntity->Unk48);
//    RenderPropertyWithHex("Unk49", &pEntity->Unk49);
//    RenderPropertyWithHex("Unk50", &pEntity->Unk50);
//    RenderPropertyWithHex("Unk51", &pEntity->Unk51);
//    RenderPropertyWithHex("Unk52", &pEntity->Unk52);
//    RenderPropertyWithHex("Unk53", &pEntity->Unk53);
//    RenderPropertyWithHex("Unk54", &pEntity->Unk54);
//    RenderPropertyWithHex("Unk55", &pEntity->Unk55);
//    RenderPropertyWithHex("Unk56", &pEntity->Unk56);
//    RenderPropertyWithHex("Unk57", &pEntity->Unk57);
//    RenderPropertyWithHex("Unk58", &pEntity->Unk58);

    EndPropertyTable();
}

void EntityContainerView::RenderProperties(void* pEntity) {
    RenderProperties((EntityContainer*) pEntity);
}
