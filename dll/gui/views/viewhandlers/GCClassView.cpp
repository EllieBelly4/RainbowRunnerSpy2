//
// Created by Sophie on 05/07/2021.
//

#include "GCClassView.h"
#include "../../../common.h"
#include "../../general/gui_functions.h"

void GCClassView::RenderProperties(GCClass* pClass) {
    BeginPropertyTable("gcclass");

    if (!IsBadReadPtr(pClass->TypeName)) {
        RenderProperty("TypeName", pClass->TypeName->ToString());
    }

    if (!IsBadReadPtr(pClass->FQTypeName)) {
        RenderProperty("FQTypeName", pClass->FQTypeName->ToString());
    }

    if (pClass->GCTypeHash != 0) {
        RenderProperty("GCTypeHash", IntToHex(pClass->GCTypeHash));
    }

    EndPropertyTable();
}
