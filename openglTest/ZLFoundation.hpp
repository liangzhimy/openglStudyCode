//
//  ZLFoundation.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/16.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLFoundation_hpp
#define ZLFoundation_hpp

#include <stdio.h>

struct ZLRect {
    float x, y, width, height;
};

ZLRect ZLMakeRect(float x, float y, float width, float height);

#endif /* ZLFoundation_hpp */
