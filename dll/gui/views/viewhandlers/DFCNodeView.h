//
// Created by Sophie on 05/07/2021.
//

#ifndef RRSPY2TESTAPP_DFCNODEVIEW_H
#define RRSPY2TESTAPP_DFCNODEVIEW_H


#include "ViewHandler.h"

class DFCNodeView : ViewHandler{
public:
    static void RenderProperties(DFCNode*);

    static void RenderCommonProperties(DFCNode*);

    static void RenderSpecificNodeProperties(DFCNode* nodeToRender);

    static DFCNode* GetCurrentSuperclassNode(DFCNode* pNode);

    static void RenderNodeCrumblebar(DFCNode* pNode);

private:
    int _selectedSuperClassIndex = 0;
};


#endif //RRSPY2TESTAPP_DFCNODEVIEW_H
