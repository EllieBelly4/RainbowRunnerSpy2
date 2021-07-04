//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_VIEWHANDLER_H
#define RRSPY2TESTAPP_VIEWHANDLER_H

#include <string>

class ViewHandler {
protected:
    static void RenderProperty(const std::string& name, const std::string& value);

    static bool BeginPropertyTable();

    static void EndPropertyTable();
};


#endif //RRSPY2TESTAPP_VIEWHANDLER_H
