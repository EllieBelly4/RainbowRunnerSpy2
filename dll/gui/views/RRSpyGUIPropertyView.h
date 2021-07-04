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
    explicit RRSpyGUIPropertyView(std::shared_ptr<RRSpyState> state, std::shared_ptr<log::Log> logger);

    void Render();
private:
    std::shared_ptr<RRSpyState> _state;
    std::shared_ptr<log::Log> logger;

    int _selectedSuperClassIndex = 0;

    void RenderProperties(DFCNode* pNode);

    void RenderNodeCrumblebar(DFCNode* pNode);
};


#endif //RRSPY2TESTAPP_RRSPYGUIPROPERTYVIEW_H
