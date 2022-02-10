//
// Created by Sophie on 10/02/2022.
//

#ifndef RRSPY2TESTAPP_VIEWSTATE_H
#define RRSPY2TESTAPP_VIEWSTATE_H

#include "imgui/imgui.h"

struct ViewState
{
	ImGuiID CurrentSelectedEditBox;
	char* CurrentEditValue = new char[1024];
};

extern std::shared_ptr<ViewState> viewState;

#endif //RRSPY2TESTAPP_VIEWSTATE_H
