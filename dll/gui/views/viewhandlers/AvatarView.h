//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_AVATARVIEW_H
#define RRSPY2TESTAPP_AVATARVIEW_H


#include "../../../gameobjects/Entities/Avatar.h"
#include "ViewHandler.h"

class AvatarView : ViewHandler {
public:
    static void RenderProperties(Avatar* entity);
};


#endif //RRSPY2TESTAPP_AVATARVIEW_H
