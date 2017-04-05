//
//  ZLStruct.h
//  openglTest
//
//  Created by zhaoliang on 2017/4/4.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLStruct_h
#define ZLStruct_h

struct ZLNumber {
    float numbers[3] = {-1, -1, -1};
};

struct ZLIndex {
    int positionIndex = -1;
    int textureIndex = -1;
    int normalIndex = -1;
};

struct ZLFaceIndex {
    struct ZLIndex indexs[3];
};

struct ZLFace {
    struct ZLNumber positions[3];
    struct ZLNumber textures[3];
    struct ZLNumber normals[3];
};

#endif /* ZLStruct_h */
