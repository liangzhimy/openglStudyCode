#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "ZLParse.h"

void ZLParse::Init(const char *filePath) {
    std::vector<ZLNumber> points;
    std::vector<ZLNumber> textures;
    std::vector<ZLNumber> normals;
    std::vector<ZLFaceIndex> faces;
    
    std::ifstream myfile (filePath);
    if (myfile.is_open()) {
        std::string line;
        while ( getline (myfile,line) ) {
            if(line[0] == 'v' && line[1] == 'n'){
                ZLNumber numbers;
                parseAndPrintLine(line, "vn", numbers);
                normals.push_back(numbers);
                //printf("vn>> %f, %f, %f\n", numbers.numbers[0], numbers.numbers[1], numbers.numbers[2]);
            }
            else if(line[0] == 'v' && line[1] == 't'){
                ZLNumber numbers;
                parseAndPrintLine(line, "vt", numbers);
                textures.push_back(numbers);
                //printf("vt>> %f, %f, %f\n", numbers.numbers[0], numbers.numbers[1], numbers.numbers[2]);
            }
            else if(line[0] == 'f'){
                ZLFaceIndex face;
                parsePolyLine(line, face);
                faces.push_back(face);
                ZLIndex index0 = face.indexs[0];
                //printf("face: (%d,%d,%d) ", index0.positionIndex, index0.textureIndex, index0.normalIndex);
                ZLIndex index1 = face.indexs[1];
                //printf("(%d,%d,%d) ", index1.positionIndex, index1.textureIndex, index1.normalIndex);
                ZLIndex index2 = face.indexs[2];
                //printf("(%d,%d,%d) \n", index2.positionIndex, index2.textureIndex, index2.normalIndex);
            }
            else if(line[0] == 'v'){
                ZLNumber numbers;
                parseAndPrintLine(line, "v", numbers);
                points.push_back(numbers);
                //printf("v>> %f, %f, %f\n", numbers.numbers[0], numbers.numbers[1], numbers.numbers[2]);
            }
        }
    }
    
    for (int i = 0; i < faces.size(); i++) {
        ZLFace face;
        ZLFaceIndex faceIndex = faces[i];
        
        int pointCount = 3;
        for (int j = 0; j < pointCount; j++) {
            int pointIndex = faceIndex.indexs[j].positionIndex - 1;
            ZLNumber point = points[pointIndex];
            face.positions[j] = point;
            
            int textureIndex = faceIndex.indexs[j].textureIndex - 1;
            if (textureIndex >= 0) {
                ZLNumber texture = textures[textureIndex];
                face.textures[j] = texture;
            }
            
            int normalIndex = faceIndex.indexs[j].normalIndex - 1;
            if (normalIndex >= 0) {
                ZLNumber normal = points[normalIndex];
                face.normals[j] = normal;
            }
        }
        
        objFaces.push_back(face);
    }
}

void ZLParse::splitString(const std::string &txt, std::vector<std::string> &strs, char ch) {
    int in_string_bool = 0;
    size_t start_pos = 0;
    size_t it_pos = 0;
    strs.clear();
    while( it_pos < txt.length()) {
        if(in_string_bool && txt[it_pos] == ch && it_pos > start_pos){
            //end of word
            strs.push_back( txt.substr( start_pos, it_pos - start_pos) );
            in_string_bool = 0;
        }
        if(!in_string_bool && txt[it_pos] != ch){
            in_string_bool = 1;
            start_pos = it_pos;
        }
        it_pos++;
    }
    // Add the last one
    if(in_string_bool && it_pos > start_pos){
        strs.push_back( txt.substr( start_pos, it_pos - start_pos) );
    }
}

void ZLParse::parseAndPrintLine(const std::string & line, const char * coordinateType, ZLNumber &number) {
    std::vector<std::string> parsed;
    splitString(line, parsed, ' ');
    for (int i = 1; i < parsed.size(); i++) {
        number.numbers[i - 1] = ::atof(parsed[i].c_str());
    }
}

void ZLParse::parsePolyLine(const std::string &line, ZLFaceIndex &face) {
    std::vector<std::string> spaceSplits;
    splitString(line, spaceSplits, ' ');
    std::vector<std::string> rep;
    std::vector <std::vector <std::string> > slashSplits(spaceSplits.size(), rep);
    for(size_t i = 0; i < spaceSplits.size(); i++){
        splitString(spaceSplits[i], slashSplits[i], '/');
    }
    
    if (slashSplits.size() > 0) {
        for (int i = 1; i < slashSplits.size(); i++) {
            ZLIndex index;
            for (int j = 0; j < slashSplits[i].size(); j++) {
                if (j == 0) {
                    index.positionIndex = atoi(slashSplits[i][j].c_str());
                } else if (j == 1) {
                    index.textureIndex = atoi(slashSplits[i][j].c_str());
                } else if (j == 2) {
                    index.normalIndex = atoi(slashSplits[i][j].c_str());
                }
            }
            face.indexs[i - 1] = index;
        }
    }
}
