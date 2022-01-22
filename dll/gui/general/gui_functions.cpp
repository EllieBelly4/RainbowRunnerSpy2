//
// Created by Sophie on 03/07/2021.
//

#include <iomanip>
#include <iostream>
#include <windows.h>
#include "gui_functions.h"
#include "common.h"

std::string IntToHex(int hash)
{
	auto buf = new char[9];

	sprintf(buf, "%08X", hash);

	std::string str(buf);

	delete[]buf;

	return str;
}

void AddCopyText(const std::string& basicString)
{
	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{ 0.7, 0.7, 0.7, 0.2 });
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.008f, 0.094f, 0.114f, 0 });

	if (ImGui::Button("copy"))
	{
		PasteToClipboard(basicString);
	}

	ImGui::PopStyleColor(2);
}

void AddDataText(const std::string& name, unsigned int address, unsigned int size)
{
	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{ 0.7, 0.7, 0.7, 0.2 });
	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.008f, 0.094f, 0.114f, 0 });

	if (ImGui::Button("D"))
	{
		logger->Write("DataStream " + name + " " + std::to_string(address));

		memoryDataStream->Watch(name, address, size);
	}

	ImGui::PopStyleColor(2);
}

ImVec2 Add(ImVec2 a, ImVec2 b)
{
	return ImVec2{ a.x + b.x, a.y + b.y };
}


bool PasteToClipboard(const std::string& text)
{
	std::cout << "Copy Value " << text << std::endl;

	bool succeeded = false;

	if (HANDLE clipdata = GlobalAlloc(GMEM_FIXED, text.length() + 1))
	{
		memcpy(clipdata, text.data(), text.length() + 1);

		if (OpenClipboard(NULL))
		{
			if (EmptyClipboard() && SetClipboardData(CF_TEXT, clipdata))
				succeeded = true;

			CloseClipboard();
		}

		if (!succeeded)
			GlobalFree(clipdata);
	}

	return succeeded;
}

//bool IsBadReadPtr(void* p)
//{
//    MEMORY_BASIC_INFORMATION mbi = {0};
//    if (::VirtualQuery(p, &mbi, sizeof(mbi)))
//    {
//        DWORD mask = (PAGE_READONLY|PAGE_READWRITE|PAGE_WRITECOPY|PAGE_EXECUTE_READ|PAGE_EXECUTE_READWRITE|PAGE_EXECUTE_WRITECOPY);
//        bool b = !(mbi.Protect & mask);
//        // check the page is not a guard page
//        if (mbi.Protect & (PAGE_GUARD|PAGE_NOACCESS)) b = true;
//
//        return b;
//    }
//    return true;
//}

