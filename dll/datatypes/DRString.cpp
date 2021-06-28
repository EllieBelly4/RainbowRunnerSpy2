//
// Created by Sophie on 27/06/2021.
//

#include "DRString.h"

std::string DRString::ToString() {
    char* addr = String;

    std::string strName;

    for (int i = 0; i < Length; ++i) {
        strName += *(addr + i);
    }

    return strName;
}
