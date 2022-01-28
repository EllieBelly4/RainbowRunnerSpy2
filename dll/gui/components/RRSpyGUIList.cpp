//
// Created by Sophie on 04/07/2021.
//

#include <chrono>
#include "RRSpyGUIList.h"
#include "../../common.h"
#include "../../gameobjects/map.h"

void RRSpyGUIList::RenderItem(DFCNode* pEntity, int i)
{
	std::string listItemLabel = pEntity->GetTypeString();

	if (listItemLabel.empty())
	{
		char hexStr[128];
		sprintf(hexStr, "Unknown VFTable 0x%08X", reinterpret_cast<unsigned int>(pEntity->VFTable));
		listItemLabel += hexStr;
	}

	if (!IsBadReadPtr(pEntity) && !IsBadReadPtr(pEntity->VFTable) && EntityMap.contains((unsigned int)pEntity->VFTable)) {
		auto entityDef = EntityMap.at((unsigned int)pEntity->VFTable);

		if (entityDef != nullptr && dynamic_cast<DFCNodeView*>(entityDef->View) != nullptr)
		{
			if (!IsBadReadPtr(pEntity->SuperClass) && !IsBadReadPtr(pEntity->SuperClass->GCClass) &&
				!IsBadReadPtr(pEntity->SuperClass->GCClass->FQTypeName))
			{
				listItemLabel = listItemLabel + " (" + pEntity->SuperClass->GCClass->FQTypeName->ToString() + ")";
			}
		}
	}

	auto textSize = ImGui::CalcTextSize(listItemLabel.c_str());
	auto cursorPos = ImGui::GetCursorScreenPos();
	auto openKey = ImGui::GetID("openKey");
	auto isOpen = ImGui::GetStateStorage()->GetBool(openKey);

	auto lineMax = Add(cursorPos, textSize);
	auto lineMin = cursorPos;

	lineMin.x -= 22;
	lineMin.y -= 2;

	lineMax.x = ImGui::GetContentRegionAvailWidth() + cursorPos.x;
	lineMax.y += 2;

	bool hovered = ImGui::IsMouseHoveringRect(lineMin, lineMax);

	auto lineColour = TO_IMCOL32(panelBg);

	if (i % 2 == 0)
	{
		lineColour = hovered ? TO_IMCOL32(panelBgLt) : TO_IMCOL32(panelBg);
	}
	else
	{
		lineColour = hovered ? TO_IMCOL32(listAltBgLt) : TO_IMCOL32(listAltBg);
	}

	ImGuiID currentID = ImGui::GetID("entity");

	if (!IsBadReadPtr(_state->CurrentSelectedEntity.get()) && _state->CurrentID == currentID)
	{
		lineColour = TO_IMCOL32(listSelected);
		_state->ConfirmSelectedIsVisible(currentID);
	}

	ImDrawList* windowDrawList = ImGui::GetWindowDrawList();
	windowDrawList->AddRectFilled(lineMin, lineMax, lineColour, 2);

	// Add child indicator icon
	if (!IsBadReadPtr(pEntity) && !IsBadReadPtr((void*)pEntity->FirstChild) && pEntity->FirstChild != 0)
	{
		windowDrawList->AddCircleFilled(ImVec2(lineMin.x + 11, lineMin.y + 12), 5, IM_COL32_WHITE);

		if (isOpen)
		{
			windowDrawList->AddCircleFilled(ImVec2(lineMin.x + 11, lineMin.y + 12), 3, lineColour);
		}
	}

	// Handle selection and open clicks
	if (hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left))
	{
		auto now = duration_cast<std::chrono::milliseconds>(
				std::chrono::system_clock::now().time_since_epoch()
		);

		if (_state->ItemSelectState.LastIDClicked == currentID &&
			now.count() - _state->ItemSelectState.LastClickedTime.count() < 200)
		{
			isOpen = !isOpen;
			ImGui::GetStateStorage()->SetBool(openKey, isOpen);
		}
		else
		{
			logger->Write(std::to_string((int)pEntity->VFTable));
			_state->SetSelectedEntity(GetEntityWrapper(pEntity->VFTable), pEntity, currentID);
		}

		_state->ItemSelectState.LastClickedTime = now;
		_state->ItemSelectState.LastIDClicked = currentID;
	}

	ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32_WHITE);

	// Render list item text
	if (!IsBadReadPtr(pEntity))
	{
		ImGui::Text(listItemLabel.c_str());
	}
	else
	{
		ImGui::Text("UnknownEntity");
	}

	// Render children if expanded
	if (isOpen && !IsBadReadPtr((void*)pEntity->FirstChild))
	{
		ImGui::Indent();
		Render(pEntity);
		ImGui::Unindent();
	}

	ImGui::PopStyleColor(1);
}

void RRSpyGUIList::Render(EntityContainer* pContainer)
{
	int j = 0;

	for (unsigned int i = pContainer->OwnedObjectsStart; i < pContainer->OwnedObjectsEnd; i += 4, j++)
	{
		if (IsBadReadPtr((void*)i))
		{
			return;
		}

		auto entityPtr = *(DFCNode**)(i);
		ImGui::PushID(i);
		RenderItem(entityPtr, j);
		ImGui::PopID();
	}
}

void RRSpyGUIList::Render(DFCNode* pNode)
{
	auto currentChild = reinterpret_cast<DFCNode*>(pNode->FirstChild);

	int i = 0;

	while (!IsBadReadPtr(currentChild))
	{
		ImGui::PushID(i);
		RenderItem(currentChild, i);
		currentChild = reinterpret_cast<DFCNode*>(currentChild->NextSibling);
		ImGui::PopID();
		i++;
	}
}

RRSpyGUIList::RRSpyGUIList(std::shared_ptr<RRSpyState> state) : _state(state)
{
}
