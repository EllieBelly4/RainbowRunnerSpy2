//
// Created by Ellie on 04/12/2022.
//

#ifndef RRSPY2TESTAPP_PATHMANAGERVIEW_H
#define RRSPY2TESTAPP_PATHMANAGERVIEW_H


#include "ViewHandler.h"
#include "gameobjects/PathManager.h"

class PathManagerView : public ViewHandler {
public:
    static void RenderProperties(PathManager* pEntity);

    void RenderProperties(void *pVoid) override;
};


#endif //RRSPY2TESTAPP_PATHMANAGERVIEW_H
