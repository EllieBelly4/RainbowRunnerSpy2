//
// Created by Sophie on 27/06/2021.
//

#ifndef RRSPY2TESTAPP_ENTITYMANAGER_H
#define RRSPY2TESTAPP_ENTITYMANAGER_H

#include <vector>
#include <string>
#include "EntityContainer.h"

struct World;

struct EntityManager {
    void* VFTable;
    int References;
    int Unk0;
    int Unk1;
    int Unk2;
    World* World;
    int Unk4;
    int Unk5;
    int Unk6;
    int Unk7;
    int Unk8;
    int Unk9;
    void* EventSystemVFTable;
    int Unk11;
    int Unk12;
    int Unk13;
    int Unk14;
    void* LinkBufferVFTable;
    int Unk16;
    int Unk17;
    int Unk18;
    int Unk19;
    int Unk20;
    int Unk21;
    int Unk22;
    int Unk23;
    int Unk24;
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
};

struct ClientEntityManager {
    //157CA748
    //157CB184
    // +0xA3C

    void* VFTable;
    int References;
    int Unk0;
    int Unk1;
    int Unk2;
    World* World;
    int Unk4;
    int Unk5;
    int Unk6;
    int SoundEnvironment;
    int Unk8;
    int Unk9;
    void* EventSystemVFTable;
    int Unk11;
    int Unk12;
    int SomeMap;
    int Unk14;
    void* LinkBufferVFTable;
    int Unk16;
    int Unk17;
    int Unk18;
    int Unk19;
    std::byte Unk[0x9C0];

    unsigned int unk_20;
    unsigned int unk_21;
    unsigned int unk_22;
    unsigned int unk_23;
    unsigned int unk_24;
    unsigned int unk_25;
    unsigned int ManagerChannel;
    unsigned int unk_27;
    unsigned int unk_28;
    EntityContainer EntityList;
    EntityContainer ComponentList;
//    int unk_33;
//    int unk_34;
//    int unk_35;
//    int unk_36;
//    int unk_37;
//    int unk_38;
//    int unk_39;
//    int unk_40;
//    int unk_41;
    int SomeTimer;
    int unk_42;
    int SomeCountAddedToCounter;
    int SomeCounter;
    int unk_43;
    int unk_44;
    int unk_45;
    int unk_46;
    int unk_47;
    int unk_48;
    int unk_49;
    int ProcessedMessagesThisMove;
    int UpdateMessagesInQueue;
    int unk_50;
    int unk_51;
    int unk_52;
    int unk_53;
    int unk_54;
    int unk_55;
    int unk_56;
    int unk_57;
    int unk_58;
    int unk_59;
    int unk_60;
    int unk_61;
    int unk_62;
    int unk_63;
    int unk_64;
    int unk_65;
    int unk_66;
    int unk_67;
    int unk_68;
    int unk_69;
    int unk_70;
    int unk_71;
    int unk_72;
    int unk_73;
    int unk_74;
    int unk_75;

    //debug442:157CB160     dd 0
    //debug442:157CB164     dd 0BAADF00Dh
    //debug442:157CB168     dd offset off_157DC350
    //debug442:157CB16C     dd 0
    //debug442:157CB170     dd 0BAADF00Dh
    //debug442:157CB174     dd 0BAADF00Dh
    //debug442:157CB178     dd offset off_8BCE778
    //debug442:157CB17C     dd 0
    //debug442:157CB180     dd 0BAADF00Dh
    //debug442:157CB184     dd offset off_157D5E90
    //debug442:157CB188     dd offset dword_157D5E98
    //debug442:157CB18C     dd offset dword_157D5E98
    //debug442:157CB190     dd 0BAADF00Dh
    //debug442:157CB194     dd 0BAADF00Dh
    //debug442:157CB198     dd offset off_157DCCE0
    //debug442:157CB19C     dd 2
    //debug442:157CB1A0     dd 0BAADF00Dh
    //debug442:157CB1A4     dd 0BAADF00Dh
    //debug442:157CB1A8     dd offset off_157EE348
    //debug442:157CB1AC     dd offset unk_157EE368
    //debug442:157CB1B0     dd offset unk_157EE36C
    //debug442:157CB1B4     dd 0BAADF00Dh
    //debug442:157CB1B8     dd 0BAADF00Dh
    //debug442:157CB1BC     dd offset off_157CA6A8
    //debug442:157CB1C0     dd 8
    //debug442:157CB1C4     dd 0BAADF00Dh
    //debug442:157CB1C8     dd 21h
    //debug442:157CB1CC     dd 0Bh
    //debug442:157CB1D0     dd 44934C28h
    //debug442:157CB1D4     dd 19h
    //debug442:157CB1D8     dd 0Bh
    //debug442:157CB1DC     dd 6D8h
    //debug442:157CB1E0     dd 0BAAD0101h
    //debug442:157CB1E4     off_157CB1E4 dd offset off_157CA170     ; DATA XREF: debug442:off_157CA170↑o
    //debug442:157CB1E8     dd 0BAADF00Dh
    //debug442:157CB1EC     dd 0BAADF00Dh
    //debug442:157CB1F0     dd 0BAADF00Dh
    //debug442:157CB1F4     dd offset unk_157D1328
    //debug442:157CB1F8     dd 8
    //debug442:157CB1FC     dd 0
    //debug442:157CB200     dd 0
    //debug442:157CB204     dd offset unk_FC201
    //debug442:157CB208     dd 0BAADF000h
    //debug442:157CB20C     dd 0ABABABABh
    //debug442:157CB210     dd 0ABABABABh
    //debug442:157CB214     dd 0FEEEFEEEh
    //debug442:157CB218     dd 0
    //debug442:157CB21C     dd 0
    //debug442:157CB220     dd 0AB5E7EF0h
    //debug442:157CB224     dd 1C72C7D0h
    //debug442:157CB228     dd offset ??_7dx3DEffect@@6B@           ; const dx3DEffect::`vftable'
    //debug442:157CB22C     dd 1
    //debug442:157CB230     dd 0BAADF00Dh
    //debug442:157CB234     dd 0BAADF00Dh
    //debug442:157CB238     dd 0
    //debug442:157CB23C     dd offset unk_157C8C70
    //debug442:157CB240     dd offset unk_157DC170
    //debug442:157CB244     dd offset unk_EB7FFE8
    //debug442:157CB248     dd 0BAADF000h
    //debug442:157CB24C     dd 0BAADF00Dh
    //debug442:157CB250     dd 0
    //debug442:157CB254     dd 0
    //debug442:157CB258     dd 0
};

std::vector<char*> GetEntityManagerProperties();
std::vector<char*> GetClientEntityManagerProperties();

std::string GetEntityManagerTypeName(EntityManager* entityManager);


#endif //RRSPY2TESTAPP_ENTITYMANAGER_H
