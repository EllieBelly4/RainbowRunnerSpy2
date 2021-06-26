//
// Created by Sophie on 26/06/2021.
//

#ifndef RRSPY2TESTAPP_GAMECLIENTSTATEMANAGER_H
#define RRSPY2TESTAPP_GAMECLIENTSTATEMANAGER_H


#pragma pack(1)
struct GameClientStateManager {
    int Unk0;
    int Unk1;
    int Unk2;
    int SomeTimer;
    int State1;
    int State2;
};

const char* GetStateString(GameClientStateManager*);
const char* GetGameClientStateManagerProperty(int i);

#endif //RRSPY2TESTAPP_GAMECLIENTSTATEMANAGER_H
