//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_VIEWHANDLER_H
#define RRSPY2TESTAPP_VIEWHANDLER_H

#include <string>
#include <memory>
#include "../../../gameobjects/Entities/DFCNode.h"
#include "../../../../lib/imgui/imgui.h"
#include "../../general/colours.h"
#include "../../general/gui_functions.h"
#include "../../../common.h"
#include <gui/views/ViewState.h>

enum ListItemResult
{
	ListItemOK, ListItemClicked
};

class ViewHandler
{
public:
	static void RenderProperty(const std::string& name, const std::string& value);

	static bool BeginPropertyTable(std::string, int cols = 2);

	static bool BeginFullPropertyTable(std::string);

	static void EndPropertyTable();

	static void AddHeading(std::string);

	template<typename T>
	static void RenderPropertyWithHex(const std::string& name, T* value);

	template<typename T>
	static void AddValueProperty(const std::string& label, T* value);

	static ListItemResult RenderSelectableListItem(int i, const char* label, ImGuiID id);

	virtual void RenderProperties(void*);

	virtual void RenderCustomView(DFCNode*);

	template<typename T>
	static void RenderPropertyLocation(const std::string& name, const T* value);

	template<typename T>
	static void writeStringValue(const char* stringValue, T* Value);
};

template<typename T>
void ViewHandler::RenderPropertyWithHex(const std::string& name, T* value)
{
	if (IsBadReadPtr(value) || value == nullptr)
	{
		ImGui::TableNextColumn();
		ImGui::PushID("PropertyName");
		ImGui::TextColored(propertyColour, name.c_str());
		ImGui::PopID();

		ImGui::TableNextColumn();
		ImGui::TextColored(ImVec4(0.95, 0.1, 0.15, 1), "error");
		ImGui::TableNextRow();
		return;
	}

//	ImGui::PushID(name.c_str());
	char hexVal[32];

	sprintf(hexVal, (std::string("0x%0") + std::to_string(sizeof(T)) + "X").c_str());

	// Code from this function has been copied here, so we can add the DataText
//	RenderProperty(name, std::to_string(*value));

	ImGui::PushID(name.c_str());

	ImGui::TableNextColumn();
	ImGui::PushID("PropertyName");

	AddDataText(name, reinterpret_cast<unsigned int>(value), sizeof(T));
	ImGui::SameLine();

	ImGui::TextColored(propertyColour, name.c_str());
	ImGui::PopID();

	AddValueProperty("PropertyInt", reinterpret_cast<int*>(value));
	AddValueProperty("PropertyFloat", reinterpret_cast<float*>(value));

	ImGui::TableNextColumn();
	ImGui::PushID("PropertyHex");
	ImGui::TextColored(titleAltText, hexVal);
	ImGui::SameLine();
	AddCopyText(hexVal);
	ImGui::PopID();

	RenderPropertyLocation(name, value);

	ImGui::PopID();
}

template<typename T>
void ViewHandler::AddValueProperty(const std::string& label, T* value)
{
	ImGui::TableNextColumn();
	ImGui::PushID(label.c_str());

	auto textSize = ImGui::CalcTextSize(std::to_string(*value).c_str());
	auto rectMin = ImGui::GetCursorScreenPos();
	auto rectMax = Add(rectMin, textSize);

	rectMin.y += 1;
	rectMax.y += 4;

//	ImDrawList* windowDrawList = ImGui::GetWindowDrawList();
//	windowDrawList->AddRectFilled(rectMin, rectMax, TO_IMCOL32(ImVec4(1, 1, 1, 1)), 2);

	ImGuiID id = ImGui::GetID("");

	if (ImGui::IsMouseClicked(ImGuiMouseButton_Left) && ImGui::IsMouseHoveringRect(rectMin, rectMax))
	{
		if (viewState->CurrentSelectedEditBox == id)
		{
			viewState->CurrentSelectedEditBox = -1;
		}
		else
		{
			viewState->CurrentSelectedEditBox = id;
			strcpy(viewState->CurrentEditValue, std::to_string(*value).c_str());
		}
	}

	if (viewState->CurrentSelectedEditBox == id)
	{
		ImGui::InputText("", viewState->CurrentEditValue, 1024);

		if (ImGui::IsKeyDown(13))
		{
			writeStringValue(viewState->CurrentEditValue, value);
			viewState->CurrentSelectedEditBox = -1;
		}
	}
	else
	{
		ImGui::TextColored(titleAltText, std::to_string(*value).c_str());
	}

	ImGui::SameLine();
	AddCopyText(std::to_string(*value));

	ImGui::PopID();
}

template<typename T>
void ViewHandler::RenderPropertyLocation(const std::string& name, const T* value)
{
	char hexVal[32];

	sprintf(hexVal, "0x%08X", reinterpret_cast<unsigned int>(value));

	ImGui::TableNextColumn();
	ImGui::PushID("PropertyLocation");
	ImGui::TextColored(titleAltText, hexVal);
	ImGui::SameLine();
	AddCopyText(hexVal);
	ImGui::PopID();
}


#endif //RRSPY2TESTAPP_VIEWHANDLER_H
