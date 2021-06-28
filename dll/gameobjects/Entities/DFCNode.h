//
// Created by Sophie on 28/06/2021.
//

#ifndef RRSPY2TESTAPP_DFCNODE_H
#define RRSPY2TESTAPP_DFCNODE_H

#include <vector>
#include <string>

struct GCClass;

struct DFCNode {
    void* VFTable;
    unsigned int ref;
    unsigned int unk_0; // 0x8
    unsigned int unk_1; // 0xc
    unsigned int unk_2; // 0x10
    unsigned int Parent; // 0x14
    unsigned int FirstChild; // 0x18
    unsigned int LastChild; // 0x1c
    unsigned int NextSibling; // 0x20
    unsigned int unk_7; // 0x24
    unsigned int unk_8; // 0x28
    unsigned int unk_9; // 0x2c
    unsigned int unk_10; // 0x30
    unsigned int unk_11; // 0x34
    unsigned int unk_12; // 0x38
    unsigned int unk_13; // 0x3c
    unsigned int unk_14; // 0x40
    unsigned int unk_15; // 0x44
    unsigned int unk_16; // 0x48
    unsigned int unk_17; // 0x4c
    unsigned int unk_18; // 0x50
    DFCNode* SuperClass; // 0x54
    GCClass* GCClass; // 0x58
    DFCNode* Desc; // 0x5c
    unsigned int unk_22; // 0x60
    unsigned int unk_23; // 0x64
    unsigned int unk_24; // 0x68
    unsigned int unk_25; // 0x6c
    unsigned int unk_26; // 0x70
    unsigned int unk_27; // 0x74
    unsigned int unk_28; // 0x78
    unsigned int unk_29; // 0x7c
    unsigned int unk_30; // 0x80
    unsigned int unk_31; // 0x84
    unsigned int unk_32; // 0x88
    unsigned int unk_33; // 0x8c
    unsigned int unk_34; // 0x90
    unsigned int unk_35; // 0x94
    unsigned int unk_36; // 0x98
    unsigned int unk_37; // 0x9c
    unsigned int unk_38; // 0xa0
    unsigned int unk_39; // 0xa4
    unsigned int unk_40; // 0xa8
    unsigned int unk_41; // 0xac

    std::string GetTypeString();
};

const std::vector<char*> GetEntityProperties();

#endif