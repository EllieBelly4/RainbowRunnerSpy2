//
// Created by Sophie on 04/07/2021.
//

#include "AvatarView.h"
#include <string>

void AvatarView::RenderProperties(Avatar* pEntity) {
    if (BeginFullPropertyTable("avatarview")) {
        std::string stateString;

        if ((pEntity->SomeState2 & 0x40) > 0) {
            stateString += "Moving |";
        } else {
            stateString = "Standing |";
        }

        stateString = stateString.substr(0, stateString.length() - 2);

        RenderProperty("State", stateString);

        ImGui::TableNextRow();

        RenderPropertyWithHex("EntityObject2", &pEntity->EntityObject2);
        RenderPropertyWithHex("SomeState", &pEntity->SomeState);
        RenderPropertyWithHex("unk_42", &pEntity->unk_42);
        RenderPropertyWithHex("SomeState2", &pEntity->SomeState2);
        RenderPropertyWithHex("unk_44", &pEntity->unk_44);
        RenderPropertyWithHex("unk_45", &pEntity->unk_45);
        RenderPropertyWithHex("unk_46", &pEntity->unk_46);
        RenderPropertyWithHex("unk_47", &pEntity->unk_47);
        RenderPropertyWithHex("unk_48", &pEntity->unk_48);
        RenderPropertyWithHex("unk_49", &pEntity->unk_49);
        RenderPropertyWithHex("unk_50", &pEntity->unk_50);

        EndPropertyTable();
    }
}

void AvatarView::RenderProperties(void* pVoid) {
    pVoid = GetCurrentSuperclassNode((DFCNode*) pVoid);
    RenderProperties((Avatar*) pVoid);
    EntityView::RenderProperties((Entity*) pVoid);
    DFCNodeView::RenderProperties((DFCNode*) pVoid);
}
