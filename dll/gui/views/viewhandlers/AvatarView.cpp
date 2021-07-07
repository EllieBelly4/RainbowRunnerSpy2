//
// Created by Sophie on 04/07/2021.
//

#include "AvatarView.h"
#include "../../../common.h"
#include <string>

void AvatarView::RenderProperties(Avatar* pEntity) {
    EntityView::RenderProperties(pEntity);

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
    EntityView::RenderProperties(pVoid);
}
