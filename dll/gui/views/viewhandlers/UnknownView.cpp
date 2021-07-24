//
// Created by Sophie on 11/07/2021.
//

#include "UnknownView.h"
#include "../../general/structs.h"

void UnknownView::RenderProperties(void* pVoid) {
    RenderStructPropertyTable((char*) pVoid, std::vector<char*>{}, 200);
}
