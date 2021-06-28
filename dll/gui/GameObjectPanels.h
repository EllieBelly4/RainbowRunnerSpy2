//
// Created by Sophie on 26/06/2021.
//

#ifndef RRSPY2_GAME_OBJECT_PANELS
#define RRSPY2_GAME_OBJECT_PANELS

#include "../gameobjects/EntityManager.h"

void RenderStructPropertyTable(char* ptr, const std::vector<char*> &propertyNames, int numProperties = 40);

void RenderGameClientStateManager();

void RenderWorld();

void RenderEntityManager(EntityManager* entityManager);

#endif
