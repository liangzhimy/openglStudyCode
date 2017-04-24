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
#include <vector>
#include <string>
#include <unordered_map>
#include "ZLVector3f.hpp"
#include "ZLTexture.hpp"

typedef enum : int {
    ZLMeterailTypeUnknow,
    ZLMeterailTypePhong,
    ZLMeterailTypeLambert,
} ZLMeterailType;

struct ZLMat {
    ZLMeterailType type;
    std::string diffuseColorTexture;
    ZLTexture *texture; 
};

class ZLFBXModel {
private:
    std::string getMaterialPath(const char *path);
    
protected:
    
    std::vector<std::vector<int>> indices; 
    
    void importPositons(FbxMesh *mesh, std::vector<ZLVector3f> &positions);
    void importNode(FbxNode *fbxNode);
    void importMaterial(FbxNode *node);
    void importMesh(FbxMesh *mesh);
    
public:
    std::string fbxPath;
    std::vector<ZLMat *> materials;
    std::unordered_map<int, int> materialIndexs;
    
    void Init(const char *filePath);
    void Draw(); 
};

#endif /* ZLFBX_hpp */
