//
//  ZLTexture.m
//  openglTest
//
//  Created by zhaoliang on 2017/4/1.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#import "ZLTexture.h"
#import <AppKit/AppKit.h>
#import <OpenGL/OpenGL.h>
#import <OpenGL/gl.h>

@interface ZLTexture () {
    GLuint _textureId;
}

@end

@implementation ZLTexture

- (instancetype)initWithImagePath:(NSString *)imagePath {
    if (self = [super init]) {
        [self __config:imagePath];
    }
    return self;
}

- (void)__config:(NSString *)imagePath {
    NSImage *image = [[NSImage alloc] initWithContentsOfFile:imagePath];
    NSBitmapImageRep *imageRep = [[NSBitmapImageRep alloc] initWithData:image.TIFFRepresentation];
    unsigned char *bitmapData = imageRep.bitmapData;
    glGenTextures(1, &_textureId);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.size.width, image.size.height, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);
    glBindTexture(GL_TEXTURE_2D, 0);
}

- (GLuint)textureId {
    return _textureId;
}

@end
