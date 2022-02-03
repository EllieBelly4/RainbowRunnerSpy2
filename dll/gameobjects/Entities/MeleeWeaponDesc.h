//
// Created by Sophie on 01/07/2021.
//

#ifndef RRSPY2TESTAPP_MELEEWEAPONDESC_H
#define RRSPY2TESTAPP_MELEEWEAPONDESC_H

#include "DFCNode.h"

class MeleeWeaponDesc : public DFCNode {
	unsigned int unk_00; // 0x68
	int Unk34;
    int Unk35;
    int Unk36;
    int Unk37;
    int Unk38;
    int Unk39;
    int Unk40;
    int Unk41;
    int Unk42;
    int Unk43;
    int Unk44;
    int Unk45;
    int Unk46;
    int Unk47;
    int Unk48;
    int Unk49;
    int Unk50;
    short Unk51;
    short Unk52;
    short Unk53;
    short WeaponTypeFlags_mb; // 0xcf Flag | 0x04 = isEquippable
};


#endif //RRSPY2TESTAPP_MELEEWEAPONDESC_H
