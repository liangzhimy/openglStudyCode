//
//  ZLDisplaylist.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/11.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLDisplaylist.hpp"

void ZLDisplaylist::Init(std::function<void()>foo) {
    displayList = glGenLists(1);
    glNewList(displayList, GL_COMPILE);
    foo();
    glEndList();
}

void ZLDisplaylist::Draw() {
    glCallList(displayList);
}