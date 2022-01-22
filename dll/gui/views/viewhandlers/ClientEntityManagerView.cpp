//
// Created by Sophie on 06/07/2021.
//

#include "ClientEntityManagerView.h"
#include "../../../common.h"
#include "../../general/structs.h"
#include "../../../gameobjects/map.h"
#include "../../../state.h"


void ClientEntityManagerView::RenderListItem(ClientEntityManager* pEntity, int i) {
    const char* label = "ClientEntityManager";
    ImGuiID id = ImGui::GetID(label);

    if (RenderSelectableListItem(i, label, id) == ListItemClicked) {
        state->SetSelectedEntity(GetEntityWrapper(pEntity->VFTable), pEntity, id);
    }
}

void ClientEntityManagerView::RenderProperties(ClientEntityManager* pEntity) {
    AddHeading("ClientEntityManager");

    if(BeginFullPropertyTable("ClientEntityManager")){
        RenderPropertyWithHex("Unk0", &pEntity->Unk0);
        RenderPropertyWithHex("Unk1", &pEntity->Unk1);
        RenderPropertyWithHex("Unk2", &pEntity->Unk2);
        RenderPropertyWithHex("World", (unsigned int*) &pEntity->World);
        RenderPropertyWithHex("Unk4", &pEntity->Unk4);
        RenderPropertyWithHex("Unk5", &pEntity->Unk5);
        RenderPropertyWithHex("Unk6", &pEntity->Unk6);
        RenderPropertyWithHex("SoundEnvironment", &pEntity->SoundEnvironment);
        RenderPropertyWithHex("Unk8", &pEntity->Unk8);
        RenderPropertyWithHex("Unk9", &pEntity->Unk9);
        RenderPropertyWithHex("EventSystemVFTable", (unsigned int*) &pEntity->EventSystemVFTable);
        RenderPropertyWithHex("Unk11", &pEntity->Unk11);
        RenderPropertyWithHex("Unk12", &pEntity->Unk12);
        RenderPropertyWithHex("SomeMap", &pEntity->SomeMap);
        RenderPropertyWithHex("Unk14", &pEntity->Unk14);
        RenderPropertyWithHex("LinkBufferVFTable", (unsigned int*) &pEntity->LinkBufferVFTable);
        RenderPropertyWithHex("Unk16", &pEntity->Unk16);
        RenderPropertyWithHex("Unk17", &pEntity->Unk17);
        RenderPropertyWithHex("Unk18", &pEntity->Unk18);
        RenderPropertyWithHex("Unk19", &pEntity->Unk19);
        RenderPropertyWithHex("unk_20", &pEntity->unk_20);
        RenderPropertyWithHex("unk_21", &pEntity->unk_21);
        RenderPropertyWithHex("unk_22", &pEntity->unk_22);
        RenderPropertyWithHex("unk_23", &pEntity->unk_23);
        RenderPropertyWithHex("unk_24", &pEntity->unk_24);
        RenderPropertyWithHex("unk_25", &pEntity->unk_25);
        RenderPropertyWithHex("ManagerChannel", &pEntity->ManagerChannel);
        RenderPropertyWithHex("unk_27", &pEntity->unk_27);
        RenderPropertyWithHex("unk_28", &pEntity->unk_28);
        RenderPropertyWithHex("EntityList", (unsigned int*) &pEntity->EntityList);
        RenderPropertyWithHex("BufferStart", (unsigned int*)&pEntity->Unk);
    //    RenderPropertyWithHex("unk_31", &pEntity->unk_31);
        RenderPropertyWithHex("ComponentList", (unsigned int*) &pEntity->ComponentList); // ComponentList
    //    RenderPropertyWithHex("unk_33", &pEntity->unk_33);
    //    RenderPropertyWithHex("unk_34", &pEntity->unk_34);
    //    RenderPropertyWithHex("unk_35", &pEntity->unk_35);
    //    RenderPropertyWithHex("unk_36", &pEntity->unk_36);
    //    RenderPropertyWithHex("unk_37", &pEntity->unk_37);
    //    RenderPropertyWithHex("unk_38", &pEntity->unk_38);
    //    RenderPropertyWithHex("unk_39", &pEntity->unk_39);
    //    RenderPropertyWithHex("unk_40", &pEntity->unk_40);
    //    RenderPropertyWithHex("unk_41", &pEntity->unk_41);
        RenderPropertyWithHex("unk_42", &pEntity->unk_42);
        RenderPropertyWithHex("SomeTimer", &pEntity->SomeTimer);
        RenderPropertyWithHex("Frame_or_RNG?", &pEntity->FrameThisSecond);
        RenderPropertyWithHex("SomeCounter", &pEntity->SomeCounter);
        RenderPropertyWithHex("unk_43", &pEntity->unk_43);
        RenderPropertyWithHex("unk_44", &pEntity->unk_44);
        RenderPropertyWithHex("unk_45", &pEntity->unk_45);
        RenderPropertyWithHex("unk_46", &pEntity->unk_46);
        RenderPropertyWithHex("unk_47", &pEntity->unk_47);
        RenderPropertyWithHex("unk_48", &pEntity->unk_48);
        RenderPropertyWithHex("unk_49", &pEntity->unk_49);
        RenderPropertyWithHex("unk_increases_slowly", &pEntity->unk_increases_slowly);
        RenderPropertyWithHex("ProcessedMessagesThisMove", &pEntity->ProcessedMessagesThisMove);
        RenderPropertyWithHex("UpdateMessagesInQueue", &pEntity->UpdateMessagesInQueue);
        RenderPropertyWithHex("unk_51", &pEntity->unk_51);
        RenderPropertyWithHex("unk_52", &pEntity->unk_52);
        RenderPropertyWithHex("unk_53", &pEntity->unk_53);
        RenderPropertyWithHex("unk_54", &pEntity->unk_54);
        RenderPropertyWithHex("unk_55", &pEntity->unk_55);
        RenderPropertyWithHex("unk_56", &pEntity->unk_56);
        RenderPropertyWithHex("unk_57", &pEntity->unk_57);
        RenderPropertyWithHex("unk_58", &pEntity->unk_58);
        RenderPropertyWithHex("unk_59", &pEntity->unk_59);
        RenderPropertyWithHex("unk_60", &pEntity->unk_60);
        RenderPropertyWithHex("unk_61", &pEntity->unk_61);
        RenderPropertyWithHex("unk_62", &pEntity->unk_62);
        RenderPropertyWithHex("unk_63", &pEntity->unk_63);
        RenderPropertyWithHex("unk_64", &pEntity->unk_64);
        RenderPropertyWithHex("unk_65", &pEntity->unk_65);
        RenderPropertyWithHex("unk_66", &pEntity->unk_66);
        RenderPropertyWithHex("unk_67", &pEntity->unk_67);
        RenderPropertyWithHex("unk_68", &pEntity->unk_68);
        RenderPropertyWithHex("unk_69", &pEntity->unk_69);
        RenderPropertyWithHex("unk_70", &pEntity->unk_70);
        RenderPropertyWithHex("unk_71", &pEntity->unk_71);
        RenderPropertyWithHex("unk_72", &pEntity->unk_72);
        RenderPropertyWithHex("unk_73", &pEntity->unk_73);
        RenderPropertyWithHex("unk_74", &pEntity->unk_74);
        RenderPropertyWithHex("unk_75", &pEntity->unk_75);
        EndPropertyTable();
    }
}

void ClientEntityManagerView::RenderProperties(void* pVoid) {
    ClientEntityManagerView::RenderProperties((ClientEntityManager*) pVoid);
}
