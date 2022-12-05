//
// Created by Ellie on 05/12/2022.
//

#ifndef RRSPY2TESTAPP_PATHNODE_H
#define RRSPY2TESTAPP_PATHNODE_H


#include "DRFloat.h"

// Size 0x18
struct PathNode {
    DRFloat x_coord;
    DRFloat y_coord;
    DRFloat global_x_coord;
    DRFloat global_y_coord;
    char* unk_0;
    char* unk_1;
    char* unk_2;
};


#endif //RRSPY2TESTAPP_PATHNODE_H
