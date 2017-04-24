//
//  ZLSkybox.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/10.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLSkybox_hpp
#define ZLSkybox_hpp

#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include "ZLTexture.hpp"
#include "ZLDisplaylist.hpp"

class ZLSkybox {
private:
    ZLDisplaylist displaylist;
public:
    ZLTexture *front, *back, *right, *left, *top, *bottom;
    void Init(const char *path);
    void Draw(float x, float y, float z);
};

#endif /* ZLSkybox_hpp */
