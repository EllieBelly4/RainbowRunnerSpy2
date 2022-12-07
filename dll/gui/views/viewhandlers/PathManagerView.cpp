//
// Created by Ellie on 04/12/2022.
//

#include "PathManagerView.h"

void PathManagerView::RenderProperties(void *pVoid) {
    RenderProperties((PathManager *) pVoid);
}

void PathManagerView::RenderProperties(PathManager *pEntity) {
    if (BeginFullPropertyTable("pathManager")) {
        RenderPropertyWithHex("vtable", &pEntity->vtable);
        RenderPropertyWithHex("field_4", &pEntity->field_4);
        RenderPropertyWithHex("field_8", &pEntity->field_8);
        RenderPropertyWithHex("field_C", &pEntity->field_C);
        RenderPropertyReference("world", &pEntity->world);
        RenderPropertyReference("path_map", &pEntity->path_map);
        RenderPropertyReference("world_collision_helper", &pEntity->world_collision_helper);
        RenderPropertyWithHex("field_1C", &pEntity->field_1C);
        RenderPropertyWithHex("unk_budget_related", &pEntity->unk_budget_related);
        RenderPropertyWithHex("grid_tile_height", &pEntity->field_24);
        RenderPropertyWithHex("coord_limit_x", &pEntity->field_28);
        RenderPropertyWithHex("coord_limit_y", &pEntity->field_2C);
        RenderPropertyWithHex("field_30", &pEntity->field_30);
        RenderPropertyWithHex("field_34", &pEntity->field_34);
        RenderPropertyWithHex("field_38", &pEntity->field_38);
        RenderPropertyWithHex("field_3C", &pEntity->field_3C);
        RenderPropertyWithHex("field_40", &pEntity->field_40);
        RenderPropertyWithHex("field_44", &pEntity->field_44);
        RenderPropertyWithHex("width", &pEntity->field_48);
        RenderPropertyWithHex("height", &pEntity->field_4C);
        RenderPropertyWithHex("node_count", &pEntity->field_50);
        RenderPropertyWithHex("budget_per_update", &pEntity->budget_per_update);
        RenderPropertyWithHex("field_58", &pEntity->field_58);
        RenderPropertyWithHex("field_5C", &pEntity->field_5C);
        RenderPropertyWithHex("budget_per_path", &pEntity->budget_per_path);
        RenderPropertyWithHex("field_64", &pEntity->field_64);
        RenderPropertyWithHex("field_68", &pEntity->field_68);
        RenderPropertyWithHex("field_6C", &pEntity->field_6C);
        RenderPropertyWithHex("field_70", &pEntity->field_70);
        RenderPropertyWithHex("field_74", &pEntity->field_74);
        RenderPropertyWithHex("field_78", &pEntity->field_78);
        RenderPropertyWithHex("field_7C", &pEntity->field_7C);
        RenderPropertyWithHex("field_80", &pEntity->field_80);
        RenderPropertyWithHex("field_84", &pEntity->field_84);
        RenderPropertyWithHex("field_88", &pEntity->field_88);
        RenderPropertyWithHex("field_8C", &pEntity->field_8C);
        EndPropertyTable();
    }
}
