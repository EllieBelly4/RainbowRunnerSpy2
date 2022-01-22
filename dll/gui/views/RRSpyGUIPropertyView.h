//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYGUIPROPERTYVIEW_H
#define RRSPY2TESTAPP_RRSPYGUIPROPERTYVIEW_H


#include <memory>
#include "../RRSpyState.h"
#include "../../log/Log.h"

class RRSpyGUIPropertyView {
public:
    explicit RRSpyGUIPropertyView(std::shared_ptr<RRSpyState> state, std::shared_ptr<RRLog::Log> logger);

    void Render();
private:
    std::shared_ptr<RRSpyState> _state;
    std::shared_ptr<RRLog::Log> logger;
};


#endif //RRSPY2TESTAPP_RRSPYGUIPROPERTYVIEW_H
