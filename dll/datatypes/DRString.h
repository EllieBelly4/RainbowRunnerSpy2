//
// Created by Sophie on 27/06/2021.
//

#ifndef RRSPY2TESTAPP_DRSTRING_H
#define RRSPY2TESTAPP_DRSTRING_H

#include <string>

#pragma pack(push, 1)
struct DRString {
    int Length;
    // Just make this as long as the longest posssible string
    char String[128];

    std::string ToString();
};

#pragma pack(pop)

#endif //RRSPY2TESTAPP_DRSTRING_H
