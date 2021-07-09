//
// Created by Sophie on 04/07/2021.
//

#include "PlayerView.h"
#include "../../../common.h"

void PlayerView::RenderProperties(Player* pEntity) {
    BeginPropertyTable("player");

    if(!IsBadReadPtr(pEntity->Name)){
        RenderProperty("Name", pEntity->Name->ToString());
    }

    EndPropertyTable();
}

void PlayerView::RenderProperties(void* pVoid) {
    DFCNodeView::RenderNodeCrumblebar((DFCNode*) pVoid);
    RenderProperties((Player*) pVoid);
    DFCNodeView::RenderProperties((DFCNode*) pVoid);
}
