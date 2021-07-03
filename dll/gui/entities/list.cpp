#include <chrono>
#include "list.h"
#include "../general/structs.h"


void RenderEntityManager(EntityManager* entityManager) {
    if (entityManager == nullptr) {
        ImGui::Text("null");
        return;
    }

    if (ImGui::TreeNode("Raw Properties")) {
        RenderStructPropertyTable((char*) entityManager, GetEntityManagerProperties(), 70);
        ImGui::TreePop();
    }
}

void RenderEntityManagerEntities(EntityManager* manager) {
    if ((int) manager->VFTable == 0x008A7C18) {
        auto* entityContainer = (ClientEntity*) ((char*) manager + 0x0A38);
        RenderDFCNodes(entityContainer);
    } else {
        auto* entityContainer = (ServerEntity*) ((char*) manager + 0x0AC8);
        RenderDFCNodes(entityContainer);
    }
}

void RenderEntityArray(unsigned int pStart, unsigned int pEnd) {
    for (unsigned int i = pStart, j = 0; i < pEnd; i += 4, j++) {
        auto entityPtr = *(DFCNode**) (i);
        ImGui::PushID(i);
        RenderDFCNodeListItem(entityPtr, j);
        ImGui::PopID();
    }
}

// This is used for children of an entity
void RenderEntityLinkedList(unsigned int firstChild, unsigned int lastChild) {
    auto currentChild = reinterpret_cast<DFCNode*>(firstChild);

    int i = 0;

    while (currentChild != nullptr) {
        ImGui::PushID(i);
        RenderDFCNodeListItem(currentChild, i);
        currentChild = reinterpret_cast<DFCNode*>(currentChild->NextSibling);
        ImGui::PopID();
        i++;
    }
}

void RenderDFCNodes(ServerEntity* entitiesPtr) {
    ImGui::PushID("serverEntities");

    RenderEntityArray(entitiesPtr->OwnedObjectsStart, entitiesPtr->OwnedObjectsEnd);

    ImGui::PopID();
}

void RenderDFCNodes(ClientEntity* entitiesPtr) {
    ImGui::PushID("clientEntities");

    if (ImGui::TreeNode("Raw Properties")) {
        RenderStructPropertyTable((char*) entitiesPtr, GetServerEntityProperties(), 60);
        ImGui::TreePop();
    }

    RenderEntityArray(entitiesPtr->OwnedObjectsStart, entitiesPtr->OwnedObjectsEnd);

    ImGui::PopID();
}

ImGuiID lastIDClicked;
std::chrono::milliseconds lastClickedTime;

void RenderDFCNodeListItem(DFCNode* pEntity, int i) {
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

    if (SelectedDFCNodeID == currentID) {
        lineColour = TO_IMCOL32(listSelected);
    }

    ImDrawList* windowDrawList = ImGui::GetWindowDrawList();
    windowDrawList->AddRectFilled(lineMin, lineMax, lineColour, 2);

    if (pEntity->FirstChild != 0) {
        windowDrawList->AddCircleFilled(ImVec2(lineMin.x + 11, lineMin.y +12), 5, IM_COL32_WHITE);

        if (isOpen) {
            windowDrawList->AddCircleFilled(ImVec2(lineMin.x + 11, lineMin.y +12), 3, lineColour);
        }
    }

    if (hovered && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {

        auto now = duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()
        );

        if (lastIDClicked == currentID && now.count() - lastClickedTime.count() < 200) {
            isOpen = !isOpen;
            ImGui::GetStateStorage()->SetBool(openKey, isOpen);
        } else {
            SelectedDFCNode = pEntity;
            SelectedDFCNodeID = currentID;
        }

        lastClickedTime = now;
        lastIDClicked = currentID;
    }

    if (pEntity->FirstChild != 0) {
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32_WHITE);

        ImGui::Text(pEntity->GetTypeString().c_str());

        if (isOpen) {
            ImGui::Indent();
            RenderEntityLinkedList(pEntity->FirstChild, pEntity->LastChild);
            ImGui::Unindent();
        }

        ImGui::PopStyleColor(1);
    } else {
        ImGui::Text(pEntity->GetTypeString().c_str());
    }
}

void AddDFCNodeTreeText(DFCNode* pEntity) {
    ImGui::SameLine();
    auto pos = ImGui::GetCursorScreenPos();
    auto rect = ImGui::CalcTextSize(pEntity->GetTypeString().c_str());
    auto newMax = ImVec2(pos.x + rect.x + 8, pos.y + rect.y + 1);
    auto newMin = ImVec2(pos.x - 8, pos.y - 1);
    ImGui::GetWindowDrawList()->AddRectFilled(newMin, newMax, IM_COL32(43, 114, 64, 255), 4);
    ImGui::Text(pEntity->GetTypeString().c_str());
}