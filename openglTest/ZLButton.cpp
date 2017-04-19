//
//  ZLButton.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/16.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLButton.hpp"

ZLButton::ZLButton() {
    
}

void ZLButton::OnTouchBegin(int x, int y) {
    if (x > rect.x && x < (rect.x + rect.width) &&
        y > rect.y && y < (rect.y + rect.height)) {
        translateX = -4;
    }
}

void ZLButton::OnTouchEnd(int x, int y) {
    if (x > rect.x && x < (rect.x + rect.width) &&
        y > rect.y && y < (rect.y + rect.height)) {
        if (clickEvent != nullptr) {
            clickEvent();
        }
    }
    translateX = 0;
}

void ZLButton::setOnClick(std::function<void()>foo) {
    clickEvent = foo;
}

void ZLButton::SetRect(float x, float y, float width, float height) {
    rect = ZLMakeRect(x, y, width, height);
    defaultSprite->SetRect(x, y, width, height);
}

void ZLButton::SetDeafaultSprite(ZLSprite *sprite) {
    defaultSprite = sprite;
}

void ZLButton::Draw() {
    glPushMatrix();
    glTranslated(0, translateX, 0);
    defaultSprite->Draw();
    glPopMatrix();
//    ZLRenderableObject::Draw();
}
