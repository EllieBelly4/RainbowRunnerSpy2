//
// Created by Sophie on 26/06/2021.
//

#include <iomanip>
#include "GameClientStateManager.h"

const char* GetStateString(GameClientStateManager* gcsm) {
    auto* str = new std::string();

    if (gcsm->State2 == 0x65) {
        *str = "Login Screen";
    } else if (gcsm->State2 == 0x66) {
        *str = "Character Selection";
    } else if (gcsm->State2 == 0x68) {
        *str = "Loading Screen";
    } else if (gcsm->State2 == 0x67) {
        *str = "In Game";
    } else {
        *str = "Unknown State";
    }

    return str->c_str();
}

std::vector<char*> GetGameClientStateManagerProperties(){
    static const std::vector<char*> properties {
            (char*) "VFTable",
            (char*) "Unk1",
            (char*) "Unk2",
            (char*) "FrameCount",
            (char*) "State1",
            (char*) "State2",
    };

    return properties;
}


//const char* GetGameClientStateManagerProperty(int i) {
//    if (i < 6) {
//        return GameClientStateManagerProperties[i];
//    }
//
//    return "";
//}