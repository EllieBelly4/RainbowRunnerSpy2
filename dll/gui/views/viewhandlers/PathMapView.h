//
// Created by Ellie on 04/12/2022.
//

#ifndef RRSPY2TESTAPP_PATHMAPVIEW_H
#define RRSPY2TESTAPP_PATHMAPVIEW_H


#include "ViewHandler.h"
#include "gameobjects/PathMap.h"

class PathMapView : public ViewHandler{
public:
    static void RenderProperties(PathMap* pathMap);

    void RenderProperties(void *pVoid) override;
};


#endif //RRSPY2TESTAPP_PATHMAPVIEW_H