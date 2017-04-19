//
//  ZLFBX.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/19.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLFBX_hpp
#define ZLFBX_hpp

#include <stdio.h>
#include <fbxsdk.h>

class ZLFBXModel {
protected:
    void ImportNode(FbxNode *fbxNode);
    void importMaterial(FbxNode *node);
    void importMesh(FbxNode *mesh);
    
public:
    void Init(const char *filePath);
    void Draw(); 
};

#endif /* ZLFBX_hpp */
