//
//  ZLFBX.cpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/19.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#include "ZLFBX.hpp"

void ZLFBXModel::importPositons(FbxMesh *mesh, std::vector<ZLVector3f> &positions) {
    int count = mesh->GetControlPointsCount();
    positions.resize(count);
    for (int i = 0; i < count; i++) {
        FbxVector4 controlPoint = mesh->GetControlPointAt(i);
        positions[i].x = static_cast<float>(controlPoint.mData[0]);
        positions[i].y = static_cast<float>(controlPoint.mData[1]);
        positions[i].z = static_cast<float>(controlPoint.mData[2]);
    }
}

void ZLFBXModel::importMesh(FbxMesh *mesh) {
    std::vector<ZLVector3f> positions;
    importPositons(mesh, positions);
    
    FbxStringList uvNameList;
    mesh->GetUVSetNames(uvNameList);
    
    int polygonCont = mesh->GetPolygonCount();
    
    int polygonIndexCount = 0;
    for (int i = 0; i < polygonCont; i++) {
        polygonIndexCount += mesh->GetPolygonSize(i);
        
    }
    
    vertices = new std::vector<ZLFace>(polygonIndexCount);
    
    for (int i = 0; i < polygonCont; i++) {
        int polygonSize = mesh->GetPolygonSize(i);
        ZLFace face = ZLFace();
        
        for (int j = 0; j < polygonSize; j++) {
            // vector
            int index = mesh->GetPolygonVertex(i, j);
//            printf("position: %f %f %f\n ", positions[index].x, positions[index].y, positions[index].z);
            
            // normal
            FbxVector4 normal;
            if (mesh->GetPolygonVertexNormal(i, j, normal)) {
//                printf("normal: %f %f %f \n", normal.mData[0], normal.mData[1], normal[2]);
            }
            
            // coord
            FbxVector2 uv;
            bool unmapped = true;
            if (mesh->GetPolygonVertexUV(i, j, uvNameList.GetItemAt(0)->mString.Buffer(), uv, unmapped)) {
//                printf("uv: %f %f\n", uv.mData[0], uv.mData[1]);
            }
        }
    }
}

std::string ZLFBXModel::getMaterialPath(const char *path) {
    char paths[256] = {0};
    strcpy(paths, path);
    memset(paths + strlen(path) - 4, 0, 4);
    strcat(paths, ".fbm/");
    return std::string(paths);
}

void ZLFBXModel::importMaterial(FbxNode *node) {
    std::string path = getMaterialPath(fbxPath.c_str());

    int materialCount = node->GetMaterialCount();
    ZLMeterailType meterailType = ZLMeterailTypeUnknow;
    
    for (int i = 0; i < materialCount; i++) {
        FbxSurfaceMaterial *surfaceMaterial = node->GetMaterial(i);
        if (FbxSurfaceLambert::ClassId == surfaceMaterial->GetClassId()) {
            meterailType = ZLMeterailTypeLambert;
            printf("import lambert material. %d\n", i);
        } else if (FbxSurfacePhong::ClassId == surfaceMaterial->GetClassId()) {
            meterailType = ZLMeterailTypePhong;
            printf("import pong material. %d\n", i);
        } else {
            printf("can not import material.");
        }
        
        FbxProperty property = surfaceMaterial->FindProperty(FbxLayerElement::sTextureChannelNames[0]); // diffuse texture
        if (property.IsValid()) {
            int textureCount = property.GetSrcObjectCount();
            int currentMaterialIndex = -1;
            FbxTexture *texture = property.GetSrcObject<FbxTexture>();
            if (texture) {
                printf("texture name: %s\n", texture->GetName());
                int currentMatCount = (int)materials.size();
                for (int k = 0; k < currentMatCount; k++) {
                    if (meterailType == materials[k]->type) {
                        if (strcmp(texture->GetName(), materials[k]->diffuseColorTexture.c_str()) == 0) {
                            currentMaterialIndex = k;
                            break;
                        }
                    }
                }
                
                if (currentMaterialIndex == -1) {
                    ZLMat *mat = new ZLMat();
                    mat->type = meterailType;
                    mat->diffuseColorTexture = texture->GetName();
                    currentMaterialIndex = (int)materials.size();
                    std::string texturePathName = path + texture->GetName();
                    printf("texture path name : %s\n", texturePathName.c_str());
                    ZLTexture *texture = ZLTexture::LoadTexture(texturePathName.c_str());
                    mat->texture = texture;
                    materials.push_back(mat);
                }
                
                materialIndexs.insert(std::pair<int, int>(i, currentMaterialIndex));
            }
        }
    }
   
}

void ZLFBXModel::importNode(FbxNode *node) {
    printf("decode %s \n", node->GetName());
    if (node->GetMesh()) {
        printf("decode mesh of %s\n", node->GetName());
        importMaterial(node);
        importMesh(node->GetMesh());
    }
    
    int childNodeCount = node->GetChildCount();
    for (int i = 0; i < childNodeCount; i++) {
        importNode(node->GetChild(i));
    }
}

void ZLFBXModel::Init(const char *filePath) {
    fbxPath = filePath;
    
    FbxManager *fbxManager = FbxManager::Create();
    FbxIOSettings *fbxIOSettings = FbxIOSettings::Create(fbxManager, IOSROOT);
    FbxImporter *fbxImporter = FbxImporter::Create(fbxManager, "");
    fbxManager->SetIOSettings(fbxIOSettings);
    
    if (fbxImporter->Initialize(filePath)) {
        FbxScene *scene = FbxScene::Create(fbxManager, "");
        fbxImporter->Import(scene);
        FbxNode *rootNode = scene->GetRootNode();
        importNode(rootNode);
        scene->Destroy();
    }
    
    fbxImporter->Destroy();
    fbxIOSettings->Destroy();
    fbxManager->Destroy();
}

void ZLFBXModel::Draw() {
}
