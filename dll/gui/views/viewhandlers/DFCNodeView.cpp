//
// Created by Sophie on 05/07/2021.
//

#include "DFCNodeView.h"
#include "../../general/colours.h"
#include "../../../common.h"
#include "../../../gameobjects/Entities/Player.h"
#include "../../entities/properties.h"
#include "../../../datatypes/GCProperties.h"
#include "../../general/structs.h"
#include "../../RRSpyGUI.h"
#include "GCClassView.h"
#include "../../../state.h"

void DFCNodeView::RenderProperties(DFCNode* pNode) {
    DFCNode* nodeToRender = GetCurrentSuperclassNode(pNode);

    if (!IsBadReadPtr(nodeToRender->GCClass)) {
        GCClassView::RenderProperties(nodeToRender->GCClass);
    }

    RenderCommonProperties(nodeToRender);
}

void DFCNodeView::RenderCommonProperties(DFCNode* nodeToRender) {
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
            RenderProperties(nodeToRender->Desc);
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

DFCNode* DFCNodeView::GetCurrentSuperclassNode(DFCNode* pNode) {
    auto nodeToRender = pNode;

    for (auto i = 0; i != state->PropertyViewState.SelectedSuperClassIndex; i++) {
        nodeToRender = nodeToRender->SuperClass;
    }

    return nodeToRender;
}

void DFCNodeView::RenderNodeCrumblebar(DFCNode* pNode) {
    DFCNode* currentNode = pNode;
    bool first = true;
    int i = 0;
    int newSelected = state->PropertyViewState.SelectedSuperClassIndex;

    while (!IsBadReadPtr(currentNode)) {
        if (!first) {
            ImGui::SameLine();
            ImGui::TextColored(textDisabled, "<");
        }

        if (i == state->PropertyViewState.SelectedSuperClassIndex) {
            ImGui::PushFont(firaHeading);
            ImGui::PushStyleColor(ImGuiCol_Text, listSelected);
        } else {
            ImGui::PushStyleColor(ImGuiCol_Text, gcSuperclassColour);
        }

        if(!first){
            ImGui::SameLine();
        }

        auto cursorPos = ImGui::GetCursorScreenPos();
        auto textSize = ImGui::CalcTextSize(currentNode->GetTypeString().c_str());
        const ImVec2 max = ImVec2{cursorPos.x + textSize.x, cursorPos.y + textSize.y};
        bool hovered = ImGui::IsMouseHoveringRect(cursorPos, max);

        if (hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
            newSelected = i;
        }

        ImGui::Text(currentNode->GetTypeString().c_str());

        ImGui::PopStyleColor(1);

        if (i == state->PropertyViewState.SelectedSuperClassIndex) {
            ImGui::PopFont();
        }

        currentNode = currentNode->SuperClass;
        first = false;
        i++;
    }

    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);

    if (state->PropertyViewState.SelectedSuperClassIndex >= i) {
        newSelected = i - 1;
    }

    state->PropertyViewState.SelectedSuperClassIndex = newSelected;
}

void DFCNodeView::RenderListItem(DFCNode* pNode, int i) {
    ImGui::Text("DFCNode");
}

void DFCNodeView::RenderProperties(void* pVoid) {
    RenderNodeCrumblebar((DFCNode*) pVoid);
    RenderProperties((DFCNode*) pVoid);
}

