//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_ENTITYCONTAINER_H
#define RRSPY2TESTAPP_ENTITYCONTAINER_H

#include <cstdint>

// Replaces ServerEntity and ClientEntityList
class EntityContainer {
public:
    uintptr_t OwnedObjectsStart;
    uintptr_t OwnedObjectsEnd;
    uintptr_t OwnedObjectsEnd_2;
    int Unk4;
    int Unk5;
    int Unk6;
    int Unk7;
    int Unk8;
    int Unk9;
};


#endif //RRSPY2TESTAPP_ENTITYCONTAINER_H
