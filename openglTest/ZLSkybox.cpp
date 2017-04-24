//
//  ZLSkybox.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/10.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLSkybox.hpp"

void ZLSkybox::Init(const char *path) {
    char temp[128] = {0};
    strcpy(temp, path);
    strcat(temp, "/front.bmp");
    front = ZLTexture::LoadTexture(temp);
    strcpy(temp, path);
    strcat(temp, "/back.bmp");
    back = ZLTexture::LoadTexture(temp);
    strcpy(temp, path);
    strcat(temp, "/top.bmp");
    top = ZLTexture::LoadTexture(temp);
    strcpy(temp, path);
    strcat(temp, "/bottom.bmp");
    bottom = ZLTexture::LoadTexture(temp);
    strcpy(temp, path);
    strcat(temp, "/left.bmp");
    left = ZLTexture::LoadTexture(temp);
    strcpy(temp, path);
    strcat(temp, "/right.bmp");
    right = ZLTexture::LoadTexture(temp);
    displaylist.Init([&]()->void {
        glColor4ub(255, 255, 255, 255);
        
        float x0 = 0.5;
        float y0 = 0.5;
        float z0 = 1;
        
        //front
        glBindTexture(GL_TEXTURE_2D, front->textureId);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(-x0, -y0, -z0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3d(x0, -y0, -z0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3d(x0, y0, -z0);
        glTexCoord2d(0.0f, 1.f);
        glVertex3d(-x0, y0, -z0);
        glEnd();
        
        //left
        glBindTexture(GL_TEXTURE_2D, left->textureId);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(-x0, -y0, -z0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3d(-x0, y0, -z0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3d(-x0, y0, z0);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3d(-x0, -y0, z0);
        glEnd();
        
        //right
        glBindTexture(GL_TEXTURE_2D, right->textureId);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x0, -y0, -z0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x0, -y0, z0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x0, y0, z0);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x0, y0, -z0);
        glEnd();
        
        //top
        glBindTexture(GL_TEXTURE_2D, top->textureId);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-x0, y0, -z0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x0, y0, -z0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x0, y0, z0);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-x0, y0, z0);
        glEnd();
        
        //bottom
        glBindTexture(GL_TEXTURE_2D, bottom->textureId);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-x0, -y0, z0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(x0, -y0, z0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(x0, -y0, -z0);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-x0, -y0, -z0);
        glEnd();
        
        //back
        glBindTexture(GL_TEXTURE_2D, back->textureId);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(x0, -y0, z0);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-x0, -y0, z0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-x0, y0, z0);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(x0, y0, z0);
        glEnd();
    });
}

void ZLSkybox::Draw(float x, float y, float z) {
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glPushMatrix();
    glTranslated(x, y, z);
    displaylist.Draw();
    glPopMatrix();
}
