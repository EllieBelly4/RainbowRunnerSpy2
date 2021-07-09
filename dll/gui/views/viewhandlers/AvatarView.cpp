//
// Created by Sophie on 04/07/2021.
//

#include "AvatarView.h"
#include "DFCNodeView.h"
#include <string>

void AvatarView::RenderProperties(Avatar* pEntity) {
    BeginPropertyTable("avatarview");
    std::string stateString;

    if ((pEntity->SomeState2 & 0x40) > 0) {
        stateString += "Moving |";
    } else {
        stateString = "Standing |";
    }

    stateString = stateString.substr(0, stateString.length() - 2);

    RenderProperty("State", stateString);
    EndPropertyTable();
}

void AvatarView::RenderProperties(void* pVoid) {
    DFCNodeView::RenderNodeCrumblebar((DFCNode*) pVoid);
    RenderProperties((Avatar*) pVoid);
    EntityView::RenderProperties((Entity*)pVoid);
    DFCNodeView::RenderProperties((DFCNode*) pVoid);
}
