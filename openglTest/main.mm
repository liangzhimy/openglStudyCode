//
//  main.m
//  openglTest
//
//  Created by zhaoliang on 2017/4/1.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include <stdio.h>
#include <OpenGL/gl.h>
#include <OpenGL/OpenGL.h>
#include "main.hpp"
#include <GLUT/GLUT.h>
#include "ZLTexture.h"
#include "ZLParse.h"
#include "ZLCamera.hpp"
#include <math.h>
#include <mach/mach_time.h>
#include <time.h>
#include "ZLTextureParse.hpp"
#include "ZLSkybox.hpp"
#include "ZLSprite.hpp"
#include "ZLGround.hpp"
#include "ZLButton.hpp"
#include "ZLFBX.hpp"

ZLParse parse;
ZLCamera camera;
ZLSkybox skybox;
uint64_t startTime;
static mach_timebase_info_data_t  sTimebaseInfo;
ZLVector3f originalPosition;
ZLGround ground;
ZLButton *spriteButton;
ZLFBXModel fbxModel;
BOOL shouldRotate = NO;

void displayTest() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glLoadIdentity();
//    glClearColor(0.1, 0.4, 1, 1.0);
    
    camera.Change3D();
    
    // update camera
    uint64_t endTime = mach_absolute_time();
    uint64_t elapseTime = endTime - startTime;
    if ( sTimebaseInfo.denom == 0 ) {
        (void)mach_timebase_info(&sTimebaseInfo);
    }
    uint64_t elapsedNano = elapseTime * sTimebaseInfo.numer / sTimebaseInfo.denom;
    float seconds = (double)elapsedNano / 1000000 / 1000;
    startTime = mach_absolute_time();
    camera.Update(seconds);
    
    // update skybox
    skybox.Draw(camera.position.x, camera.position.y, camera.position.z);
//    ground.Draw();
   
    // 光照
    float blankColor[] = {0.f, 0.f, 0.f, 1.f};
    float whiteColor[] = {1.f, 1.f, 1.f, 1.f};
    float lightPosition[] = {0.f, 1.f, 0.f, 0.f};
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, whiteColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
    float blankMat[] = {0.f, 0.f, 0.f, 1.f};
    float ambientMat[] = {0.1f, 0.1f, 0.1f, 1.f};
    float diffuseMat[] = {0.1f, 0.3f, 0.6f, 1.f};
    float spacularMat[] = {0.9f, 0.9f, 0.9f, 1.f};
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, spacularMat);
    glMaterialf(GL_FRONT, GL_SHININESS, 100.f);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);

    // texture
    ZLTextureParse *texture = ZLTextureParse::LoadTexture("/Users/liangzhimy/Desktop/OpenGL/openglTest/openglTest/test.bmp");
    glBindTexture(GL_TEXTURE_2D, texture->textureId);
    
    glPushMatrix();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_COLOR, GL_ONE);
    glTranslated(0, -2, 0);
    glRotated(180, 1, 0, 0);
    parse.Draw();
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();
    
    parse.Draw();

    glPushMatrix();
    camera.Change2D();
    glLoadIdentity();
    
    ZLTextureParse *spriteTexture = ZLTextureParse::LoadTexture("/Users/liangzhimy/Desktop/OpenGL/openglTest/openglTest/head.png");
    ZLSprite sprite;
    sprite.SetTexture(spriteTexture);
    spriteButton->SetDeafaultSprite(&sprite);
    spriteButton->SetRect(-400, 350, 50, 50);
    spriteButton->setOnClick([]()->void {
        printf("has onclicked \n ");
    });
    spriteButton->Draw();
    
    glPopMatrix();
    
//
//    float x = camera.viewWidth * .5;
//    float y = camera.viewHeight * .5;
//    float z = 0;
//    
//    float positions[] = {
//        -x, -y, z,
//        0, -y, z,
//        0, 0, z,
//        -x, 0, z
//    };
//    
//    float texcoords[] = {
//       0, 0,
//       1, 0,
//       1, 1,
//       0, 1
//    };
//    
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3.0, GL_FLOAT, 0, positions);
//    
//    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
//    
//    glDrawArrays(GL_QUADS, 0, 4);
    
    glutSwapBuffers();
    glutPostRedisplay();
}

// press keyboard
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT: {
            camera.moveRight = NO;
            camera.moveForward = NO;
            camera.moveBackward = NO;
            camera.moveLeft = YES;
            break;
        }
        case GLUT_KEY_RIGHT: {
            camera.moveLeft = NO;
            camera.moveForward = NO;
            camera.moveBackward = NO;
            camera.moveRight = YES;
            break;
        }
        case GLUT_KEY_UP: {
            camera.moveLeft = NO;
            camera.moveRight = NO;
            camera.moveBackward = NO;
            camera.moveForward = YES;
            break;
        }
        case GLUT_KEY_DOWN: {
            camera.moveLeft = NO;
            camera.moveRight = NO;
            camera.moveForward = NO;
            camera.moveBackward = YES;
            break;
        }
        default: {
            camera.moveLeft = NO;
            camera.moveRight = NO;
            camera.moveForward = NO;
            camera.moveBackward = NO;
            break;
        }
    }
    glutPostRedisplay();
}

void mouseState(int button, int state, int x, int y) {
    switch (state) {
        case GLUT_DOWN: {
            originalPosition = ZLVector3f(x, y, 0);
            shouldRotate = YES;
            glutSetCursor(GLUT_CURSOR_NONE);
            
            int modelX =  x - camera.viewWidth * .5;
            int modelY = camera.viewHeight * .5 - y;
            spriteButton->OnTouchBegin(modelX, modelY);
            
            break;
        }
        case GLUT_UP: {
            shouldRotate = NO;
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
            glutWarpPointer(originalPosition.x, originalPosition.y);
            
            int modelX =  x - camera.viewWidth * .5;
            int modelY = camera.viewHeight * .5 - y;
            spriteButton->OnTouchEnd(modelX, modelY);
            
            break;
        }
        default:
            break;
    }
}

void rotate(GLdouble deltaX, GLdouble deltaY) {
    float rotatePitchAngle = deltaY / 100;
    camera.Pitch(rotatePitchAngle);
    float rotateYawAngle = deltaX / 100;
    camera.Yaw(rotateYawAngle);
}

void mouseMove(int x, int y) {
    if (!shouldRotate) {
        return;
    }
    
    static int lastX = -1, lastY = -1;
    GLdouble deltaX, deltaY;
    deltaX = x - lastX;
    deltaY = y - lastY;
    
    if (deltaX < 0) {
        deltaX = -1;
    } else if (deltaX > 0) {
        deltaX = 1;
    }
    
    if (deltaY < 0) {
        deltaY = -1;
    } else if (deltaY > 0) {
        deltaY = 1;
    } 
    
    // do some thing
    rotate(deltaX, deltaY);
    
    lastX = x;
    lastY = y;
    glutPostRedisplay();
}

void changeSize(int w, int h) {
    skybox.Init("/Users/liangzhimy/Desktop/OpenGL/openglTest/openglTest/skybox");
    ground.Init();
    fbxModel.Init("/Users/liangzhimy/Desktop/OpenGL/openglTest/openglTest/cube.fbx");
    camera.viewWidth = w;
    camera.viewHeight = h;
    camera.Change3D();
}

int main(int argc, char * argv[]) {
    //    __readTexture();
    startTime = mach_absolute_time();
    parse.Init("/Users/liangzhimy/Desktop/OpenGL/openglTest/openglTest/Sphere.obj");
    spriteButton = new ZLButton();
   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Demo");
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(changeSize);
    glutMouseFunc(mouseState);
    glutMotionFunc(mouseMove);
    glutDisplayFunc(displayTest);
    glutMainLoop();
    
    delete spriteButton;
    
    return 0;
}
