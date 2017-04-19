//
//  ZLCamera.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/6.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLCamera.hpp"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/OpenGL.h>

ZLCamera::ZLCamera():position(0, 0, 10), viewCenter(0, 0, 9), up(0, 1.0, 0), moveLeft(false), moveRight(false), moveForward(false), moveBackward(false) {
}

ZLCamera::~ZLCamera() {
    
}

void ZLCamera::rotateView(float angle, float x, float y, float z) {
    float C = cosf(angle);
    float S = sinf(angle);
    
    ZLVector3f viewDirection = viewCenter - position;
    ZLVector3f newDirection;
    
    ZLVector3f tmpX = ZLVector3f(C+x*x*(1-C), x*y*(1-C)-z*S, x*z*(1-C)+y*S);
    newDirection.x = tmpX * viewDirection;
    
    ZLVector3f tmpY = ZLVector3f(x*y*(1-C)+z*S, C+y*y*(1-C), y*z*(1-C)-x*S);
    newDirection.y = tmpY * viewDirection;
    
    ZLVector3f tmpZ = ZLVector3f(x*z*(1-C)-y*S, y*z*(1-C)+x*S, C+z*z*(1-C));
    newDirection.z = tmpZ * viewDirection;
    
    viewCenter = position + newDirection;
}

void  ZLCamera::Yaw(float angle) {
    rotateView(angle, up.x, up.y, up.z); 
}

void ZLCamera::Pitch(float angle) {
    ZLVector3f viewDirection = viewCenter - position;
    viewDirection.Normalize();
    ZLVector3f rightDirection = viewDirection ^ up;
    rightDirection.Normalize();
    rotateView(angle, rightDirection.x, rightDirection.y, rightDirection.z);
}

void ZLCamera::Update(float deltaTime) {
    float speed = 5.f;
    float distance = deltaTime * speed;
    float rotateSpeed = 1.f;
    
    if (moveLeft) {
//        rotateView(rotateSpeed * deltaTime, up.x, up.y, up.z);
        ZLVector3f direction = ZLVector3f(1, 0, 0);
        direction.Normalize();
        ZLVector3f tmp = direction * distance;
        viewCenter = viewCenter + tmp;
        position = position + tmp;
    }
    
    if (moveRight) {
//        rotateView(-rotateSpeed * deltaTime, up.x, up.y, up.z);
        ZLVector3f direction = ZLVector3f(-1, 0, 0);
        direction.Normalize(); 
        ZLVector3f tmp = direction * distance;
        viewCenter = viewCenter + tmp;
        position = position + tmp;
    }
    
    if (moveForward) {
        ZLVector3f direction = ZLVector3f(0, 0, 1);
        direction.Normalize();
        ZLVector3f tmp = direction * distance;
        viewCenter = viewCenter + tmp;
        position = position + tmp;
    }
    
    if (moveBackward) {
        ZLVector3f direction = ZLVector3f(0, 0, -1);
        direction.Normalize();
        ZLVector3f tmp = direction * distance;
        viewCenter = viewCenter + tmp;
        position = position + tmp;
    }
    
    // set mode view matrix
    
    gluLookAt(position.x, position.y, position.z, viewCenter.x, viewCenter.y, viewCenter.z, up.x, up.y, up.z);
}

void ZLCamera::Change2D() {
    glViewport(0, 0, viewWidth, viewHeight);
    // 选中投影矩阵
    glMatrixMode(GL_PROJECTION);
    // 设置透视投影矩阵
    glLoadIdentity();
    gluOrtho2D(-viewWidth * .5, viewWidth * .5, -viewHeight * .5, viewHeight * .5);
    glMatrixMode(GL_MODELVIEW);
}

void ZLCamera::Change3D() {
    // 视口大小
    glViewport(0, 0, viewWidth, viewHeight);
    // 选中投影矩阵
    glMatrixMode(GL_PROJECTION);
    // 设置透视投影矩阵
    glLoadIdentity();
    gluPerspective(50.0, (float)viewHeight / (float)viewHeight, 0.1f, 1000.f);
    glMatrixMode(GL_MODELVIEW);
}
