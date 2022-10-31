//
// Created by Sophie on 06/07/2021.
//

#include "EntityView.h"
#include "DFCNodeView.h"
#include "../../../common.h"

void EntityView::RenderProperties(Entity* pEntity) {
    if(BeginFullPropertyTable("entity")){
        std::string posString;

        auto posX = (float)pEntity->posX_maybe / (float)256;
        auto posY = (float)pEntity->posY_maybe / (float)256;
        auto posZ = (float)pEntity->posZ_maybe / (float)256;

        posString += "X: " + std::to_string(posX);
        posString += " Y: " + std::to_string(posY);
        posString += " Z: " + std::to_string(posZ);

        char rotString[128];

        sprintf(rotString, "%.2f", (float) pEntity->rotation / (float) 256);

        posString += " Rot: " + std::string(rotString);

        RenderProperty("Pos", posString);
        ImGui::TableNextRow();

        RenderPropertyWithHex("unk_00", &pEntity->unk_00);
        RenderPropertyWithHex("unk_26", &pEntity->unk_26);
        RenderPropertyWithHex("unk_27", &pEntity->unk_27);
        RenderPropertyWithHex("unk_28", &pEntity->unk_28);
        RenderPropertyWithHex("unk_29", &pEntity->unk_29);
        RenderPropertyWithHex("unk_30", &pEntity->unk_30);
        RenderPropertyWithHex("unk_31", &pEntity->unk_31);
        RenderPropertyWithHex("unk_32", &pEntity->unk_32);
        RenderPropertyWithHex("unk_33", &pEntity->unk_33);
        RenderPropertyWithHex("EntityManager", (unsigned int*) &pEntity->EntityManager);
        RenderPropertyWithHex("unk_34", &pEntity->unk_34);
        RenderPropertyWithHex("posX", &posX);
        RenderPropertyWithHex("posY", &posY);
        RenderPropertyWithHex("posZ", &posZ);
        RenderPropertyWithHex("rotation", &pEntity->rotation);
        RenderPropertyWithHex("unk_35", &pEntity->unk_35);
        RenderPropertyWithHex("World", (unsigned int*) &pEntity->World);
        RenderPropertyWithHex("unk_37", &pEntity->unk_37);
        RenderPropertyWithHex("unk_38", &pEntity->unk_38);
        RenderPropertyWithHex("EntityObject", &pEntity->EntityObject);
        RenderPropertyWithHex("unk_40", &pEntity->unk_40);

        EndPropertyTable();
    }
}

void EntityView::RenderListItem(Entity*, int) {

}

void EntityView::RenderProperties(void* pVoid) {
    pVoid = GetCurrentSuperclassNode((DFCNode*) pVoid);
    RenderProperties((Entity*) pVoid);
    DFCNodeView::RenderProperties((DFCNode*) pVoid);
}
