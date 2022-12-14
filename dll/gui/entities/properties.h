//
// Created by Sophie on 03/07/2021.
//

#ifndef RRSPY2TESTAPP_PROPERTIES_H
#define RRSPY2TESTAPP_PROPERTIES_H

#include "../../gameobjects/Entities/DFCNode.h"
#include "../../gameobjects/Entities/MeleeWeapon.h"
#include "../../gameobjects/Entities/Player.h"
#include "../../gameobjects/Entities/Avatar.h"

void RenderGCProperties(GCProperties* properties);

void RenderGCCLass(GCClass* pClass);

void RenderDFCNodeProperties(DFCNode* pEntity);

void RenderNumberProperty(const std::string &propertyName, const unsigned int number);

void RenderProperty(const std::string &propertyName, const std::string &hexStr);

#endif //RRSPY2TESTAPP_PROPERTIES_H
