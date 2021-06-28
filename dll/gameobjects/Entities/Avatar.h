//
// Created by Sophie on 27/06/2021.
//

#ifndef RRSPY2TESTAPP_AVATAR_H
#define RRSPY2TESTAPP_AVATAR_H

#include <string>
#include <vector>

struct EntityManager;
struct World;

struct Avatar {
    void* VFTable;
    unsigned int ref;
    unsigned int unk_0;
    unsigned int unk_1;
    unsigned int unk_2;
    unsigned int Parent;
    unsigned int FirstChild;
    unsigned int LastChild;
    unsigned int NextSibling;
    unsigned int DialogManager;
    unsigned int unk_8;
    unsigned int unk_9;
    unsigned int VFTableIEventHandler;
    unsigned int unk_11;
    unsigned int unk_12;
    unsigned int VFTableEventSystem;
    unsigned int unk_14;
    unsigned int unk_15;
    unsigned int unk_16;
    unsigned int unk_17;
    unsigned int unk_18;
    unsigned int AnotherAvatar;
    unsigned int unk_20;
    unsigned int AvatarDesc;
    unsigned int unk_22;
    unsigned int unk_23;
    unsigned int VFTableNativeAvatar;
    unsigned int unk_25;
    unsigned int unk_26;
    unsigned int unk_27;
    unsigned int unk_28;
    unsigned int unk_29;
    unsigned int unk_30;
    unsigned int unk_31;
    EntityManager* EntityManager;
    unsigned int unk_33;
    unsigned int unk_34;
    unsigned int posX_maybe;
    unsigned int posY_maybe;
    unsigned int posZ_maybe;
    unsigned int unk_35;
    World* World;
    unsigned int unk_37;
    unsigned int unk_38;
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
