//
//  ZLCamera.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/6.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLCamera_hpp
#define ZLCamera_hpp

#include <stdio.h>
#include "ZLVector3f.hpp"

class ZLCamera {
private:
    void rotateView(float angle, float x, float y, float z);
    
public:
    ZLVector3f position;
    ZLVector3f viewCenter;
    ZLVector3f up;
    
    float viewWidth, viewHeight;
    
    bool moveLeft;
    bool moveRight;
    bool moveForward;
    bool moveBackward;
    
     ZLCamera();
    ~ZLCamera();
  
    void Update(float deltaTime);
    
    void Yaw(float angle);
    void Pitch(float angle);
    
    void Change2D();
    void Change3D();
};

#endif /* ZLCamera_hpp */
