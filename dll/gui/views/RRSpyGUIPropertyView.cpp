//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyGUIPropertyView.h"
#include "../../common.h"
#include "../../rrspy.h"
#include "../../datatypes/GCProperties.h"
#include "viewhandlers/AvatarView.h"
#include "viewhandlers/DFCNodeView.h"
#include "viewhandlers/GameClientStateManagerView.h"

RRSpyGUIPropertyView::RRSpyGUIPropertyView(std::shared_ptr<RRSpyState> state, std::shared_ptr<log::Log> logger)
        : _state(state), logger(logger) {
}

void RRSpyGUIPropertyView::Render() {
    ImGui::Begin("Properties", &_state->PropertiesOpen);

    auto currentSelectedEntity = _state->CurrentSelectedEntity;
    auto entity = _state->CurrentSelectedEntity->GetEntity<void>();

    if (currentSelectedEntity != nullptr && !IsBadReadPtr(entity)) {
        if (std::dynamic_pointer_cast<RRSpyDFCNode>(currentSelectedEntity)) {
            DFCNodeView::RenderProperties((DFCNode*) entity);
        }else if (std::dynamic_pointer_cast<RRSpyGameClientStateManager>(currentSelectedEntity)) {
            GameClientStateManagerView::RenderProperties((GameClientStateManager*) entity);
        }
    }

    ImGui::End();
}
