//
// Created by Sophie on 06/07/2021.
//

#ifndef RRSPY2TESTAPP_MAP_H
#define RRSPY2TESTAPP_MAP_H

#include <string>
#include <memory>
#include <map>
#include "../gui/entities/RRSpyGUIBaseEntityWrapper.h"

extern std::map<unsigned int, std::shared_ptr<RRSpyGUIBaseEntityWrapper>> EntityMap;

void InitialiseEntityMap();

#endif //RRSPY2TESTAPP_MAP_H
