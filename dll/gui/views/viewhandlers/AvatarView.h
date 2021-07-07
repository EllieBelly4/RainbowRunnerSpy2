//
// Created by Sophie on 04/07/2021.
//

#ifndef RRSPY2TESTAPP_AVATARVIEW_H
#define RRSPY2TESTAPP_AVATARVIEW_H


#include "../../../gameobjects/Entities/Avatar.h"
#include "ViewHandler.h"
#include "EntityView.h"

class AvatarView : public EntityView {
public:
    static void RenderProperties(Avatar* pEntity);

    void RenderProperties(void* pVoid) override;
};


#endif //RRSPY2TESTAPP_AVATARVIEW_H
