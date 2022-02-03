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
    static void RenderProperties(World*);
    static void RenderListItem(World*, int);

    void RenderProperties(void* pVoid) override;
};


#endif //RRSPY2TESTAPP_WORLDVIEW_H
