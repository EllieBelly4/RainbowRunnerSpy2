//
// Created by Ellie on 28/12/2022.
//

#ifndef RRSPY2TESTAPP_DRVECTORTYPE_H
#define RRSPY2TESTAPP_DRVECTORTYPE_H

#include <string>
#include "DRFloat.h"

struct DRVectorType {
public:
    DRFloat X;
    DRFloat Y;
    DRFloat Z;

    std::string to_string() const {
        return std::string(
                "X: " + std::to_string((float) X) +
                ", Y: " + std::to_string((float) Y) +
                ", Z: " +std::to_string((float) Z));
    }
};

#endif //RRSPY2TESTAPP_DRVECTORTYPE_H
