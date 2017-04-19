//
//  ZLParse.h
//  openglTest
//
//  Created by zhaoliang on 2017/4/4.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLParse_h
#define ZLParse_h
#include "ZLStruct.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

class ZLParse {
public:
    std::vector<ZLFace> objFaces;
    
private:
    void splitString(const std::string &txt, std::vector<std::string> &strs, char ch);
    void parseAndPrintLine(const std::string & line, const char * coordinateType, ZLNumber &number);
    void parsePolyLine(const std::string &line, ZLFaceIndex &face);
    
public:
    ZLParse();
    ~ZLParse();
    
    void Init(const char *filePath);
    void Draw();
};


#endif /* ZLParse_h */
