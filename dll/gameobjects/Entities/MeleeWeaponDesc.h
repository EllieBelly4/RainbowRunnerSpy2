//
// Created by Sophie on 01/07/2021.
//

#ifndef RRSPY2TESTAPP_MELEEWEAPONDESC_H
#define RRSPY2TESTAPP_MELEEWEAPONDESC_H

#include "DFCNode.h"

class MeleeWeaponDesc : public DFCNode {
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
    int Unk50; // 0xc8
    short Unk51; // 0xcc
    short Unk52; // 0xcd
    short Unk53; // 0xce
    short WeaponTypeFlags_mb; // 0xcf Flag | 0x04 = isEquippable
};


#endif //RRSPY2TESTAPP_MELEEWEAPONDESC_H
