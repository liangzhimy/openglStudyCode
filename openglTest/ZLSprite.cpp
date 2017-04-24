//
//  ZLSprite.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/13.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLSprite.hpp"

void ZLSprite::SetTexture(ZLTexture *texture) {
    myTexture = texture;
}

void ZLSprite::SetRect(float x, float y, float width, float height) {
    mash[0].x = x;
    mash[0].y = y;
    mash[0].z = 0;
    
    mash[1].x = x + width;
    mash[1].y = y;
    mash[1].z = 0;
    
    mash[2].x = x + width;
    mash[2].y = y + height;
    mash[2].z = 0;
    
    mash[3].x = x;
    mash[3].y = y + height;
    mash[3].z = 0;
}

void ZLSprite::Draw() {
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glDisable(GL_DEPTH_TEST);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture->textureId);
    
    glPushMatrix();
//    glClearColor(0, 0, 0, 1);
//    glColor4b(1.0, 1.0, 1.0, 1.0);
//    
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3fv(mash[0].v);
    glTexCoord2d(1, 0);
    glVertex3fv(mash[1].v);
    glTexCoord2d(1, 1);
    glVertex3fv(mash[2].v);
    glTexCoord2d(0, 1);
    glVertex3fv(mash[3].v);
    glEnd();
    glPopMatrix();
    
    glEnable(GL_COLOR);
//    glDisable(GL_BLEND);
    
}
