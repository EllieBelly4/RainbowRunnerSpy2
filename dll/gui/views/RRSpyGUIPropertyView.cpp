//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyGUIPropertyView.h"
#include "../entities/properties.h"
#include "../../common.h"
#include "../general/colours.h"
#include "../../rrspy.h"
#include "../../datatypes/GCProperties.h"
#include "../general/structs.h"
#include "viewhandlers/PlayerView.h"
#include "viewhandlers/AvatarView.h"
#include "viewhandlers/MeleeWeaponView.h"

RRSpyGUIPropertyView::RRSpyGUIPropertyView(std::shared_ptr<RRSpyState> state, std::shared_ptr<log::Log> logger)
        : _state(state), logger(logger) {

}

void RRSpyGUIPropertyView::Render() {
    ImGui::Begin("Properties");

    if (_state->CurrentSelectedEntity != nullptr && !IsBadReadPtr(_state->CurrentSelectedEntity->_node)) {
        RenderNodeCrumblebar(_state->CurrentSelectedEntity->_node);
        RenderProperties(_state->CurrentSelectedEntity->_node);
    }

    ImGui::End();
}

void RRSpyGUIPropertyView::RenderProperties(DFCNode* pNode) {
    auto nodeToRender = pNode;

    for (auto i = 0; i != _selectedSuperClassIndex; i++) {
        nodeToRender = nodeToRender->SuperClass;
    }

    auto vftable = (int) nodeToRender->VFTable;

    switch (vftable) {
        case 0x0089B468:
            PlayerView::RenderProperties((Player*) nodeToRender);
            break;
        case 0x0086DE00:
            AvatarView::RenderProperties((Avatar*) nodeToRender);
            break;
        case 0x00893490:
            MeleeWeaponView::RenderProperties((MeleeWeapon*) nodeToRender);
            break;
    }

    int tab_bar_flags = ImGuiTabBarFlags_None;
    ImGui::PushStyleColor(ImGuiCol_Tab, tabColour);
    ImGui::PushStyleColor(ImGuiCol_TabActive, tabSelectedColour);

    if (ImGui::BeginTabBar("DFCNodeProperties", tab_bar_flags)) {
        if (ImGui::BeginTabItem("DFC Node properties")) {
            if (ImGui::BeginTable("PropertyTable", 4,
                                  ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit)) {
                RenderDFCNodeProperties(nodeToRender);

                ImGui::EndTable();
            }

            if (!IsBadReadPtr(nodeToRender->GCProperties) && ImGui::BeginTable("SomePropertiesStruct", 3,
                                                                               ImGuiTableFlags_Borders |
                                                                               ImGuiTableFlags_RowBg |
                                                                               ImGuiTableFlags_SizingFixedFit)) {
                RenderGCProperties(nodeToRender->GCProperties);
                ImGui::EndTable();
            }

            ImGui::PushStyleColor(ImGuiCol_Header, gcclassColour);

            if (!IsBadReadPtr(nodeToRender->GCProperties) && ImGui::TreeNode("GCCProperties Raw Properties")) {
                RenderStructPropertyTable((char*) nodeToRender->GCProperties, GetGCPropertiesProperties(), 10,
                                          "GCCProperties Raw Properties");
                ImGui::TreePop();
            }

            if (!IsBadReadPtr(nodeToRender->GCClass) && ImGui::TreeNode("GCCLass Raw Properties")) {
                RenderStructPropertyTable((char*) nodeToRender->GCClass, GetGCCLassProperties(), 70,
                                          "GCCLassRawProperties");
                ImGui::TreePop();
            }

            ImGui::PopStyleColor(1);

            ImGui::EndTabItem();
        }

        if (!IsBadReadPtr(nodeToRender->Desc) && ImGui::BeginTabItem(nodeToRender->Desc->GetTypeString().c_str())) {
            ImGui::Indent();
//            RenderDFCNodeInner(nodeToRender->Desc);
            ImGui::Unindent();
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("RawProperties")) {
            RenderStructPropertyTable((char*) nodeToRender, GetPlayerProperties(), 40);
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::PopStyleColor(2);
}

void RRSpyGUIPropertyView::RenderNodeCrumblebar(DFCNode* pNode) {
    DFCNode* currentNode = pNode;
    bool first = true;
    int i = 0;
    int newSelected = _selectedSuperClassIndex;

    while (!IsBadReadPtr(currentNode)) {
        if (!first) {
            ImGui::SameLine();
            ImGui::TextColored(textDisabled, "<");
        }

        if (i == _selectedSuperClassIndex) {
            ImGui::PushFont(firaHeading);
            ImGui::PushStyleColor(ImGuiCol_Text, listSelected);
        } else {
            ImGui::PushStyleColor(ImGuiCol_Text, gcSuperclassColour);
        }

        ImGui::SameLine();

        auto cursorPos = ImGui::GetCursorScreenPos();
        auto textSize = ImGui::CalcTextSize(currentNode->GetTypeString().c_str());
        const ImVec2 max = ImVec2{cursorPos.x + textSize.x, cursorPos.y + textSize.y};
        bool hovered = ImGui::IsMouseHoveringRect(cursorPos, max);

        if (hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
            newSelected = i;
        }

        ImGui::Text(currentNode->GetTypeString().c_str());

        ImGui::PopStyleColor(1);

        if (i == _selectedSuperClassIndex) {
            ImGui::PopFont();
        }

        currentNode = currentNode->SuperClass;
        first = false;
        i++;
    }

    ImGui::NewLine();

    if (_selectedSuperClassIndex >= i) {
        newSelected = i - 1;
    }

    _selectedSuperClassIndex = newSelected;
}
