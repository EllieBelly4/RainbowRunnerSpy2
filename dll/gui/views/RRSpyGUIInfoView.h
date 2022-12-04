//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYGUIINFOVIEW_H
#define RRSPY2TESTAPP_RRSPYGUIINFOVIEW_H

#include <memory>
#include "../components/RRSpyGUIList.h"
#include "../RRSpyState.h"
#include "../../log/Log.h"
#include "state.h"
#include "../../gameobjects/map.h"

class RRSpyGUIInfoView {
public:
    explicit RRSpyGUIInfoView(std::shared_ptr<RRSpyState> state, std::shared_ptr<RRLog::Log> logger);

    void Render();

private:
    std::shared_ptr<RRSpyGUIList> entityList;
    std::shared_ptr<RRSpyState> _state;
    std::shared_ptr<RRLog::Log> logger;

    void RenderEntities();

    void RenderGlobalObjects();

    void RenderGeneralInfo();

    const char *AddEntityManagerListItem(EntityContainer **pEntityContainer, EntityContainer **pComponentList, int i);

};

template<class T>
void RenderListItem(const char *label, T *entity, int i) {
    ImGuiID id = ImGui::GetID(label);

    if (ViewHandler::RenderSelectableListItem(i, label, id) == ListItemClicked) {
        state->SetSelectedEntity(GetEntityWrapper((void *) reinterpret_cast<unsigned int*>(entity)[0]), entity, id);
    }
}

#endif //RRSPY2TESTAPP_RRSPYGUIINFOVIEW_H
