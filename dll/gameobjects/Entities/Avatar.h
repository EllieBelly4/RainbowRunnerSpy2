//
// Created by Sophie on 27/06/2021.
//

#ifndef RRSPY2TESTAPP_PLAYER_H
#define RRSPY2TESTAPP_PLAYER_H

#include <string>
#include <vector>

struct Avatar {
    void* VFTable;
    unsigned int ref;
    unsigned int unk_0;
    unsigned int unk_1;
    unsigned int unk_2;
    unsigned int unk_3;
    unsigned int unk_4;
    unsigned int unk_5;
    unsigned int unk_6;
    unsigned int unk_7;
    unsigned int unk_8;
    unsigned int unk_9;
    unsigned int unk_10;
    unsigned int unk_11;
    unsigned int unk_12;
    unsigned int unk_13;
    unsigned int unk_14;
    unsigned int unk_15;
    unsigned int unk_16;
    unsigned int unk_17;
    unsigned int unk_18;
    unsigned int unk_19;
    unsigned int unk_20;
    unsigned int unk_21;
    unsigned int unk_22;
    unsigned int unk_23;
    unsigned int unk_24;
    unsigned int unk_25;
    unsigned int unk_26;
    unsigned int unk_27;
    unsigned int unk_28;
    unsigned int unk_29;
    unsigned int unk_30;
    unsigned int unk_31;
    unsigned int unk_32;
    unsigned int unk_33;
    unsigned int unk_34;
    unsigned int posX_maybe;
    unsigned int posY_maybe;
    unsigned int posZ_maybe;
    unsigned int unk_35;
    unsigned int unk_36;
    unsigned int unk_37;
    unsigned int unk_38;
    unsigned int unk_39;
    unsigned int unk_40;
    unsigned int unk_41;

    std::string DoSomething();
};

const std::vector<char*> GetAvatarProperties();

#endif //RRSPY2TESTAPP_PLAYER_H
