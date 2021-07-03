//
// Created by Sophie on 03/07/2021.
//

#ifndef RRSPY2TESTAPP_LIST_H
#define RRSPY2TESTAPP_LIST_H

#include "../../../lib/imgui/imgui.h"
#include "../GameObjectPanels.h"
#include "../../gameobjects/EntityManager.h"
#include "../../gameobjects/ClientEntity.h"
#include "../../gameobjects/Entities/DFCNode.h"
#include "../../gameobjects/Entities/Avatar.h"
#include "../../gameobjects/Entities/Player.h"
#include "../../gameobjects/ServerEntity.h"
#include "../../gameobjects/Entities/MeleeWeapon.h"
#include "../../gameobjects/Entities/GCClass.h"
#include "../general/colours.h"
#include "../general/gui_functions.h"
#include "../../common.h"

void RenderEntityManager(EntityManager* entityManager);

void RenderEntityManagerEntities(EntityManager* entityManager);

void RenderEntityArray(unsigned int pStart, unsigned int pEnd);

void RenderEntityLinkedList(unsigned int child, unsigned int child1);

void RenderDFCNodes(ServerEntity* entitiesPtr);

void RenderDFCNodes(ClientEntity* entitiesPtr);

void RenderDFCNodeListItem(DFCNode* pEntity, int i);

void AddDFCNodeTreeText(DFCNode* pEntity);

#endif //RRSPY2TESTAPP_LIST_H
