//
// Created by Sophie on 26/06/2021.
//

#ifndef RRSPY2TESTAPP_GAMECLIENTSTATEMANAGER_H
#define RRSPY2TESTAPP_GAMECLIENTSTATEMANAGER_H

#include <vector>

class GameClientStateManager {
public:
    void* VFTable; // 0x0 void* VFTable;
    void* field_4; // 0x4 int Unk1;
    int field_8; // 0x8 int Unk2;
    int CurrentFrame; // 0xc int CurrentFrame;
    __int16 State0; // 0x10 int State1;
    __int16 State1; // 0x12
    __int16 State2; // 0x14 int State2;
    __int16 State3; // 0x16
    char field_18; // 0x18
    char field_19[7];//0x19
    int IEventHandlerVFTable; //
    int SomeMap; //
    std::byte gap28[4];
    int field_2C; //
    int field_30; //
    int field_34; //
    void* UpdatingText; //
    void* CheckingForUpdatesText; //
    void* field_40; //
    void* field_44; //
    void* field_48; //
    void* field_4C; //
    GameClientStateManager* field_50; //
    void* WorldUI; //
    void* WorldUIBanner; //
    void* LoadingScreen; //
    void* GatewayClient; //
    void* ZoneClient; //
    std::byte gap68[8]; //
    void* SomeMap2; //
    int field_74; //
    std::byte gap78[4]; //
    char field_7C; //
    char field_7D; //
    char field_7E; //
    char field_7F; //
    int field_80; //
};

extern std::vector<char*> GetGameClientStateManagerProperties();

const char* GetStateString(GameClientStateManager*);

#endif //RRSPY2TESTAPP_GAMECLIENTSTATEMANAGER_H
