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

struct World : DFCNode {
    	DRString* MapName;
    	int Unk25;
    	int Unk26;
    	int Unk27;
    	int Unk28;
    	int Unk29;
    	int Unk30;
    	int Unk31;
    	int Unk32;
    	int Unk33;
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
    	int Unk51;
    	int Unk52;
    	int Unk53;
    	int Unk54;
    	int Unk55;
    	int Unk56;
    	int Unk57;
    	int Unk58;

    EntityManager* EntityManager = nullptr;
};

//extern World* CurrentWorld;

std::vector<char*> GetWorldProperties();

#endif //RRSPY2TESTAPP_WORLD_H
