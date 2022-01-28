//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_RRSPYGUIBASEENTITYWRAPPER_H
#define RRSPY2TESTAPP_RRSPYGUIBASEENTITYWRAPPER_H


#include "../../../lib/imgui/imgui.h"
#include "../../gameobjects/Entities/DFCNode.h"
#include "../../gameobjects/GameClientStateManager.h"
#include "../../gameobjects/ClientEntityList.h"
#include "../../gameobjects/EntityManager.h"
#include "../../gameobjects/EntityContainer.h"
#include "../views/viewhandlers/EntityContainerView.h"
#include "../views/viewhandlers/ClientEntityManagerView.h"
#include "../views/viewhandlers/GameClientStateManagerView.h"
#include "../views/viewhandlers/DFCNodeView.h"
#include "../views/viewhandlers/EntityView.h"
#include "../../gameobjects/Entities/Entity.h"

class RRSpyGUIBaseEntityWrapper {
public:
    explicit RRSpyGUIBaseEntityWrapper(std::string name);

    explicit RRSpyGUIBaseEntityWrapper(std::string name, ViewHandler*);

    template<class T>
    inline T* GetEntity() {
        return static_cast<T*>(_node);
    }

    ViewHandler* View;
    std::string Name;

    inline virtual void RenderProperties(void* pEntity) {
		__try
		{
			View->RenderProperties(pEntity);

		}
		__catch (...)
		{
			puts("in except");
		}
    };

    inline virtual void RenderListItem(void*, int) {};

private:
    void* _node;
};


#endif //RRSPY2TESTAPP_RRSPYGUIBASEENTITYWRAPPER_H
