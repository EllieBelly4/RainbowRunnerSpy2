//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYGUILIST_H
#define RRSPY2TESTAPP_RRSPYGUILIST_H


#include <memory>
#include "../../gameobjects/EntityContainer.h"
#include "../../gameobjects/Entities/DFCNode.h"
#include "../../../lib/imgui/imgui.h"
#include "../general/gui_functions.h"
#include "../general/colours.h"
#include "../RRSpyState.h"

class RRSpyGUIList {
public:
    explicit RRSpyGUIList(std::shared_ptr<RRSpyState> state);

    void Render(EntityContainer* pContainer);

    void Render(DFCNode* pNode);

    void RenderItem(DFCNode* pEntity, int i);

private:
    std::shared_ptr<RRSpyState> _state;
};


#endif //RRSPY2TESTAPP_RRSPYGUILIST_H
