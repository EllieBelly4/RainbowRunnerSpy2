//
// Created by Ellie on 04/12/2022.
//

#ifndef RRSPY2TESTAPP_PATHMAP_H
#define RRSPY2TESTAPP_PATHMAP_H


#include "datatypes/DRFloat.h"

struct PathNode;

/* 3604 */
struct PathMap {
    void *vtable;
    int field_4;
    int field_8;
    int field_C;
    void *world;
    void *world_collision_manager;
    DRFloat grid_tile_width;
    int field_1C;
    int field_20;
    DRFloat grid_tile_height;
    int coord_limit_x;
    int coord_limit_y;
    int field_30;
    int field_34;
    int field_38;
    void *aNsemanagerL110;
    void *anonymous_0;
    void *anonymous_1;
    int width;
    int height;
    int node_count;
    PathNode *(*nodes);
    int field_58;
    int field_5C;
};

#endif //RRSPY2TESTAPP_PATHMAP_H
