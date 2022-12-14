//
// Created by Ellie on 04/12/2022.
//

#ifndef RRSPY2TESTAPP_PATHMANAGER_H
#define RRSPY2TESTAPP_PATHMANAGER_H


/*
   This file has been generated by IDA.
   It contains local type definitions from
   the type library 'DungeonRunners.exe'
*/

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

struct PathMap;
struct World;

/* 3600 */
struct PathManager {
    void *vtable;
    void *field_4;
    void *field_8;
    void *field_C;
    World *world;
    PathMap *path_map;
    void *world_collision_helper;
    void *field_1C;
    void *unk_budget_related;
    void *field_24;
    void *field_28;
    void *field_2C;
    void *field_30;
    void *field_34;
    void *field_38;
    void *field_3C;
    void *field_40;
    void *field_44;
    void *field_48;
    void *field_4C;
    void *field_50;
    void *budget_per_update;
    void *field_58;
    void *field_5C;
    void *budget_per_path;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
};


#endif //RRSPY2TESTAPP_PATHMANAGER_H
