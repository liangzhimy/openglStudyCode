//
//  ZLSprite.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/13.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLSprite_hpp
#define ZLSprite_hpp

#include <stdio.h>
#include "ZLTexture.hpp"
#include "ZLVector3f.hpp"
#include "ZLList.h"

class ZLSprite : public ZLList {
    
private:
    ZLTexture *myTexture;
    ZLVector3f mash[4];
    
public:
    void SetTexture(ZLTexture *texture);
    void SetRect(float x, float y, float width, float height);
    void Draw();
    
};


#endif /* ZLSprite_hpp */
