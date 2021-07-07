//
// Created by Sophie on 04/07/2021.
//

#include "RRSpyGUIBaseEntityWrapper.h"

RRSpyGUIBaseEntityWrapper::RRSpyGUIBaseEntityWrapper(std::string name) : Name(name) {}

RRSpyGUIBaseEntityWrapper::RRSpyGUIBaseEntityWrapper(std::string name, ViewHandler* view) : Name(name), View(view) {

}

