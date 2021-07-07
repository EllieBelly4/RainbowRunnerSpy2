//
// Created by Sophie on 05/07/2021.
//

#ifndef RRSPY2TESTAPP_GAMECLIENTSTATEMANAGERVIEW_H
#define RRSPY2TESTAPP_GAMECLIENTSTATEMANAGERVIEW_H


#include "ViewHandler.h"
#include "../../../gameobjects/GameClientStateManager.h"

class GameClientStateManagerView : public ViewHandler {
public:
    static void RenderListItem(GameClientStateManager*, int);

    static void RenderProperties(GameClientStateManager* pEntity);

    void RenderProperties(void* pVoid) override;
};


#endif //RRSPY2TESTAPP_GAMECLIENTSTATEMANAGERVIEW_H
