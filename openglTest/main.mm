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

ZLParse parse;

ZLTexture *__readTexture() {
    ZLTexture *texture = [[ZLTexture alloc] initWithImagePath:@"/Users/liangzhimy/Documents/work/iOSTest/Demo/openglTest/openglTest/Metal_V1_1012.JPG"];
    return texture;
}

void display() {
    
    //    CGLContextObj ctx;
    //    CGLPixelFormatObj pix;
    //    GLint npix;
    //
    //    CGLPixelFormatAttribute attributs[] {
    //        kCGLPFAOpenGLProfile,
    ////        kCGLDoubleBufferBit
    //    };
    //
    //    CGLChoosePixelFormat(attributs, &pix, &npix);
    //    CGLCreateContext(pix, NULL, &npix);
    //    CGLSetCurrentContext(ctx);
    
    

    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1, 0.4, 1, 1.0);
    
    
    // -- set matrix
    //    // 选中投影矩阵
    //    glMatrixMode(GL_PROJECTION);
    //    gluPerspective(60.f, 600.f / 600.f, 0.1, 1000.f);
    //    // 模型视口矩阵
    //    glMatrixMode(GL_MODELVIEW);
    //    glLoadIdentity();
    
    // set white color
    glColor4ub(0, 0, 255, 255);
    //     start draw someting
    //    glPointSize(20.0f);
    //    glBegin(GL_POINTS);
    //    glVertex3f(-0.5f, 0.f, 0.f);
    //    glVertex3f(0.f, 0.f, 0.f);
    //    glVertex3f(0.5f, 0.f, 0.f);
    //    glEnd();
    
    // line
    //    glLineWidth(8.f);
    //    glBegin(GL_LINE_LOOP);
    //    glVertex2f(-0.5, -0.5);
    //    glColor4ub(255, 0, 255, 255);
    //    glVertex2f(0, 0.5);
    //    glColor4ub(255, 0, 0, 255);
    //    glVertex2f(0.5, -0.5);
    //    glEnd();
    
    //    // 剪裁， 只显示正面， 不绘制2面， 逆时针方向默认是正面， 正时针方面为反面。
    //    // 当画triangle时逆时针是可以看到的，正时针是看不到的。
    //    glEnable(GL_CULL_FACE);
    //    // 指定正时针方向为正面， 这时要按正时针方面画才能被看到。
    ////    glFrontFace(GL_CW);
    //    // 线框模式
    //    glPolygonMode(GL_FRONT, GL_LINE);
    //
    //    glLineWidth(2.f);
    //    // 正时针方向画
    //    glBegin(GL_TRIANGLES);
    //    glVertex2d(-0.5, 0);
    //    glVertex2d(0, .1);
    //    glVertex2d(0, -.1);
    //    glEnd();
    //
    
    glEnable(GL_DEPTH_TEST);
    
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
    glMaterialfv(GL_FRONT, GL_SPECULAR, blankMat);
    glMaterialf(GL_FRONT, GL_SHININESS, 100.f);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
//
//    ZLTexture *texture = __readTexture();
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, texture.textureId);
//    
//    
//    // 逆时针方向画
//    glColor4ub(255, 0, 0, 255);
//    glBegin(GL_TRIANGLES);
//    
//    glTexCoord2d(0.0f, 0.0f);
//    glNormal3f(0, 0.1, 0.f);
//    glVertex3d(0.5, 0, -0.5);
//    
//    glNormal3f(0, 0.1, 0.f);
//    glTexCoord2d(1.0f, 0.0f);
//    glVertex3d(0.8, 0, -0.5);
//    
//    glNormal3f(0, 0.2, 0.f);
//    glTexCoord2d(0.5f, 0.5f);
//    glVertex3d(0.65, 0.5, -0.5);
//    
//    glEnd();
    
    
    // 图元 4边形
    //    glBegin(GL_QUADS);
    //
    //    glVertex2d(0, .6);
    //    glVertex2d(.5, .6);
    //    glVertex2d(.5, .9);
    //    glVertex2d(0, .9);
    //
    //    glEnd();
    
    //    glPushMatrix();
    //
    ////    glLoadIdentity();
    //    glScalef(2.0, 1.0, 1.0);
    //    glTranslatef(0.01, -0.5, 0.f);
    //    glRotatef(30.f, 0, 0, 1.0f);
    //    glColor4ub(255.0, 0, 0, 1.0);
    //    // 图元 多边形
    //    glBegin(GL_POLYGON);
    //
    //    glVertex2d(0, .6);
    //    glVertex2d(.5, .6);
    //    glVertex2d(.5, .7);
    //    glVertex2d(.3, 0.9);
    //    glVertex2d(0, .9);
    //    
    //    glEnd();
    //    
    //    glPopMatrix();
    
    
    
    // load object
    
    glEnable(GL_CULL_FACE);
//    glEnable(GL_DEPTH_TEST);
//    glPolygonMode(GL_FRONT, GL_LINE);
//    glClearColor(255, 255, 255, 255);
//    glClear(GL_DEPTH);
    
    glPushMatrix();
    
//    glColor4b(0, 0, 0, 1);
    glRotated(30, 0, 1, 0);
    glTranslated(0, 0, -0.01);
    glScaled(0.5, 0.5, 0.5);
//    glRotated(10, 1, 0, 0);
    
    
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < parse.objFaces.size(); i++) {
        ZLFace face = parse.objFaces[i];
        for (int j = 0; j < 3; j++) {
            if (face.textures[j].numbers[0] != -1) {
                glTexCoord3d(face.textures[j].numbers[0], face.textures[j].numbers[1], face.textures[j].numbers[2]);
            }
            
            if (face.normals[j].numbers[0] != -1) {
                glNormal3d(face.normals[j].numbers[0], face.normals[j].numbers[1], face.normals[j].numbers[2]);
            }
            
            glVertex3d(face.positions[j].numbers[0], face.positions[j].numbers[1], face.positions[j].numbers[2]);
//            printf("%f, %f, %f", face.positions[j].numbers[0], face.positions[j].numbers[1], face.positions[j].numbers[2]);
        }
//        printf("\n"); 
    }
    glEnd();
    
    glPopMatrix();
    
    glFlush();
}

// press keyboard
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP: {
            break;
        }
        case GLUT_KEY_DOWN: {
            break;
        }
        case GLUT_KEY_LEFT: {
            break;
        }
        case GLUT_KEY_RIGHT: {
            break;
        }
        default: {
            break;
        }
    }
    glutPostRedisplay();
}

int main(int argc, char * argv[]) {
    parse.Init("/Users/liangzhimy/Documents/work/iOSTest/Demo/openglTest/openglTest/Sphere.obj");
    
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Demo");
    glutSpecialFunc(specialKeys);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
