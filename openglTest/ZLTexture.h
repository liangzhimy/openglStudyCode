//
//  ZLTexture.h
//  openglTest
//
//  Created by zhaoliang on 2017/4/1.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OpenGL/gl.h>

@interface ZLTexture : NSObject

@property (assign, nonatomic, readonly) GLuint textureId;

- (instancetype)initWithImagePath:(NSString *)imagePath; 

@end
