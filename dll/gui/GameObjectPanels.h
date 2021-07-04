//
// Created by Sophie on 26/06/2021.
//

#ifndef RRSPY2_GAME_OBJECT_PANELS
#define RRSPY2_GAME_OBJECT_PANELS

#include "../../lib/imgui/imgui.h"
#include "../gameobjects/EntityManager.h"
#include "../gameobjects/ClientEntity.h"
#include "../gameobjects/Entities/DFCNode.h"
#include "../gameobjects/Entities/Avatar.h"
#include "../gameobjects/Entities/Player.h"
#include "../gameobjects/ServerEntity.h"
#include "../gameobjects/Entities/MeleeWeapon.h"
#include "../gameobjects/Entities/GCClass.h"

extern DFCNode* SelectedDFCNode;
extern ImGuiID SelectedDFCNodeID;

void RenderWorld();

void RenderGCClassProperties(GCClass* pClass);

#endif
