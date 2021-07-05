//
// Created by Sophie on 04/07/2021.
//

#include <chrono>
#include "RRSpyGUIList.h"
#include "../../common.h"

void RRSpyGUIList::RenderItem(DFCNode* pEntity, int i) {
    auto textSize = ImGui::CalcTextSize(pEntity->GetTypeString().c_str());
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

    if (i % 2 == 0) {
        lineColour = hovered ? TO_IMCOL32(panelBgLt) : TO_IMCOL32(panelBg);
    } else {
        lineColour = hovered ? TO_IMCOL32(listAltBgLt) : TO_IMCOL32(listAltBg);
    }

    ImGuiID currentID = ImGui::GetID("entity");

    if (!IsBadReadPtr(_state->CurrentSelectedEntity.get()) && _state->CurrentSelectedEntity->ImGui_ID == currentID) {
        lineColour = TO_IMCOL32(listSelected);
        _state->ConfirmSelectedIsVisible(currentID);
    }

    ImDrawList* windowDrawList = ImGui::GetWindowDrawList();
    windowDrawList->AddRectFilled(lineMin, lineMax, lineColour, 2);

    if (pEntity->FirstChild != 0) {
        windowDrawList->AddCircleFilled(ImVec2(lineMin.x + 11, lineMin.y + 12), 5, IM_COL32_WHITE);

        if (isOpen) {
            windowDrawList->AddCircleFilled(ImVec2(lineMin.x + 11, lineMin.y + 12), 3, lineColour);
        }
    }

    if (hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
        auto now = duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()
        );

        if (_state->ItemSelectState.LastIDClicked == currentID &&
            now.count() - _state->ItemSelectState.LastClickedTime.count() < 200) {
            isOpen = !isOpen;
            ImGui::GetStateStorage()->SetBool(openKey, isOpen);
        } else {
            _state->SetSelectedEntity(std::make_shared<RRSpyDFCNode>(pEntity, currentID));
        }

        _state->ItemSelectState.LastClickedTime = now;
        _state->ItemSelectState.LastIDClicked = currentID;
    }

    if (!IsBadReadPtr((void*) pEntity->FirstChild)) {
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32_WHITE);

        ImGui::Text(pEntity->GetTypeString().c_str());

        if (isOpen) {
            ImGui::Indent();
            Render(pEntity);
            ImGui::Unindent();
        }

        ImGui::PopStyleColor(1);
    } else {
        ImGui::Text(pEntity->GetTypeString().c_str());
    }
}

void RRSpyGUIList::Render(EntityContainer* pContainer) {
    int j = 0;

    for (unsigned int i = pContainer->OwnedObjectsStart; i < pContainer->OwnedObjectsEnd; i += 4, j++) {
        if (IsBadReadPtr((void*) i)) {
            return;
        }

        auto entityPtr = *(DFCNode**) (i);
        ImGui::PushID(i);
        RenderItem(entityPtr, j);
        ImGui::PopID();
    }
}

void RRSpyGUIList::Render(DFCNode* pNode) {
    auto currentChild = reinterpret_cast<DFCNode*>(pNode->FirstChild);

    int i = 0;

    while (!IsBadReadPtr(currentChild)) {
        ImGui::PushID(i);
        RenderItem(currentChild, i);
        currentChild = reinterpret_cast<DFCNode*>(currentChild->NextSibling);
        ImGui::PopID();
        i++;
    }
}

RRSpyGUIList::RRSpyGUIList(std::shared_ptr<RRSpyState> state) : _state(state) {}
