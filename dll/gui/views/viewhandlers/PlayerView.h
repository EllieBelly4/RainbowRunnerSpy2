//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_PLAYERVIEW_H
#define RRSPY2TESTAPP_PLAYERVIEW_H


#include "../../../gameobjects/Entities/Player.h"
#include "DFCNodeView.h"

class PlayerView : public ViewHandler {
public:
    static void RenderProperties(Player*);

    void RenderProperties(void* pVoid) override;
};


#endif //RRSPY2TESTAPP_PLAYERVIEW_H
