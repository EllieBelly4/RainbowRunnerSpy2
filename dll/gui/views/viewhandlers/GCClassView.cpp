//
// Created by Sophie on 05/07/2021.
//

#include "GCClassView.h"
#include "../../../common.h"
#include "../../general/gui_functions.h"

void GCClassView::RenderProperties(GCClass* pClass) {
    if(BeginFullPropertyTable("gcclass")){
        if (!IsBadReadPtr(pClass->TypeName)) {
            RenderProperty("TypeName", pClass->TypeName->ToString());
            ImGui::TableNextRow();
        }

        if (!IsBadReadPtr(pClass->FQTypeName)) {
            RenderProperty("FQTypeName", pClass->FQTypeName->ToString());
            ImGui::TableNextRow();
        }

        if (pClass->GCTypeHash != 0) {
            RenderProperty("GCTypeHash", IntToHex(pClass->GCTypeHash));
            ImGui::TableNextRow();
        }

        RenderPropertyWithHex("Unk2", &pClass->Unk2);
        RenderPropertyWithHex("Unk3", &pClass->Unk3);
        RenderPropertyWithHex("GCTypeHash", &pClass->GCTypeHash);
        RenderPropertyWithHex("Unk7", &pClass->Unk7);
        RenderPropertyWithHex("Unk8", &pClass->Unk8);
        RenderPropertyWithHex("Unk9", &pClass->Unk9);
        RenderPropertyWithHex("Unk10", &pClass->Unk10);
        RenderPropertyWithHex("Unk11", &pClass->Unk11);
        RenderPropertyWithHex("Unk12", &pClass->Unk12);
        RenderPropertyWithHex("Unk13", &pClass->Unk13);
        RenderPropertyWithHex("Unk14", &pClass->Unk14);
        RenderPropertyWithHex("Unk15", &pClass->Unk15);
        RenderPropertyWithHex("Unk16", &pClass->Unk16);
        RenderPropertyWithHex("Unk17", &pClass->Unk17);
        RenderPropertyWithHex("Unk18", &pClass->Unk18);
        RenderPropertyWithHex("Unk19", &pClass->Unk19);
        RenderPropertyWithHex("Unk20", &pClass->Unk20);
        RenderPropertyWithHex("Unk21", &pClass->Unk21);
        RenderPropertyWithHex("Unk22", &pClass->Unk22);
        RenderPropertyWithHex("Unk23", &pClass->Unk23);
        RenderPropertyWithHex("Unk24", &pClass->Unk24);
        RenderPropertyWithHex("Unk25", &pClass->Unk25);
        RenderPropertyWithHex("Unk26", &pClass->Unk26);
        RenderPropertyWithHex("Unk27", &pClass->Unk27);

        EndPropertyTable();
    }
}
