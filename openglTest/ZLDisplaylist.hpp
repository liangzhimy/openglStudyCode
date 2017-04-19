//
//  ZLDisplaylist.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/11.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLDisplaylist_hpp
#define ZLDisplaylist_hpp

#include <stdio.h>
#include <OpenGL/gl.h>
#include <functional>

class ZLDisplaylist {
public:
    GLuint displayList;
    void Init(std::function<void()>foo);
    void Draw();
};

#endif /* ZLDisplaylist_hpp */
