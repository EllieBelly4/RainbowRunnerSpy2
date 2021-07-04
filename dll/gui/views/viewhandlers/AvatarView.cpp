//
// Created by Sophie on 04/07/2021.
//

#include "AvatarView.h"

void AvatarView::RenderProperties(Avatar* entity) {
    std::string stateString;

    BeginPropertyTable();

    if ((entity->SomeState2 & 0x40) > 0) {
        stateString += "Moving |";
    } else {
        stateString = "Standing |";
    }

    stateString = stateString.substr(0, stateString.length() - 2);

    RenderProperty("State", stateString);

    std::string posString;

    posString += "X: " + std::__cxx11::to_string(entity->posX_maybe);
    posString += " Y: " + std::__cxx11::to_string(entity->posY_maybe);

    RenderProperty("Position", posString);
    RenderProperty("Rotation", std::to_string((float) entity->rotation / (float) 255));

    EndPropertyTable();
}
