//
// Created by Sophie on 05/07/2021.
//

#include "DFCNodeView.h"
#include "../../RRSpyGUI.h"
#include "GCClassView.h"
#include "../../../state.h"
#include "GCPropertiesView.h"

void DFCNodeView::RenderProperties(DFCNode* pNode)
{
	DFCNode* nodeToRender = GetCurrentSuperclassNode(pNode);

	if (nodeToRender == nullptr)
	{
		return;
	}

	RenderDFCNodeAllProperties(nodeToRender);

	if (!IsBadReadPtr(nodeToRender->GCClass))
	{
		GCClassView::RenderProperties(nodeToRender->GCClass);
	}

	if (!IsBadReadPtr(nodeToRender->GCProperties))
	{
		GCPropertiesView::RenderProperties(nodeToRender->GCProperties);
	}

	if (!IsBadReadPtr(nodeToRender->Desc))
	{
		if (ImGui::BeginTabItem("desc"))
		{
			ImGui::TextColored(entityColour, nodeToRender->Desc->GetTypeString().c_str());
			if (ImGui::BeginTabBar("desctabbar"))
			{
				RenderProperties(nodeToRender->Desc);
				ImGui::EndTabBar();
			}
			ImGui::EndTabItem();
		}
	}

//    RenderCommonProperties(nodeToRender);
}

void DFCNodeView::RenderDFCNodeAllProperties(DFCNode* pEntity)
{
	if (BeginFullPropertyTable("dfcnode"))
	{
		RenderPropertyWithHex("VFTable", (unsigned int*)&pEntity->VFTable);
		RenderPropertyWithHex("unk_0", &pEntity->unk_0);
		RenderPropertyWithHex("unk_1", &pEntity->unk_1);
		RenderPropertyWithHex("Inventory", &pEntity->Inventory);
		RenderPropertyWithHex("Parent", &pEntity->Parent);
		RenderPropertyWithHex("FirstChild", &pEntity->FirstChild);
		RenderPropertyWithHex("LastChild", &pEntity->LastChild);
		RenderPropertyWithHex("NextSibling", &pEntity->NextSibling);
		RenderPropertyWithHex("PreviousSibling", &pEntity->PreviousSibling);
		RenderPropertyWithHex("unk_8", &pEntity->unk_8);
		RenderPropertyWithHex("unk_9", &pEntity->unk_9);
		RenderPropertyWithHex("VFTableIEventHandler", &pEntity->VFTableIEventHandler);
		RenderPropertyWithHex("GCProperties", (unsigned int*)&pEntity->GCProperties);
		RenderPropertyWithHex("unk_12", &pEntity->unk_12);
		RenderPropertyWithHex("VFTableEventSystem", &pEntity->VFTableEventSystem);
		RenderPropertyWithHex("unk_14", &pEntity->unk_14);
		RenderPropertyWithHex("unk_15", &pEntity->unk_15);
		RenderPropertyWithHex("unk_16", &pEntity->unk_16);
		RenderPropertyWithHex("unk_17", &pEntity->unk_17);
		RenderPropertyWithHex("unk_18", &pEntity->unk_18);
		RenderPropertyWithHex("SuperClass", (unsigned int*)&pEntity->SuperClass);
		RenderPropertyWithHex("GCClass", (unsigned int*)&pEntity->GCClass);
		RenderPropertyWithHex("Desc", (unsigned int*)&pEntity->Desc);
		RenderPropertyWithHex("unk_22", &pEntity->unk_22);
		RenderPropertyWithHex("unk_23", &pEntity->unk_23);
		RenderPropertyWithHex("ID?", &pEntity->ID);

		EndPropertyTable();
	}
}

void DFCNodeView::RenderCommonProperties(DFCNode* nodeToRender)
{
	int tab_bar_flags = ImGuiTabBarFlags_None;
	ImGui::PushStyleColor(ImGuiCol_Tab, tabColour);
	ImGui::PushStyleColor(ImGuiCol_TabActive, tabSelectedColour);

	if (ImGui::BeginTabBar("DFCNodeProperties", tab_bar_flags))
	{
//        if (ImGui::BeginTabItem("DFC Node properties")) {
//
//            ImGui::PushStyleColor(ImGuiCol_Header, gcclassColour);
//
////            if (!IsBadReadPtr(nodeToRender->GCProperties) && ImGui::TreeNode("GCCProperties Raw Properties")) {
////                RenderStructPropertyTable((char*) nodeToRender->GCProperties, GetGCPropertiesProperties(), 10,
////                                          "GCCProperties Raw Properties");
////                ImGui::TreePop();
////            }
//
////            if(!IsBadReadPtr(nodeToRender->GCClass)){
////                GCClassView::RenderProperties(nodeToRender->GCClass);
////            }
//
////            if (!IsBadReadPtr(nodeToRender->GCClass) && ImGui::TreeNode("GCCLass Raw Properties")) {
////                RenderStructPropertyTable((char*) nodeToRender->GCClass, GetGCCLassProperties(), 70,
////                                          "GCCLassRawProperties");
////                ImGui::TreePop();
////            }
//
//            ImGui::PopStyleColor(1);
//
//            ImGui::EndTabItem();
//        }

//        if (!IsBadReadPtr(nodeToRender->Desc) && ImGui::BeginTabItem(nodeToRender->Desc->GetTypeString().c_str())) {
//            RenderProperties(nodeToRender->Desc);
//            ImGui::EndTabItem();
//        }

//        if (ImGui::BeginTabItem("RawProperties")) {
//            RenderStructPropertyTable((char*) nodeToRender, GetPlayerProperties(), 40);
//            ImGui::EndTabItem();
//        }

		ImGui::EndTabBar();
	}

	ImGui::PopStyleColor(2);
}

DFCNode* DFCNodeView::GetCurrentSuperclassNode(DFCNode* pNode)
{
	auto nodeToRender = pNode;

	for (auto i = 0; i != state->PropertyViewState.SelectedSuperClassIndex; i++)
	{
		nodeToRender = nodeToRender->SuperClass;
	}

	return nodeToRender;
}

void DFCNodeView::RenderNodeCrumblebar(DFCNode* pNode)
{
	DFCNode* currentNode = pNode;
	bool first = true;
	int i = 0;
	int newSelected = state->PropertyViewState.SelectedSuperClassIndex;

	while (!IsBadReadPtr(currentNode))
	{
		if (!first)
		{
			ImGui::SameLine();
			ImGui::TextColored(textDisabled, "<");
		}

		if (i == state->PropertyViewState.SelectedSuperClassIndex)
		{
			ImGui::PushFont(firaHeading);
			ImGui::PushStyleColor(ImGuiCol_Text, listSelected);
		}
		else
		{
			ImGui::PushStyleColor(ImGuiCol_Text, gcSuperclassColour);
		}

		if (!first)
		{
			ImGui::SameLine();
		}

		auto cursorPos = ImGui::GetCursorScreenPos();
		auto textSize = ImGui::CalcTextSize(currentNode->GetTypeString().c_str());
		const ImVec2 max = ImVec2{ cursorPos.x + textSize.x, cursorPos.y + textSize.y };
		bool hovered = ImGui::IsMouseHoveringRect(cursorPos, max);

		if (hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left))
		{
			newSelected = i;
		}

		ImGui::Text(currentNode->GetTypeString().c_str());

		ImGui::PopStyleColor(1);

		if (i == state->PropertyViewState.SelectedSuperClassIndex)
		{
			ImGui::PopFont();
		}

		currentNode = currentNode->SuperClass;
		first = false;
		i++;
	}

	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);

	if (state->PropertyViewState.SelectedSuperClassIndex >= i)
	{
		newSelected = i - 1;
	}

	state->PropertyViewState.SelectedSuperClassIndex = newSelected;
}

void DFCNodeView::RenderListItem(DFCNode* pNode, int i)
{
	ImGui::Text("DFCNode");
}

void DFCNodeView::RenderProperties(void* pVoid)
{
	RenderProperties((DFCNode*)pVoid);
}

