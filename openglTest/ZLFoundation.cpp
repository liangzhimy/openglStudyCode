//
//  ZLFoundation.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/16.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLFoundation.hpp"

ZLRect ZLMakeRect(float x, float y, float width, float height) {
    ZLRect rect;
    rect.x = x;
    rect.y = y;
    rect.width = width;
    rect.height = height;
    return rect;
}