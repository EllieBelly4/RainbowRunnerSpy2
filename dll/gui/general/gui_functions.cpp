//
// Created by Sophie on 03/07/2021.
//

#include <iomanip>
#include "gui_functions.h"

std::string IntToHex(int hash) {
    auto buf = new char[9];

    sprintf(buf, "%08X", hash);

    std::string str(buf);

    delete[]buf;

    return str;
}

void AddCopyText(const std::string &basicString) {
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{0.7, 0.7, 0.7, 0.2});
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.008f, 0.094f, 0.114f, 0});

    if (ImGui::Button("copy")) {
        PasteToClipboard(basicString);
    }

    ImGui::PopStyleColor(2);
}

ImVec2 Add(ImVec2 a, ImVec2 b) {
    return ImVec2{a.x + b.x, a.y + b.y};
}