//
//  ZLVector3f.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/6.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLVector3f_hpp
#define ZLVector3f_hpp

#include <stdio.h>
#include <math.h>

class ZLVector3f {
public:
    
    union {
        struct {
            float x, y, z;
        };
        float v[3];
    };
    
    ZLVector3f(float x, float y, float z);
    ZLVector3f();
    
    ZLVector3f operator*(float scaler);
    float operator*(ZLVector3f &vector);
    ZLVector3f operator+(ZLVector3f &vector);
    ZLVector3f operator-(ZLVector3f &vector);
    ZLVector3f operator^(ZLVector3f &vector);
    ZLVector3f& operator=(const ZLVector3f &vector);
    
    void Normalize();
    float Magnitude();
};

#endif /* ZLVector3f_hpp */
