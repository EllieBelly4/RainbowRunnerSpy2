//
// Created by Sophie on 06/07/2021.
//

#ifndef RRSPY2TESTAPP_ENTITYCONTAINERVIEW_H
#define RRSPY2TESTAPP_ENTITYCONTAINERVIEW_H


#include "ViewHandler.h"
#include "../../../gameobjects/EntityManager.h"
#include "../../../gameobjects/EntityContainer.h"

class EntityContainerView : public ViewHandler {
public:
    static void RenderListItem(EntityContainer*, int);
    static void RenderProperties(EntityContainer*);
    void RenderProperties(void*) override;
};


#endif //RRSPY2TESTAPP_ENTITYCONTAINERVIEW_H
