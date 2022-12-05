//
// Created by Ellie on 04/12/2022.
//

#include "PathMapView.h"
#include <datatypes/PathNode.h>

void PathMapView::RenderCustomView(void *node) {
    auto *pathMap = (PathMap *) node;

    if (ImGui::Button("Dump Nodes")) {
        auto stream = logger->Stream();

        logger->Write("Dumping nodes");

        for (int x = 0; x < pathMap->width; ++x) {
            for (int y = 0; y < pathMap->height; ++y) {
                void *basePtr = (void *) *(unsigned int *) (
                        ((unsigned int) pathMap->nodes) + x * 4 + y * pathMap->width * 4
                );

                if (basePtr == 0) {
//                    *stream << "_ ";
                    continue;
                } else if (IsBadReadPtr(basePtr)) {
                    *stream << "bad(" << x << "," << y << ")["
                            << std::hex << ((unsigned int) pathMap->nodes) + x * 4 + y * pathMap->width * 4 << "] ";
                    continue;
                }

                auto **subNodes = (PathNode *(*)) basePtr;

                DumpSubNodes(pathMap, subNodes);

//                *stream << "* ";

//                *stream << std::to_string((float) pathNode->x_coord) << ",";
//                *stream << std::to_string((float) pathNode->y_coord) << " ";
            }

            *stream << std::endl;
        }
    }
}

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
        RenderPropertyWithHex("field_18", &pathMap->field_18);
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
        RenderPropertyWithHex("width", &pathMap->width);
        RenderPropertyWithHex("height", &pathMap->height);
        RenderPropertyWithHex("node_count", &pathMap->node_count);
        RenderPropertyWithHex("nodes", &pathMap->nodes);
        RenderPropertyWithHex("field_58", &pathMap->field_58);
        RenderPropertyWithHex("field_5C", &pathMap->field_5C);
        EndPropertyTable();
    }
}

void PathMapView::DumpSubNodes(PathMap *pathMap, PathNode **pNode) {
    auto stream = logger->Stream();

    logger->Write("Dumping sub nodes");

    for (int x = 0; x < pathMap->width; ++x) {
        for (int y = 0; y < pathMap->height; ++y) {
            void *basePtr = (void *) *(unsigned int *) (
                    ((unsigned int) pNode) + x * 4 + y * pathMap->width * 4
            );

//            *stream << std::hex << basePtr << " ";

            if (basePtr == 0) {
                *stream << "_ ";
                continue;
            } else if (IsBadReadPtr(basePtr)) {
                *stream << "bad(" << x << "," << y << ")["
                        << std::hex << ((unsigned int) pathMap->nodes) + x * 4 + y * pathMap->width * 4
                        << "] ";
                continue;
            }

            *stream << "* ";
        }

        *stream << std::endl;
    }
}
