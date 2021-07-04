//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYGUIINFOVIEW_H
#define RRSPY2TESTAPP_RRSPYGUIINFOVIEW_H

#include <memory>
#include "../components/RRSpyGUIList.h"
#include "../RRSpyState.h"
#include "../../log/Log.h"

class RRSpyGUIInfoView {
public:
    explicit RRSpyGUIInfoView(std::shared_ptr<RRSpyState> state, std::shared_ptr<log::Log> logger);

    void Render();

private:
    std::shared_ptr<RRSpyGUIList> entityList;
    std::shared_ptr<RRSpyState> _state;
    std::shared_ptr<log::Log> logger;

    void RenderEntities();

    void RenderGlobalObjects();

    void RenderGeneralInfo();
};


#endif //RRSPY2TESTAPP_RRSPYGUIINFOVIEW_H
