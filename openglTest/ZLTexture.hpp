//
//  ZLTexture.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/9.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLTexture_hpp
#define ZLTexture_hpp

#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <string>
#include <unordered_map>

#define GL_CLAMP_TO_EDGE 0x812F

class ZLTexture {
public:
    std::string path;
    GLuint textureId = 0;
    ZLTexture(const char *path);
    ~ZLTexture();
    
    void Init(GLenum wrapMode = GL_CLAMP_TO_EDGE);
    static ZLTexture *LoadTexture(const char *path);
    void UnloadTexture(ZLTexture *texture);
};


#endif /* ZLTexture_hpp */
