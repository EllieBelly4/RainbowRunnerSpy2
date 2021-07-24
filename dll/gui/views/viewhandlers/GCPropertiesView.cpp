//
// Created by Sophie on 12/07/2021.
//

#include "GCPropertiesView.h"


void GCPropertiesView::RenderProperties(void* pVoid) {
    GCPropertiesView::RenderProperties((GCProperties*) pVoid);
}

void GCPropertiesView::RenderProperties(GCProperties* pEntity) {
    if(BeginFullPropertyTable("gcproperties")){
        RenderPropertyWithHex("Unk0", &pEntity->Unk0);
        RenderPropertyWithHex("Unk1", (unsigned int*) &pEntity->Unk1);
        RenderPropertyWithHex("Unk2", &pEntity->Unk2);
        RenderPropertyWithHex("Unk3", &pEntity->Unk3);
        RenderPropertyWithHex("Unk4", &pEntity->Unk4);
        RenderPropertyWithHex("Unk5", &pEntity->Unk5);
        RenderPropertyWithHex("Unk6", &pEntity->Unk6);
        RenderPropertyWithHex("Unk7", &pEntity->Unk7);
        RenderPropertyWithHex("Unk8", &pEntity->Unk8);
        RenderPropertyWithHex("Unk9", &pEntity->Unk9);

        EndPropertyTable();
    }
}
