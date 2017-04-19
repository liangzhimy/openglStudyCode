//
//  ZLUtility.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/18.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLUtility.hpp"
#include <math.h>
#include <iostream>

static const float __ZLRandMax = 10;

float ZLUtility::randf() {
    return std::rand() / RAND_MAX;
}

float ZLUtility::srandf() {
    return randf() - 0.5;
}