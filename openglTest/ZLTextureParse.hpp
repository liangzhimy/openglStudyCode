//
//  ZLTextureParse.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/9.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLTextureParse_hpp
#define ZLTextureParse_hpp

#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <string>
#include <unordered_map>

#define GL_CLAMP_TO_EDGE 0x812F

class ZLTextureParse {
public:
    std::string path;
    GLuint textureId = 0;
    ZLTextureParse(const char *path);
    ~ZLTextureParse();
    
    void Init(GLenum wrapMode = GL_CLAMP_TO_EDGE);
    static ZLTextureParse *LoadTexture(const char *path);
    void UnloadTexture(ZLTextureParse *texture);
};


#endif /* ZLTextureParse_hpp */
