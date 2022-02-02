//
// Created by Sophie on 28/06/2021.
//

#ifndef RRSPY2TESTAPP_GCCLASS_H
#define RRSPY2TESTAPP_GCCLASS_H

#include <vector>
#include <string>

#include "../../datatypes/DRString.h"

struct GCClass {
    int VFTable;
    int Ref;
    int Unk2; // 0x8
    int Unk3; // 0xc
    int GCTypeHash; // 0x10
    DRString* TypeName; // 0x14
    DRString* FQTypeName; // 0x18
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
    int Unk22; // 0x58
    int Unk23; // 0x5c
};

std::vector<char*> GetGCCLassProperties();

#endif //RRSPY2TESTAPP_GCCLASS_H
