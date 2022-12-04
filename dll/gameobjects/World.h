//
// Created by Sophie on 26/06/2021.
//

#ifndef RRSPY2TESTAPP_WORLD_H
#define RRSPY2TESTAPP_WORLD_H

#include <vector>
#include <string>
#include "../datatypes/DRString.h"
#include "gameobjects/Entities/DFCNode.h"

struct EntityManager;
struct PathManager;

struct World : DFCNode {
    DRString *MapName; // 0x6c
    unsigned int unk_25; // 0x70
    unsigned int unk_26; // 0x74
    unsigned int unk_27; // 0x78
    unsigned int unk_28; // 0x7c
    unsigned int unk_29; // 0x80
    unsigned int unk_30; // 0x84
    unsigned int unk_31; // 0x88
    unsigned int unk_32; // 0x8c
    unsigned int unk_33; // 0x90
    unsigned int unk_34;  // 0x94
    unsigned int unk_35;  // 0x98
    unsigned int unk_36;  // 0x9c
    unsigned int unk_37;  // 0xa0
    unsigned int unk_38;  // 0xa4
    unsigned int unk_39;  // 0xa8
    unsigned int unk_40;  // 0xac
    unsigned int unk_41;  // 0xb0
    unsigned int unk_42;  // 0xb4
    unsigned int unk_43;  // 0xb8
    unsigned int unk_44;  // 0xbc
    unsigned int unk_45;  // 0xc0
    unsigned int unk_46;  // 0xc4
    unsigned int unk_47;  // 0xc8
    unsigned int unk_48;  // 0xcc
    unsigned int unk_49;  // 0xd0
    unsigned int unk_50;  // 0xd4
    unsigned int unk_51;  // 0xd8
    unsigned int unk_52;  // 0xdc
    unsigned int unk_53;  // 0xe0
    unsigned int unk_54;  // 0xe4
    unsigned int unk_55;  // 0xe8
    unsigned int unk_56;  // 0xec
    unsigned int unk_57;  // 0xf0
    unsigned int unk_57_5;  // 0xf4
    EntityManager *EntityManager;  // 0xf8
    char *world_scene_manager;  // 0xfc
    char *world_collision_manager;  // 0x100
    char *world_collision_helper;  // 0x104
    PathManager *path_manager;  // 0x108
    char *unit_finder;  // 0x10c
    char *gcobject_0;  // 0x110
    char *gcobject_1;  // 0x114
    char *worldmap;  // 0x118
    char *zonedef;  // 0x11c
    unsigned int unk_68;  // 0x120
    unsigned int unk_69;  // 0x124
    unsigned int unk_70;  // 0x128
    unsigned int unk_71;  // 0x12c
    unsigned int unk_72;  // 0x130
    unsigned int unk_73;  // 0x134
    unsigned int unk_74;  // 0x138
    unsigned int unk_75;  // 0x13c
    unsigned int unk_76;  // 0x140
    unsigned int unk_77;  // 0x144
    unsigned int unk_78;  // 0x148
    unsigned int unk_79;  // 0x14c
    unsigned int unk_80;  // 0x150
    unsigned int unk_81;  // 0x154
    unsigned int unk_82;  // 0x158
    unsigned int unk_83;  // 0x15c
    unsigned int unk_84;  // 0x160
    unsigned int unk_85;  // 0x164
    unsigned int unk_86;  // 0x168
    unsigned int unk_87;  // 0x16c
    unsigned int unk_88;  // 0x170
    unsigned int unk_89;  // 0x174
    unsigned int unk_90;  // 0x178
    unsigned int unk_91;  // 0x17c
    unsigned int unk_92;  // 0x180
    unsigned int unk_93;  // 0x184
    unsigned int unk_94;  // 0x188
    unsigned int unk_95;  // 0x18c
    unsigned int unk_96;  // 0x190
};

//extern World* CurrentWorld;

std::vector<char *> GetWorldProperties();

#endif //RRSPY2TESTAPP_WORLD_H
