//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyGUIEntityWrapper.h"

RRSpyGUIEntityWrapper::RRSpyGUIEntityWrapper(void* pNode, ImGuiID id) : _node(pNode), ImGui_ID(id) {}

RRSpyGameClientStateManager::RRSpyGameClientStateManager
        (GameClientStateManager* pNode, ImGuiID id) : RRSpyGUIEntityWrapper(pNode, id) {}

RRSpyDFCNode::RRSpyDFCNode
        (DFCNode* pNode, ImGuiID id) : RRSpyGUIEntityWrapper(pNode, id) {}

