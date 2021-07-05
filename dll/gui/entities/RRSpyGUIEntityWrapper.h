//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYGUIENTITYWRAPPER_H
#define RRSPY2TESTAPP_RRSPYGUIENTITYWRAPPER_H


#include "../../../lib/imgui/imgui.h"
#include "../../gameobjects/Entities/DFCNode.h"
#include "../../gameobjects/GameClientStateManager.h"

class RRSpyGUIEntityWrapper {
public:
    explicit RRSpyGUIEntityWrapper(void* pNode, ImGuiID id);

    template<class T>
    inline T* GetEntity() {
        return static_cast<T*>(_node);
    }

    ImGuiID ImGui_ID;

    virtual ~RRSpyGUIEntityWrapper() = default;
private:
    void* _node;
};

class RRSpyDFCNode: public RRSpyGUIEntityWrapper {
public:
    explicit RRSpyDFCNode(DFCNode* pNode, ImGuiID id);
};

class RRSpyGameClientStateManager : public RRSpyGUIEntityWrapper {
public:
    explicit RRSpyGameClientStateManager(GameClientStateManager* pNode, ImGuiID id);
};


#endif //RRSPY2TESTAPP_RRSPYGUIENTITYWRAPPER_H
