//
// Created by Sophie on 26/06/2021.
//

#include "World.h"

std::vector<char*> GetWorldProperties(){
    static const std::vector<char*> properties {
            (char*) "VFTable",
            (char*) "References",
    };

    return properties;
}
