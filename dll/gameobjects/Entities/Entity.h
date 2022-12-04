//
// Created by Sophie on 06/07/2021.
//

#ifndef RRSPY2TESTAPP_ENTITY_H
#define RRSPY2TESTAPP_ENTITY_H


#include "DFCNode.h"

class Entity : DFCNode {
public:
	void* VFTable; // 0x6c
	unsigned int unk_00; // 0x68
    unsigned int unk_26; // 0x70
    unsigned int unk_27; // 0x74
    unsigned int unk_28; // 0x78
    unsigned short unk_29; // 0x7c
    unsigned short unk_30; // 0x7e
    unsigned short unk_31; // 0x80
    unsigned short unk_32; // 0x82
    unsigned int unk_33; // 0x84
    struct EntityManager* EntityManager; // 0x88
    unsigned int unk_34; // 0x8c
    int posX_maybe; // 0x90
    int posY_maybe; // 0x94
    int posZ_maybe; // 0x98
    unsigned int rotation; // 0x9c
    unsigned int worldEntityFlags; // 0xa0
    struct World* World; // 0xa4
    unsigned int ID; // 0xa8
    unsigned int unk_38; // 0xac
    unsigned int EntityObject; // 0xb0
    unsigned int unk_40; // 0xb4
};


#endif //RRSPY2TESTAPP_ENTITY_H
