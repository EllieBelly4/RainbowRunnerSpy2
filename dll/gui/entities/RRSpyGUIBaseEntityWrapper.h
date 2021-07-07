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
        View->RenderProperties(pEntity);
    };

    inline virtual void RenderListItem(void*, int) {};

private:
    void* _node;
};

//class RRSpyDFCNode : public RRSpyGUIBaseEntityWrapper {
//    using RRSpyGUIBaseEntityWrapper::RRSpyGUIBaseEntityWrapper;
//
//public:
//    inline void RenderListItem(void* pVoid, int i) override {
//        DFCNodeView::RenderListItem((DFCNode*) pVoid, i);
//    }
//
//    inline void RenderProperties(void* pVoid) override {
//        DFCNodeView::RenderProperties((DFCNode*) pVoid);
//    }
//};
//
//class RRSpyGameClientStateManager : public RRSpyGUIBaseEntityWrapper {
//    using RRSpyGUIBaseEntityWrapper::RRSpyGUIBaseEntityWrapper;
//
//public:
//    inline void RenderListItem(void* pVoid, int i) override {
//        GameClientStateManagerView::RenderListItem((GameClientStateManager*) pVoid, i);
//    }
//
//    inline void RenderProperties(void* pVoid) override {
//        GameClientStateManagerView::RenderProperties((GameClientStateManager*) pVoid);
//    }
//};
//
//class RRSpyClientEntityManager : public RRSpyGUIBaseEntityWrapper {
//    using RRSpyGUIBaseEntityWrapper::RRSpyGUIBaseEntityWrapper;
//
//public:
//    inline void RenderListItem(void* pVoid, int i) override {
//        ClientEntityManagerView::RenderListItem((ClientEntityManager*) pVoid, i);
//    }
//
//    inline void RenderProperties(void* pVoid) override {
//        ClientEntityManagerView::RenderProperties((ClientEntityManager*) pVoid);
//    }
//};
//
//class RRSpyEntityContainer : public RRSpyGUIBaseEntityWrapper {
//    using RRSpyGUIBaseEntityWrapper::RRSpyGUIBaseEntityWrapper;
//
//public:
//    inline void RenderListItem(void* pVoid, int i) override {
//        EntityContainerView::RenderListItem((EntityContainer*) pVoid, i);
//    }
//
//    inline void RenderProperties(void* pVoid) override {
//        EntityContainerView::RenderProperties((EntityContainer*) pVoid);
//    }
//};
//
//class RRSpyEntity : public RRSpyGUIBaseEntityWrapper {
//    using RRSpyGUIBaseEntityWrapper::RRSpyGUIBaseEntityWrapper;
//
//public:
//    inline void RenderListItem(void* pVoid, int i) override {
//        EntityView::RenderListItem((Entity*) pVoid, i);
//    }
//
//    inline void RenderProperties(void* pVoid) override {
//        EntityView::RenderProperties((Entity*) pVoid);
//    }
//};


#endif //RRSPY2TESTAPP_RRSPYGUIBASEENTITYWRAPPER_H
