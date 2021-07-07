//
// Created by Sophie on 06/07/2021.
//

#include "EntityView.h"
#include "DFCNodeView.h"
#include "../../../common.h"

void EntityView::RenderProperties(Entity* pEntity) {
    BeginPropertyTable("entity");
    std::string posString;

    posString += "X: " + std::to_string(pEntity->posX_maybe);
    posString += " Y: " + std::to_string(pEntity->posY_maybe);
    posString += " Z: " + std::to_string(pEntity->posZ_maybe);

    char rotString[128];

    sprintf(rotString, "%.2f", (float) pEntity->rotation / (float) 255);

    posString += " Rot: " + std::string(rotString);

    RenderProperty("Pos", posString);
    EndPropertyTable();
}

void EntityView::RenderListItem(Entity*, int) {

}

void EntityView::RenderProperties(void* pVoid) {
    DFCNodeView::RenderNodeCrumblebar((DFCNode*) pVoid);
    RenderProperties((Entity*) pVoid);
    DFCNodeView::RenderProperties((DFCNode*) pVoid);
}
