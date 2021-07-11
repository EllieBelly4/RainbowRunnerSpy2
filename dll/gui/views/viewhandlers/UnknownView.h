//
// Created by Sophie on 11/07/2021.
//

#ifndef RRSPY2TESTAPP_UNKNOWNVIEW_H
#define RRSPY2TESTAPP_UNKNOWNVIEW_H


#include "ViewHandler.h"

class UnknownView : public ViewHandler {
public:
    void RenderProperties(void* pVoid) override;
};


#endif //RRSPY2TESTAPP_UNKNOWNVIEW_H
