//
// Created by Sophie on 26/06/2021.
//

#include <iomanip>
#include "GameClientStateManager.h"

const char* GetStateString(GameClientStateManager* gcsm) {
    std::string* str = new std::string();

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

const char* GetGameClientStateManagerProperty(int i) {
    const char* properties[6] = {
            "Unk0",
            "Unk1",
            "Unk2",
            "SomeTimer",
            "State1",
            "State2",
    };

    if (i < 6) {
        return properties[i];
    }

    return "";
}