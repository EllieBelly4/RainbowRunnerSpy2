//
// Created by Sophie on 12/07/2021.
//

#ifndef RRSPY2TESTAPP_GCPROPERTIESVIEW_H
#define RRSPY2TESTAPP_GCPROPERTIESVIEW_H


#include "ViewHandler.h"

class GCPropertiesView : public ViewHandler {
public:
    static void RenderProperties(GCProperties* pEntity);
    void RenderProperties(void* pVoid) override;
};


#endif //RRSPY2TESTAPP_GCPROPERTIESVIEW_H
