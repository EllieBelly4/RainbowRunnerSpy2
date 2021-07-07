//
// Created by Sophie on 27/06/2021.
//

#ifndef RRSPY2TESTAPP_CLIENTENTITYLIST_H
#define RRSPY2TESTAPP_CLIENTENTITYLIST_H

#include <vector>

// This is the entity type that is accessible through ClientEntityList::getEntities.
struct ClientEntityList {
    int Unk0;
    uintptr_t OwnedObjectsStart;
    uintptr_t OwnedObjectsEnd;
    uintptr_t OwnedObjectsEnd_2;
    int Unk4;
    int Unk5;
    int Unk6;
    int Unk7;
    int Unk8;
    int Unk9;
    int Unk10;
    int Unk11;
    int Unk12;
    int Unk13;
    int Unk14;
    int Unk15;
    int Unk16;
    int Unk17;
    int Unk18;
    int Unk19;
    int SomeTimer;
    int Unk21;
    int SomeCountAddedToCounter;
    int SomeCounter;
    int Unk24;
    int Unk25;
    int Unk26;
    int Unk27;
    int Unk28;
    int Unk29;
    int Unk30;
    int ProcessedMessagesThisMove;
    int UpdateMessagesInQueue;
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
};

std::vector<char*> GetClientEntityProperties();


#endif //RRSPY2TESTAPP_CLIENTENTITYLIST_H
