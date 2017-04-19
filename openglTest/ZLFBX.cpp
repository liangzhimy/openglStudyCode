//
//  ZLFBX.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/19.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLFBX.hpp"

void ZLFBXModel::importMesh(FbxNode *mesh) {
    
}

void ZLFBXModel::importMaterial(FbxNode *node) {
    
}

void ZLFBXModel::ImportNode(FbxNode *node) {
    printf("decode %s \n", node->GetName());
    if (node->GetMesh()) {
        printf("decode mesh of %s\n", node->GetName());
    }
    
    int childNodeCount = node->GetChildCount();
    for (int i = 0; i < childNodeCount; i++) {
        ImportNode(node->GetChild(i));
    }
}

void ZLFBXModel::Init(const char *filePath) {
    FbxManager *fbxManager = FbxManager::Create();
    FbxIOSettings *fbxIOSettings = FbxIOSettings::Create(fbxManager, IOSROOT);
    FbxImporter *fbxImporter = FbxImporter::Create(fbxManager, "");
    fbxManager->SetIOSettings(fbxIOSettings);
    
    if (fbxImporter->Initialize(filePath)) {
        FbxScene *scene = FbxScene::Create(fbxManager, "");
        fbxImporter->Import(scene);
        FbxNode *rootNode = scene->GetRootNode();
        ImportNode(rootNode);
        scene->Destroy();
    }
    
    fbxImporter->Destroy();
    fbxIOSettings->Destroy();
    fbxManager->Destroy();
}

void ZLFBXModel::Draw() {
}
