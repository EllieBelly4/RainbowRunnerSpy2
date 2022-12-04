//
// Created by Ellie on 04/12/2022.
//

#include "PathMapView.h"

void PathMapView::RenderProperties(void *pVoid) {
    RenderProperties((PathMap *) pVoid);
}

void PathMapView::RenderProperties(PathMap *pathMap) {
    if (BeginFullPropertyTable("pathMap")) {
        RenderPropertyWithHex("vtable", &pathMap->vtable);
        RenderPropertyWithHex("field_4", &pathMap->field_4);
        RenderPropertyWithHex("field_8", &pathMap->field_8);
        RenderPropertyWithHex("field_C", &pathMap->field_C);
        RenderPropertyWithHex("world", &pathMap->world);
        RenderPropertyWithHex("world_collision_manager", &pathMap->world_collision_manager);
        RenderPropertyWithHex("world_collision_helper", &pathMap->field_18);
        RenderPropertyWithHex("field_1C", &pathMap->field_1C);
        RenderPropertyWithHex("field_20", &pathMap->field_20);
        RenderPropertyWithHex("field_24", &pathMap->field_24);
        RenderPropertyWithHex("field_28", &pathMap->field_28);
        RenderPropertyWithHex("field_2C", &pathMap->field_2C);
        RenderPropertyWithHex("field_30", &pathMap->field_30);
        RenderPropertyWithHex("field_34", &pathMap->field_34);
        RenderPropertyWithHex("field_38", &pathMap->field_38);
        RenderPropertyWithHex("aNsemanagerL110", &pathMap->aNsemanagerL110);
        RenderPropertyWithHex("anonymous_0", &pathMap->anonymous_0);
        RenderPropertyWithHex("anonymous_1", &pathMap->anonymous_1);
        RenderPropertyWithHex("field_48", &pathMap->field_48);
        RenderPropertyWithHex("field_4C", &pathMap->field_4C);
        RenderPropertyWithHex("field_50", &pathMap->field_50);
        RenderPropertyWithHex("field_54", &pathMap->field_54);
        RenderPropertyWithHex("field_58", &pathMap->field_58);
        RenderPropertyWithHex("field_5C", &pathMap->field_5C);
        EndPropertyTable();
    }
}
