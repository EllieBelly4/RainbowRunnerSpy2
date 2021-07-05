//
// Created by Sophie on 03/07/2021.
//

#include "properties.h"
#include "../../../lib/imgui/imgui.h"
#include "../general/structs.h"
#include "../../datatypes/GCProperties.h"
#include "../general/colours.h"
#include "../../common.h"
#include "../general/gui_functions.h"

void RenderGCProperties(GCProperties* properties) {
    if (properties->Unk2) {
        RenderProperty("Unk2", std::__cxx11::to_string(properties->Unk2));
    }
}

void RenderMeleeWeaponProperties(MeleeWeapon* pWeapon) {
}

void RenderGCCLass(GCClass* pClass) {
    if (!IsBadReadPtr(pClass->TypeName)) {
        RenderProperty("TypeName", pClass->TypeName->ToString());
    }

    if (!IsBadReadPtr(pClass->FQTypeName)) {
        RenderProperty("FQTypeName", pClass->FQTypeName->ToString());
    }

    if (pClass->GCTypeHash != 0) {
        RenderProperty("GCTypeHash", IntToHex(pClass->GCTypeHash));
    }
}

void RenderPlayerProperties(Player* pPlayer) {
    if (!IsBadReadPtr(pPlayer->Name)) {
        RenderProperty("Name", pPlayer->Name->ToString());
    }
}
//
//void RenderAvatarProperties(Avatar* pAvatar) {
//    std::string stateString;
//
//    if ((pAvatar->SomeState2 & 0x40) > 0) {
//        stateString += "Moving |";
//    } else {
//        stateString = "Standing |";
//    }
//
//    stateString = stateString.substr(0, stateString.length() - 2);
//
//    RenderProperty("State", stateString);
//
//    std::string posString;
//
//    posString += "X: " + std::__cxx11::to_string(pAvatar->posX_maybe);
//    posString += " Y: " + std::__cxx11::to_string(pAvatar->posY_maybe);
//
//    RenderProperty("Position", posString);
//    RenderProperty("Rotation", std::to_string((float) pAvatar->rotation / (float) 255));
//}

void RenderDFCNodeProperties(DFCNode* pEntity) {
    auto vftable = (int) pEntity->VFTable;
    char hexBuf[64];
    std::string hexStr;

    if (!IsBadReadPtr(pEntity->GCClass)) {
        RenderGCCLass(pEntity->GCClass);
    }

    sprintf(hexBuf, "0x%08x", reinterpret_cast<int>(pEntity));
    hexStr = hexBuf;
    RenderProperty("Location", hexStr);

    sprintf(hexBuf, "0x%08x", vftable);
    hexStr = hexBuf;
    RenderProperty("VFTable", hexStr);

    RenderProperty("SlotID (If Item)", std::__cxx11::to_string(pEntity->unk_24));
    RenderProperty("UnkShort1", std::__cxx11::to_string(pEntity->unk_29));
    RenderProperty("UnkShort2", std::__cxx11::to_string(pEntity->unk_30));

    RenderNumberProperty("unk_0", pEntity->unk_0);
    RenderNumberProperty("unk_1", pEntity->unk_1);
    RenderNumberProperty("unk_2", pEntity->unk_2);
    RenderNumberProperty("unk_7", pEntity->unk_7);
    RenderNumberProperty("unk_8", pEntity->unk_8);
    RenderNumberProperty("unk_9", pEntity->unk_9);
    RenderNumberProperty("unk_12", pEntity->unk_12);
    RenderNumberProperty("unk_14", pEntity->unk_14);
    RenderNumberProperty("unk_15", pEntity->unk_15);
    RenderNumberProperty("unk_16", pEntity->unk_16);
    RenderNumberProperty("unk_17", pEntity->unk_17);
    RenderNumberProperty("unk_18", pEntity->unk_18);
    RenderNumberProperty("unk_22", pEntity->unk_22);
    RenderNumberProperty("unk_23", pEntity->unk_23);
    RenderNumberProperty("unk_24", pEntity->unk_24);
    RenderNumberProperty("unk_25", pEntity->unk_25);
    RenderNumberProperty("unk_26", pEntity->unk_26);
    RenderNumberProperty("unk_27", pEntity->unk_27);
    RenderNumberProperty("unk_28", pEntity->unk_28);
    RenderNumberProperty("unk_29", pEntity->unk_29);
    RenderNumberProperty("unk_30", pEntity->unk_30);
    RenderNumberProperty("unk_31", pEntity->unk_31);
    RenderNumberProperty("unk_32", pEntity->unk_32);
    RenderNumberProperty("unk_33", pEntity->unk_33);
}

void RenderNumberProperty(const std::string &propertyName, unsigned int number) {
    char hexVal[128];
    auto simpleStr = std::to_string(number);

    ImGui::TableNextColumn();
    ImGui::TextColored(propertyColour, propertyName.c_str());

    ImGui::TableNextColumn();
    ImGui::Text(simpleStr.c_str());

    ImGui::SameLine();

    ImGui::PushID((propertyName + "col1").c_str());
    AddCopyText(simpleStr);
    ImGui::PopID();

    ImGui::TableNextColumn();

    sprintf(hexVal, "0x%08X", number);
    ImGui::Text(hexVal);
    ImGui::SameLine();

    ImGui::PushID((propertyName + "col2").c_str());
    AddCopyText(hexVal);
    ImGui::PopID();

    ImGui::TableNextRow();
}

void RenderProperty(const std::string &propertyName, const std::string &hexStr) {
    ImGui::TableNextColumn();
    ImGui::TextColored(propertyColour, propertyName.c_str());

    ImGui::TableNextColumn();
    ImGui::Text(hexStr.c_str());

    ImGui::SameLine();
    ImGui::PushID((propertyName + "col1").c_str());
    AddCopyText(hexStr);
    ImGui::PopID();
    ImGui::TableNextRow();
}