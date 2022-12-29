//
// Created by Ellie on 04/12/2022.
//

#include "PathMapView.h"
#include "state.h"
#include <datatypes/PathNode.h>

void PathMapView::RenderCustomView(void *node) {
    auto *pathMap = (PathMap *) node;

    if (ImGui::Button("Dump Nodes")) {
        auto stream = logger->Stream();

        logger->Write("Dumping nodes");

//        nlohmann::json pathMapJson();
        nlohmann::json pathMapResults[pathMap->width * pathMap->height];

        for (int x = 0; x < pathMap->width; ++x) {
            for (int y = 0; y < pathMap->height; ++y) {
                void *basePtr = (void *) *(unsigned int *) (
                        ((unsigned int) pathMap->nodes) + x * 4 + y * pathMap->width * 4
                );

                pathMapResults[x + y * pathMap->width] = nlohmann::json::array();

                if (basePtr == 0) {
//                    *stream << "_ ";
                    continue;
                } else if (IsBadReadPtr(basePtr)) {
                    *stream << "bad(" << x << "," << y << ")["
                            << std::hex << ((unsigned int) pathMap->nodes) + x * 4 + y * pathMap->width * 4 << "] ";
                    continue;
                }

                auto **subNodes = (PathNode *(*)) basePtr;

                DumpSubNodes(pathMap, subNodes, pathMapResults[x + y * pathMap->width]);

//                *stream << "* ";

//                *stream << std::to_string((float) pathNode->x_coord) << ",";
//                *stream << std::to_string((float) pathNode->y_coord) << " ";
            }

//            *stream << std::endl;
        }

        nlohmann::json pathMapJson = nlohmann::json::array();

        for (int x = 0; x < pathMap->width; ++x) {
            for (int y = 0; y < pathMap->height; ++y) {
                pathMapJson.push_back(pathMapResults[x + y * pathMap->width]);
            }
        }

        logger->Write("Saving results");

        std::ofstream jsonOutput;

        char *filename = new char[256];

        auto mapName = state->CurrentWorld->MapName->ToString();
        std::transform(mapName.begin(), mapName.end(), mapName.begin(), ::tolower);

        sprintf(filename, "dumps/%s_pathmap.json", mapName.c_str());

        jsonOutput.open(filename, std::ios::trunc | std::ios::in);

        auto finalJson = nlohmann::json({
                                                {"worldOffsetX", (float) state->CurrentWorld->root_pos.X},
                                                {"worldOffsetY", (float) state->CurrentWorld->root_pos.Y},
                                                {"worldOffsetZ", (float) state->CurrentWorld->root_pos.Z},
                                                {"coordLimitX",  pathMap->coord_limit_x},
                                                {"coordLimitY",  pathMap->coord_limit_y},
                                                {"tileWidth",    (float) pathMap->grid_tile_width},
                                                {"tileHeight",   (float) pathMap->grid_tile_height},
                                                {"width",        pathMap->width},
                                                {"height",       pathMap->height},
                                                {"nodes",        pathMapJson}
                                        });

        const std::string &jsonString = finalJson.dump() + "\n";

        jsonOutput.write(jsonString.c_str(), jsonString.length());

        jsonOutput.close();
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
        RenderPropertyWithHex("grid_tile_width", &pathMap->grid_tile_width);
        RenderPropertyWithHex("field_1C", &pathMap->field_1C);
        RenderPropertyWithHex("field_20", &pathMap->field_20);
        RenderPropertyWithHex("grid_tile_height", &pathMap->grid_tile_height);
        RenderPropertyWithHex("coord_limit_x", &pathMap->coord_limit_x);
        RenderPropertyWithHex("coord_limit_y", &pathMap->coord_limit_y);
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

void PathMapView::DumpSubNodes(PathMap *pathMap, PathNode **pNode, nlohmann::basic_json<> &pJson) {
    auto stream = logger->Stream();

    logger->Write("Dumping sub nodes");

    for (int x = 0; x < 16; ++x) {
        for (int y = 0; y < 16; ++y) {
            void *basePtr = (void *) *(unsigned int *) (
                    ((unsigned int) pNode) + x * 4 + y * 16 * 4
            );

            auto solid = true;

            if (basePtr == nullptr) {
                solid = false;
            } else if (IsBadReadPtr(basePtr)) {
                *stream << "bad(" << x << "," << y << ")["
                        << std::hex << basePtr
                        << "] ";
                continue;
            }

            auto node = (PathNode *) basePtr;

            if (solid) {
                pJson[x + y * 16] = {
                        {"solid",  true},
                        {"gridX",  node->x_coord.value},
                        {"gridY",  node->y_coord.value},
                        {"worldX", (float) node->global_x_coord},
                        {"worldY", (float) node->global_y_coord},
                        {"height", (float) node->height},
                        {"unk1",   node->unk_1},
//                        {"unk2",           node->unk_2},
                };
            } else {
                pJson[x + y * 16] = {
                        {"solid", false},
                };
            }

        }

        *stream << std::endl;
    }
}
