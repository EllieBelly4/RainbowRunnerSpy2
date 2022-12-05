//
// Created by Ellie on 05/12/2022.
//

#ifndef RRSPY2TESTAPP_DRFLOAT_H
#define RRSPY2TESTAPP_DRFLOAT_H

struct DRFloat {
    int value;

    explicit operator float() const {
        return ((float) value) / 256.0f;
    }
};

#endif //RRSPY2TESTAPP_DRFLOAT_H
