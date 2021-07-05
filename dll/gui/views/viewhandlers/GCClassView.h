//
// Created by Sophie on 05/07/2021.
//

#ifndef RRSPY2TESTAPP_GCCLASSVIEW_H
#define RRSPY2TESTAPP_GCCLASSVIEW_H


#include "ViewHandler.h"
#include "../../../gameobjects/Entities/GCClass.h"

class GCClassView : public ViewHandler {
public:
    static void RenderProperties(GCClass*);
};


#endif //RRSPY2TESTAPP_GCCLASSVIEW_H
