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
    int unk_42;
    int SystemTime;
    int FrameThisSecond;
    int TicksWithoutServerResponse;
    int ServerTick;
    int unk_44;
    int unk_45;
    int unk_46;
    int unk_47;
    int unk_48;
    int unk_49;
    // This value increases over time by an amount of 1 -> , but the time between updates and the value increases exponentially
    int unk_increases_slowly;
    int ProcessedMessagesThisMove;
    int UpdateMessagesInQueue;
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
	unsigned int unk_76;
	unsigned int unk_77;
	unsigned int unk_78;
	unsigned int unk_79;
	unsigned int unk_80;
	unsigned int unk_81;
	unsigned int unk_82;
	unsigned int unk_83;
	unsigned int unk_84;
	unsigned int unk_85;
	unsigned int unk_86;
	unsigned int unk_87;
	unsigned int unk_88;
	unsigned int unk_89;
	unsigned int unk_90;
	unsigned int unk_91;
	unsigned int unk_92;
	unsigned int unk_93;
	unsigned int unk_94;
	unsigned int unk_95;
	unsigned int unk_96;
	unsigned int unk_97;
	unsigned int unk_98;
	unsigned int unk_100;
	unsigned int unk_101;
	unsigned int unk_102;
	unsigned int unk_103;
	unsigned int unk_104;
	unsigned int unk_105;
	unsigned int unk_106;
	unsigned int unk_107;
	unsigned int unk_108;
	unsigned int unk_109;
	unsigned int unk_110;
	unsigned int unk_111;
	unsigned int unk_112;
	unsigned int unk_113;
	unsigned int unk_114;
	unsigned int unk_115;
	unsigned int unk_116;
	unsigned int unk_117;
	unsigned int unk_118;
	unsigned int unk_119;
	unsigned int unk_120;
	unsigned int unk_121;
	unsigned int unk_122;
	unsigned int unk_123;
	unsigned int unk_124;
	unsigned int unk_125;
};

std::vector<char*> GetEntityManagerProperties();

std::vector<char*> GetClientEntityManagerProperties();

std::string GetEntityManagerTypeName(EntityManager* entityManager);


#endif //RRSPY2TESTAPP_ENTITYMANAGER_H
