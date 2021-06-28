//
// Created by Sophie on 28/06/2021.
//

#ifndef RRSPY2TESTAPP_MELEEWEAPON_H
#define RRSPY2TESTAPP_MELEEWEAPON_H


#include "../../datatypes/DRString.h"

struct GCClass;

struct MeleeWeapon {
    int VFTable;
    int Ref;
    int Unk2; // 0x8
    int Unk3; // 0xc
    int Unk4; // 0x10
    int Unk5; // 0x14
    int Unk6; // 0x18
    int Unk7; // 0x1c
    int Unk8; // 0x20
    int Unk9; // 0x24
    int Unk10; // 0x28
    int Unk11; // 0x2c
    int Unk12; // 0x30
    int Unk13; // 0x34
    int Unk14; // 0x38
    int Unk15; // 0x3c
    int Unk16; // 0x40
    int Unk17; // 0x44
    int Unk18; // 0x48
    int Unk19; // 0x4c
    int Unk20; // 0x50
    int Unk21; // 0x54
    GCClass* GCClass; // 0x58
    int Unk23; // 0x5c
    int Unk24; // 0x60
    int Unk25; // 0x64
    int Unk26; // 0x68
    int Unk27; // 0x6c
    int Unk28; // 0x70
    int Unk29; // 0x74
    int Unk30; // 0x78
    int Unk31; // 0x7c
    int Unk32; // 0x80
    int Unk33; // 0x84
    int Unk34; // 0x88
    int Unk35; // 0x8c
    int Unk36; // 0x90
    int Unk37; // 0x94
    int Unk38; // 0x98
    int Unk39; // 0x9c
    int Unk40; // 0xa0
    int Unk41; // 0xa4
    int Unk42; // 0xa8
    int Unk43; // 0xac
    int Unk44; // 0xb0
    int Unk45; // 0xb4
    int Unk46; // 0xb8
    int Unk47; // 0xbc
    int Unk48; // 0xc0
    int Unk49; // 0xc4
};


#endif //RRSPY2TESTAPP_MELEEWEAPON_H
