//
// Created by Sophie on 06/07/2021.
//

#ifndef RRSPY2TESTAPP_CLIENTENTITYMANAGERVIEW_H
#define RRSPY2TESTAPP_CLIENTENTITYMANAGERVIEW_H


#include "ViewHandler.h"
#include "../../../gameobjects/EntityManager.h"

class ClientEntityManagerView : public ViewHandler {
public:
    static void RenderProperties(ClientEntityManager*);
    static void RenderListItem(ClientEntityManager*, int);
};


#endif //RRSPY2TESTAPP_CLIENTENTITYMANAGERVIEW_H
