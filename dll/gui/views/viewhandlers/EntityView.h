//
// Created by Sophie on 06/07/2021.
//

#ifndef RRSPY2TESTAPP_ENTITYVIEW_H
#define RRSPY2TESTAPP_ENTITYVIEW_H


#include "ViewHandler.h"
#include "../../../gameobjects/Entities/Avatar.h"
#include "DFCNodeView.h"

class EntityView : public DFCNodeView {

public:
    static void RenderProperties(Entity*);
    static void RenderListItem(Entity*, int);

    void RenderProperties(void* pVoid) override;
};


#endif //RRSPY2TESTAPP_ENTITYVIEW_H
