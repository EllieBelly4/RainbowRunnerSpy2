//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYGUIENTITYWRAPPER_H
#define RRSPY2TESTAPP_RRSPYGUIENTITYWRAPPER_H


#include "../../../lib/imgui/imgui.h"
#include "../../gameobjects/Entities/DFCNode.h"

class RRSpyGUIEntityWrapper {
public:
    explicit RRSpyGUIEntityWrapper(DFCNode* pNode, ImGuiID id);

    ImGuiID ImGui_ID;
    DFCNode* _node;
};


#endif //RRSPY2TESTAPP_RRSPYGUIENTITYWRAPPER_H
