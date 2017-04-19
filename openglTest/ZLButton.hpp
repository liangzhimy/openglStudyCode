//
//  ZLButton.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/16.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLButton_hpp
#define ZLButton_hpp

#include <stdio.h>
#include "ZLList.h"
#include "ZLSprite.hpp"
#include <functional>
#include "ZLFoundation.hpp"

class ZLButton : public ZLRenderableObject {
private:
    ZLSprite *defaultSprite;
    std::function<void()> clickEvent;
    ZLRect rect;
    float translateX;
public:
    ZLButton(); 
    void setOnClick(std::function<void()>foo);
    void SetRect(float x, float y, float width, float height);
    void SetDeafaultSprite(ZLSprite *sprite);
    void Draw();
    
    void OnTouchBegin(int x, int y);
    void OnTouchEnd(int x, int y);
};

#endif /* ZLButton_hpp */
