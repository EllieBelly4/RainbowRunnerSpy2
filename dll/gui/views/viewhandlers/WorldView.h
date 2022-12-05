//
// Created by Sophie on 06/07/2021.
//

#ifndef RRSPY2TESTAPP_WORLDVIEW_H
#define RRSPY2TESTAPP_WORLDVIEW_H


#include "ViewHandler.h"
#include "DFCNodeView.h"
#include "gameobjects/World.h"

class WorldView : public DFCNodeView {

public:
    static void RenderProperties(World *);

    void RenderCustomView(void *pEntity);

    void RenderProperties(void *pVoid) override;

    void DumpStaticObjects(DFCNode *pNode);
};


#endif //RRSPY2TESTAPP_WORLDVIEW_H
