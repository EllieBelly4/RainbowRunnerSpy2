//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_VIEWHANDLER_H
#define RRSPY2TESTAPP_VIEWHANDLER_H

#include <string>
#include "../../../gameobjects/Entities/DFCNode.h"
#include "../../../../lib/imgui/imgui.h"

enum ListItemResult {
    ListItemOK, ListItemClicked
};

class ViewHandler {
protected:
    static void RenderProperty(const std::string &name, const std::string &value);

    static bool BeginPropertyTable();

    static void EndPropertyTable();

    static ListItemResult RenderSelectableListItem(int i, const char* label, ImGuiID id);
};


#endif //RRSPY2TESTAPP_VIEWHANDLER_H
