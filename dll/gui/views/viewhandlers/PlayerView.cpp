//
// Created by Sophie on 04/07/2021.
//

#include "PlayerView.h"
#include "../../../common.h"

void PlayerView::RenderProperties(Player* pEntity) {
    if (BeginFullPropertyTable("player")) {
        if (!IsBadReadPtr(pEntity->Name)) {
            RenderProperty("Name", pEntity->Name->ToString());
        }

        RenderPropertyWithHex("unk_0", &pEntity->unk_0);
        RenderPropertyWithHex("unk_1", &pEntity->unk_1);
        RenderPropertyWithHex("unk_3", &pEntity->unk_3);
        RenderPropertyWithHex("unk_4", &pEntity->unk_4);
        RenderPropertyWithHex("unk_5", &pEntity->unk_5);
        RenderPropertyWithHex("unk_6", &pEntity->unk_6);
        RenderPropertyWithHex("PreviousSibling", &pEntity->unk_7);
        RenderPropertyWithHex("unk_8", &pEntity->unk_8);
        RenderPropertyWithHex("unk_9", &pEntity->unk_9);
        RenderPropertyWithHex("unk_10", &pEntity->unk_10);
        RenderPropertyWithHex("unk_11", &pEntity->unk_11);
        RenderPropertyWithHex("unk_12", &pEntity->unk_12);
        RenderPropertyWithHex("unk_13", &pEntity->unk_13);
        RenderPropertyWithHex("unk_14", &pEntity->unk_14);
        RenderPropertyWithHex("unk_15", &pEntity->unk_15);
        RenderPropertyWithHex("unk_16", &pEntity->unk_16);
        RenderPropertyWithHex("unk_17", &pEntity->unk_17);
        RenderPropertyWithHex("unk_18", &pEntity->unk_18);
        RenderPropertyWithHex("unk_19", &pEntity->unk_19);
        RenderPropertyWithHex("unk_20", &pEntity->unk_20);
        RenderPropertyWithHex("unk_21", &pEntity->unk_21);
        RenderPropertyWithHex("unk_22", &pEntity->unk_22);
        RenderPropertyWithHex("unk_23", &pEntity->unk_23);
        RenderPropertyWithHex("unk_24", &pEntity->unk_24);
        RenderPropertyWithHex("unk_25", &pEntity->unk_25);
        RenderPropertyWithHex("unk_26", &pEntity->unk_26);
        RenderPropertyWithHex("unk_27", &pEntity->unk_27);
        RenderPropertyWithHex("unk_28", &pEntity->unk_28);
        RenderPropertyWithHex("unk_29", &pEntity->unk_29);
        RenderPropertyWithHex("unk_30", &pEntity->unk_30);
        RenderPropertyWithHex("unk_31", &pEntity->unk_31);
        RenderPropertyWithHex("unk_32", &pEntity->unk_32);
        RenderPropertyWithHex("unk_33", &pEntity->unk_33);
        RenderPropertyWithHex("unk_34", &pEntity->unk_34);
        RenderPropertyWithHex("unk_35", &pEntity->unk_35);
        RenderPropertyWithHex("unk_36", &pEntity->unk_36);
        RenderPropertyWithHex("ID", &pEntity->unk_37);
        RenderPropertyWithHex("unk_38", &pEntity->unk_38);
        RenderPropertyWithHex("unk_39", &pEntity->unk_39);
        RenderPropertyWithHex("unk_40", &pEntity->unk_40);
        RenderPropertyWithHex("unk_41", &pEntity->unk_41);

        EndPropertyTable();
    }
}

void PlayerView::RenderProperties(void* pVoid) {
    pVoid = GetCurrentSuperclassNode((DFCNode*) pVoid);
    RenderProperties((Player*) pVoid);
    DFCNodeView::RenderProperties((DFCNode*) pVoid);
}
