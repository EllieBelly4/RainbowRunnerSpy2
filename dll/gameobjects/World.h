//
// Created by Sophie on 26/06/2021.
//

#ifndef RRSPY2TESTAPP_WORLD_H
#define RRSPY2TESTAPP_WORLD_H

#include <vector>

struct World {
    void* VFTable;
    int References;
};

extern World* World;
std::vector<char*> GetWorldProperties();

#endif //RRSPY2TESTAPP_WORLD_H
