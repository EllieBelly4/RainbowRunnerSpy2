//
// Created by Sophie on 27/06/2021.
//

#ifndef RRSPY2TESTAPP_AVATAR_H
#define RRSPY2TESTAPP_AVATAR_H

#include <string>
#include <vector>
#include "DFCNode.h"

struct EntityManager;
struct World;

class Avatar : public DFCNode {
public:
    EntityManager* EntityManager; // 0x88
    unsigned int unk_33; // 0x8c
    unsigned int unk_34; // 0x90
    unsigned int posX_maybe; // 0x94
    unsigned int posY_maybe; // 0x98
    unsigned int rotation; // 0x9c
    unsigned int unk_35; // 0xa0
    World* World; // 0xa4
    unsigned int unk_37; // 0xa8
    unsigned int unk_38; // 0xac
    unsigned int EntityObject;
    unsigned int unk_40;
    unsigned int EntityObject2;
    unsigned int SomeState;
    unsigned int unk_42;
    unsigned int SomeState2;
    unsigned int unk_44;
    unsigned int unk_45;
    unsigned int unk_46;
    unsigned int unk_47;
    unsigned int unk_48;
    unsigned int unk_49;
    unsigned int unk_50;

    std::string DoSomething();
};

const std::vector<char*> GetAvatarProperties();

#endif //RRSPY2TESTAPP_AVATAR_H
