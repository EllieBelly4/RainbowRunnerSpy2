//
// Created by Sophie on 27/06/2021.
//

#include "Avatar.h"

const std::vector<char*> GetAvatarProperties() {
    static const std::vector<char*> properties{
            (char*) "vftable",
            (char*) "ref",
            (char*) "unk_0",
            (char*) "unk_1",
            (char*) "unk_2",
            (char*) "Parent",
            (char*) "FirstChild",
            (char*) "LastChild",
            (char*) "NextSibling",
            (char*) "DialogManager",
            (char*) "unk_8",
            (char*) "unk_9",
            (char*) "VFTableIEventHandler",
            (char*) "unk_11",
            (char*) "unk_12",
            (char*) "VFTableEventSystem",
            (char*) "unk_14",
            (char*) "unk_15",
            (char*) "unk_16",
            (char*) "unk_17",
            (char*) "unk_18",
            (char*) "AnotherAvatar",
            (char*) "unk_20",
            (char*) "AvatarDesc",
            (char*) "unk_22",
            (char*) "unk_23",
            (char*) "VFTableNativeAvatar",
            (char*) "unk_25",
            (char*) "unk_26",
            (char*) "unk_27",
            (char*) "unk_28",
            (char*) "unk_29",
            (char*) "unk_30",
            (char*) "unk_31",
            (char*) "EntityManager",
            (char*) "unk_33",
            (char*) "unk_34",
            (char*) "posX_maybe",
            (char*) "posY_maybe",
            (char*) "posZ_maybe",
            (char*) "unk_35",
            (char*) "World",
            (char*) "unk_37",
            (char*) "unk_38",
            (char*) "EntityObject",
            (char*) "unk_40",
            (char*) "EntityObject2",
            (char*) "SomeState",
            (char*) "unk_42",
            (char*) "SomeState2",
            (char*) "unk_44",
            (char*) "unk_45",
            (char*) "unk_46",
            (char*) "unk_47",
            (char*) "unk_48",
            (char*) "unk_49",
            (char*) "unk_50",
    };

    return properties;
}

std::string Avatar::DoSomething() {
    return "something";
}
