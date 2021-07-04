//
// Created by Sophie on 03/07/2021.
//

#ifndef RRSPY2TESTAPP_GUI_FUNCTIONS_H
#define RRSPY2TESTAPP_GUI_FUNCTIONS_H

#include "../../../lib/imgui/imgui.h"

std::string IntToHex(int hash);

void AddCopyText(const std::string &basicString);

ImVec2 Add(ImVec2 a, ImVec2 b);

bool PasteToClipboard(const std::string &text);

//bool IsBadReadPtr(void* p);

#endif //RRSPY2TESTAPP_GUI_FUNCTIONS_H
