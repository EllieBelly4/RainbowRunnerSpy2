//
// Created by Sophie on 06/07/2021.
//

#ifndef RRSPY2TESTAPP_STATICOBJECTVIEW_H
#define RRSPY2TESTAPP_STATICOBJECTVIEW_H


#include "ViewHandler.h"
#include "DFCNodeView.h"
#include "gameobjects/Entities/StaticObject.h"

class StaticObjectView : public DFCNodeView {

public:
    static void RenderProperties(StaticObject*);
    static void RenderListItem(StaticObject*, int);

    void RenderProperties(void* pVoid) override;
};


#endif //RRSPY2TESTAPP_STATICOBJECTVIEW_H
