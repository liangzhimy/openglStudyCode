//
//  ZLTextureParse.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/9.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLTextureParse.hpp"
#include <SDL2_image/SDL_image.h>
#import "SOIL.h"

static std::unordered_map<std::string, ZLTextureParse *>cache;

void ZLTextureParse::Init(GLenum wrapMode) {
    textureId = SOIL_load_OGL_texture(
                                      this->path.c_str(),
                                      SOIL_LOAD_AUTO,
                                      SOIL_CREATE_NEW_ID,
                                      SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                      );
    if (wrapMode == GL_CLAMP_TO_EDGE) {
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    return;
//    SDL_Surface *surface = IMG_Load(this->path.c_str());
//    if (surface == NULL) {
//        printf("error load bmp only!");
//        return;
//    }
//   
//    int mode = GL_RGB; // Set the mode
//    if(surface->format->BytesPerPixel == 4) {
//        mode = GL_RGBA;
//    }
//    
//    glEnable(GL_TEXTURE_2D);
//    glGenTextures(1, &textureId);
//    glBindTexture(GL_TEXTURE_2D, textureId);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//    glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
//    glBindTexture(GL_TEXTURE_2D, 0);
//    
//    SDL_FreeSurface(surface);
}

ZLTextureParse::ZLTextureParse(const char *path) {
    this->path = path;
}

ZLTextureParse::~ZLTextureParse() {
}

ZLTextureParse *ZLTextureParse::LoadTexture(const char *path) {
    if (cache.find(path) != cache.end()) {
        return cache[path];
    }
    
    ZLTextureParse *texture = new ZLTextureParse(path);
    texture->Init();
    cache.insert(std::pair<std::string, ZLTextureParse *>(path, texture));
    return texture;
}

void ZLTextureParse::UnloadTexture(ZLTextureParse *texture) {
    auto iter = cache.find(texture->path.c_str());
    if (iter != cache.end()) {
        cache.erase(iter);
        glDeleteTextures(1, &texture->textureId);
        delete texture;
    }
}