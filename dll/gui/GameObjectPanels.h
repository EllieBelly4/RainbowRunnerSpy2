//
// Created by Sophie on 26/06/2021.
//

#ifndef RRSPY2_GAME_OBJECT_PANELS
#define RRSPY2_GAME_OBJECT_PANELS

#include "../gameobjects/EntityManager.h"
#include "../gameobjects/ClientEntity.h"
#include "../gameobjects/Entities/DFCNode.h"
#include "../gameobjects/Entities/Avatar.h"
#include "../gameobjects/Entities/Player.h"
#include "../gameobjects/ServerEntity.h"

void RenderStructPropertyTable(char* ptr, const std::vector<char*> &propertyNames, int numProperties = 40,
                               std::string RenderStructPropertyTable = "Raw Properties");

void RenderGameClientStateManager();

void RenderWorld();

void RenderEntityManager(EntityManager* entityManager);

void RenderEntityManagerEntities(EntityManager* entityManager);

void RenderDFCNodes(ClientEntity* entitiesPtr);

void RenderDFCNode(DFCNode* pEntity);

void RenderEntities(ServerEntity* string);

void AddCopyText(const std::string &basicString);

void RenderProperty(const std::string &propertyName, const std::string &hexStr);

void RenderDFCNodeProperties(DFCNode* pEntity);

void RenderAvatarProperties(Avatar* pAvatar);

void RenderPlayerProperties(Player* pPlayer);

#endif
