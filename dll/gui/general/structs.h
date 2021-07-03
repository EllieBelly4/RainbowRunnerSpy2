//
// Created by Sophie on 02/07/2021.
//

#ifndef RRSPY2TESTAPP_STRUCTS_H
#define RRSPY2TESTAPP_STRUCTS_H

void RenderStructPropertyTable(char* ptr, const std::vector<char*> &propertyNames, int numProperties = 40,
                               std::string RenderStructPropertyTable = "Raw Properties");

#include "../../../lib/imgui/imgui.h"
#include "../../gameobjects/EntityManager.h"
#include "../../gameobjects/ClientEntity.h"
#include "../../gameobjects/Entities/DFCNode.h"
#include "../../gameobjects/Entities/Avatar.h"
#include "../../gameobjects/Entities/Player.h"
#include "../../gameobjects/ServerEntity.h"
#include "../../gameobjects/Entities/MeleeWeapon.h"
#include "../../gameobjects/Entities/GCClass.h"

#endif //RRSPY2TESTAPP_STRUCTS_H
