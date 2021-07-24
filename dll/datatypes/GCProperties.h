//
// Created by Sophie on 30/06/2021.
//

#ifndef RRSPY2TESTAPP_GCPROPERTIES_H
#define RRSPY2TESTAPP_GCPROPERTIES_H

#include <vector>
#include <string>

class GCProperties {
public:
    unsigned int Unk0;
    void* Unk1;
    unsigned int Unk2;
    unsigned int Unk3;
    unsigned int Unk4;
    unsigned int Unk5;
    unsigned int Unk6;
    unsigned int Unk7;
    unsigned int Unk8;
    unsigned int Unk9;
};

const std::vector<char*> GetGCPropertiesProperties();

#endif //RRSPY2TESTAPP_GCPROPERTIES_H
