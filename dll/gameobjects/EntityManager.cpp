//
// Created by Sophie on 27/06/2021.
//

#include <string>
#include "../common.h"
#include "EntityManager.h"

std::vector<char*> GetEntityManagerProperties() {
    static const std::vector<char*> properties{
            (char*) "VFTable",
            (char*) "References",
            (char*) "Unk0",
            (char*) "Unk1",
            (char*) "Unk2",
            (char*) "World",
            (char*) "Unk4",
            (char*) "Unk5",
            (char*) "Unk6",
            (char*) "Unk7",
            (char*) "Unk8",
            (char*) "Unk9",
            (char*) "EventSystemVFTable",
            (char*) "Unk11",
            (char*) "Unk12",
            (char*) "Unk13",
            (char*) "Unk14",
            (char*) "LinkBufferVFTable",
            (char*) "Unk16",
            (char*) "Unk17",
            (char*) "Unk18",
            (char*) "Unk19",
            (char*) "Unk20",
            (char*) "Unk21",
            (char*) "Unk22",
            (char*) "Unk23",
            (char*) "Unk24",
            (char*) "Unk25",
            (char*) "Unk26",
            (char*) "Unk27",
            (char*) "Unk28",
            (char*) "Unk29",
            (char*) "Unk30",
            (char*) "Unk31",
            (char*) "Unk32",
            (char*) "Unk33",
            (char*) "Unk34",
            (char*) "Unk35",
            (char*) "Unk36",
            (char*) "Unk37",
            (char*) "Unk38",
            (char*) "Unk39",
            (char*) "Unk40",
            (char*) "Unk41",
            (char*) "Unk42",
            (char*) "Unk43",
            (char*) "Unk44",
            (char*) "Unk45",
            (char*) "Unk46",
            (char*) "Unk47",
            (char*) "Unk48",
            (char*) "Unk49",
            (char*) "Unk50",
            (char*) "Unk51",
            (char*) "Unk52",
            (char*) "Unk53",
            (char*) "Unk54",
            (char*) "Unk55",
            (char*) "Unk56",
            (char*) "Unk57",
            (char*) "Unk58",
            (char*) "Unk59",
    };

    return properties;
}

std::vector<char*> GetClientEntityManagerProperties() {
    static const std::vector<char*> properties{
            (char*) "VFTable",
            (char*) "References",
            (char*) "Unk0",
            (char*) "Unk1",
            (char*) "Unk2",
            (char*) "World",
            (char*) "Unk4",
            (char*) "Unk5",
            (char*) "Unk6",
            (char*) "Unk7",
            (char*) "Unk8",
            (char*) "Unk9",
            (char*) "EventSystemVFTable",
            (char*) "Unk11",
            (char*) "Unk12",
            (char*) "Unk13",
            (char*) "Unk14",
            (char*) "LinkBufferVFTable",
            (char*) "Unk16",
            (char*) "Unk17",
            (char*) "Unk18",
            (char*) "Unk19",
            (char*) "Unk20",
            (char*) "Unk21",
            (char*) "Unk22",
            (char*) "Unk23",
            (char*) "Unk24",
            (char*) "Unk25",
            (char*) "Unk26",
            (char*) "Unk27",
            (char*) "Unk28",
            (char*) "Unk29",
            (char*) "Unk30",
            (char*) "Unk31",
            (char*) "Unk32",
            (char*) "Unk33",
            (char*) "Unk34",
            (char*) "Unk35",
            (char*) "Unk36",
            (char*) "Unk37",
            (char*) "Unk38",
            (char*) "Unk39",
            (char*) "Unk40",
            (char*) "Unk41",
            (char*) "Unk42",
            (char*) "Unk43",
            (char*) "Unk44",
            (char*) "Unk45",
            (char*) "Unk46",
            (char*) "Unk47",
            (char*) "Unk48",
            (char*) "Unk49",
            (char*) "Unk50",
            (char*) "Unk51",
            (char*) "Unk52",
            (char*) "Unk53",
            (char*) "Unk54",
            (char*) "Unk55",
            (char*) "Unk56",
            (char*) "Unk57",
            (char*) "Unk58",
            (char*) "Unk59",
    };

    return properties;
}

std::string GetEntityManagerTypeName(EntityManager* entityManager) {
    if (IsBadReadPtr(entityManager)){
        return "Null";
    }

    switch ((int) entityManager->VFTable) {
        case 0x008a8040:
            return "ServerEntityManager";
        case 0x008A7C18:
            return "ClientEntityManager";
        default:
            return "Unknown";
    }
}