//
// Created by Sophie on 06/07/2021.
//

#include "WorldView.h"
#include <gameobjects/World.h>
#include "DFCNodeView.h"
#include "gameobjects/Entities/StaticObject.h"

void WorldView::RenderProperties(World *pEntity) {
    if (BeginFullPropertyTable("world")) {
        if (!IsBadReadPtr(pEntity->MapName)) {
            RenderProperty("MapName", pEntity->MapName->ToString());
        } else {
            RenderProperty("MapName", "Unknown");
        }

        ImGui::TableNextRow();

        RenderProperty("RootPos", pEntity->root_pos.to_string());

        ImGui::TableNextRow();

        RenderPropertyWithHex("unk_25", &pEntity->unk_25);
        RenderPropertyWithHex("unk_26", &pEntity->unk_26);
        RenderPropertyWithHex("unk_27", &pEntity->unk_27);
        RenderPropertyWithHex("unk_28", &pEntity->unk_28);
        RenderPropertyWithHex("unk_29", &pEntity->unk_29);
        RenderPropertyWithHex("unk_30", &pEntity->unk_30);
        RenderPropertyWithHex("unk_31", &pEntity->unk_31);
        RenderPropertyWithHex("unk_32", &pEntity->unk_32);
        RenderPropertyWithHex("unk_33", &pEntity->unk_33);
        RenderPropertyWithHex("unk_34", &pEntity->unk_34);
        RenderPropertyWithHex("unk_35", &pEntity->unk_35);
        RenderPropertyWithHex("unk_36", &pEntity->unk_36);
        RenderPropertyWithHex("unk_37", &pEntity->unk_37);
        RenderPropertyWithHex("unk_38", &pEntity->unk_38);
        RenderPropertyWithHex("unk_39", &pEntity->unk_39);
        RenderPropertyWithHex("unk_40", &pEntity->unk_40);
        RenderPropertyWithHex("unk_41", &pEntity->unk_41);
        RenderPropertyWithHex("unk_42", &pEntity->unk_42);
        RenderPropertyWithHex("unk_43", &pEntity->unk_43);
        RenderPropertyWithHex("unk_44", &pEntity->unk_44);
        RenderPropertyWithHex("unk_45", &pEntity->unk_45);
        RenderPropertyWithHex("unk_46", &pEntity->unk_46);
        RenderPropertyWithHex("unk_47", &pEntity->unk_47);
        RenderPropertyWithHex("unk_48", &pEntity->unk_48);
        RenderPropertyWithHex("unk_49", &pEntity->unk_49);
        RenderPropertyWithHex("unk_50", &pEntity->unk_50);
        RenderPropertyWithHex("unk_51", &pEntity->unk_51);
        RenderPropertyWithHex("unk_52", &pEntity->unk_52);
        RenderPropertyWithHex("unk_53", &pEntity->unk_53);
        RenderPropertyWithHex("unk_54", &pEntity->unk_54);
        RenderPropertyWithHex("unk_55", &pEntity->unk_55);
        RenderPropertyWithHex("unk_56", &pEntity->unk_56);
        RenderPropertyWithHex("unk_57", &pEntity->unk_57);
        RenderPropertyReference("EntityManager", &pEntity->EntityManager);
        RenderPropertyReference("world_scene_manager", &pEntity->world_scene_manager);
        RenderPropertyReference("world_collision_manager", &pEntity->world_collision_manager);
        RenderPropertyReference("world_collision_helper", &pEntity->world_collision_helper);
        RenderPropertyReference("path_manager", &pEntity->path_manager);
        RenderPropertyReference("unit_finder", &pEntity->unit_finder);
        RenderPropertyReference("gcobject_0", &pEntity->gcobject_0);
        RenderPropertyReference("gcobject_1", &pEntity->gcobject_1);
        RenderPropertyReference("worldmap", &pEntity->worldmap);
        RenderPropertyReference("zonedef", &pEntity->zonedef);
        RenderPropertyWithHex("unk_68", &pEntity->unk_68);
        RenderPropertyWithHex("unk_69", &pEntity->unk_69);
        RenderPropertyWithHex("unk_70", &pEntity->unk_70);
        RenderPropertyWithHex("unk_71", &pEntity->unk_71);
        RenderPropertyWithHex("unk_72", &pEntity->unk_72);
        RenderPropertyWithHex("unk_73", &pEntity->unk_73);
        RenderPropertyWithHex("unk_74", &pEntity->unk_74);
        RenderPropertyWithHex("root_pos.X", &pEntity->root_pos.X);
        RenderPropertyWithHex("root_pos.Y", &pEntity->root_pos.Y);
        RenderPropertyWithHex("root_pos.Z", &pEntity->root_pos.Z);
        RenderPropertyWithHex("unk_78", &pEntity->unk_78);
        RenderPropertyWithHex("unk_79", &pEntity->unk_79);
        RenderPropertyWithHex("unk_80", &pEntity->unk_80);
        RenderPropertyWithHex("unk_81", &pEntity->unk_81);
        RenderPropertyWithHex("unk_82", &pEntity->unk_82);
        RenderPropertyWithHex("unk_83", &pEntity->unk_83);
        RenderPropertyWithHex("unk_84", &pEntity->unk_84);
        RenderPropertyWithHex("unk_85", &pEntity->unk_85);
        RenderPropertyWithHex("unk_86", &pEntity->unk_86);
        RenderPropertyWithHex("unk_87", &pEntity->unk_87);
        RenderPropertyWithHex("unk_88", &pEntity->unk_88);
        RenderPropertyWithHex("unk_89", &pEntity->unk_89);
        RenderPropertyWithHex("unk_90", &pEntity->unk_90);
        RenderPropertyWithHex("unk_91", &pEntity->unk_91);
        RenderPropertyWithHex("unk_92", &pEntity->unk_92);
        RenderPropertyWithHex("unk_93", &pEntity->unk_93);
        RenderPropertyWithHex("unk_94", &pEntity->unk_94);
        RenderPropertyWithHex("unk_95", &pEntity->unk_95);
        RenderPropertyWithHex("unk_96", &pEntity->unk_96);

        EndPropertyTable();
    }
}

void WorldView::RenderCustomView(void *pEntity) {
    if (ImGui::Button("Dump Static Objects")) {
        DumpStaticObjects((DFCNode *) pEntity);
    }
}

void WorldView::RenderProperties(void *pVoid) {
    pVoid = GetCurrentSuperclassNode((DFCNode *) pVoid);
    RenderProperties((World *) pVoid);
    DFCNodeView::RenderProperties((DFCNode *) pVoid);
}

void WorldView::DumpStaticObjects(DFCNode *pNode) {
    nlohmann::json result = nlohmann::json::array();

    pNode->WalkChildren([&result](DFCNode *child) -> void {
        // StaticObject VFTable
        if (reinterpret_cast<unsigned int>(child->VFTable) != 0x8676E8) {
            return;
        }

        StaticObject *staticObject = (StaticObject *) child;

        nlohmann::json objectData = {
                {"gctypename", child->SuperClass->GCClass->FQTypeName->ToString()},
                {"gctypehash", child->SuperClass->GCClass->GCTypeHash},
                {"position",   {
                                       {"x", staticObject->positionX},
                                       {"y", staticObject->positionY},
                                       {"z", staticObject->positionZ},
                                       {"rotation", staticObject->rotation},
                               }}
        };

        result.push_back(objectData);

//		logger->Write(std::to_string(*reinterpret_cast<unsigned int*>(child->VFTable)));
    });

    auto jsonString = to_string(result);

    logger->Write(jsonString);
}
