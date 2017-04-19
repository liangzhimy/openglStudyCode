//
//  ZLGround.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/14.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLGround.hpp"
#include "ZLDisplaylist.hpp"
#include <OpenGL/gl.h>
#include <OpenGL/OpenGL.h>

void ZLGround::Init() {
    groundDisplay.Init([&]()->void{
        glBegin(GL_QUADS);
        
        int x = 0, z = 0, step = 2;
        int number = 20;
        float dy = -1;
        float offsetX = step * -10;
        float offsetZ = step * -10;
        
        for (x = 0; x < number; x++) {
            float dx = offsetX + x * step;
            for (z = 0; z < number; z++) {
                float dz = offsetZ + z * step;
                
                if ((z%2)^(x%2)) {
                    glColor4b(41, 41, 41, 255);
                } else {
                    glColor4b(200, 200, 200, 255);
                }
                
                glVertex3d(dx, dy, dz);
                glVertex3d(dx + step, dy, dz);
                glVertex3d(dx + step, dy, dz - step);
                glVertex3d(dx, dy, dz - step);
            }
        }
        
        glEnd();
    });
}

void ZLGround::Draw() {
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);
    glPushMatrix();
    groundDisplay.Draw();
    glPopMatrix(); 
}
