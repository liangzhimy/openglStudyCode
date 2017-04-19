//
//  ZLVector3f.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/6.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLVector3f.hpp"

ZLVector3f::ZLVector3f() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

ZLVector3f::ZLVector3f(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

ZLVector3f ZLVector3f::operator *(float scaler) {
    return ZLVector3f(x * scaler, y * scaler, z * scaler);
}

float ZLVector3f::operator*(ZLVector3f &vector) {
    return x * vector.x + y * vector.y + z * vector.z;
}

ZLVector3f ZLVector3f::operator^(ZLVector3f &vector) {
    return ZLVector3f(y * vector.z - z*vector.y, x * vector.z - z * vector.x, x * vector.y - y * vector.x);
}

ZLVector3f ZLVector3f::operator +(ZLVector3f &vector) {
    return ZLVector3f(x + vector.x, y + vector.y, z + vector.z);
}

ZLVector3f ZLVector3f::operator -(ZLVector3f &vector) {
    return ZLVector3f(x - vector.x, y - vector.y, z - vector.z);
}

ZLVector3f& ZLVector3f::operator=(const ZLVector3f &vector) {
    x = vector.x;
    y = vector.y;
    z = vector.z;
    return *this;
}

void ZLVector3f::Normalize() {
    float len = Magnitude();
    x /= len;
    y /= len;
    z /= len;
}

float ZLVector3f::Magnitude() {
    return sqrt(x * x + y * y + z * z);
}
