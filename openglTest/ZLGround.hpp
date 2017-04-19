//
//  ZLGround.hpp
//  openglTest
//
//  Created by zhaoliang on 2017/4/14.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLGround_hpp
#define ZLGround_hpp

#include <stdio.h>
#include "ZLDisplaylist.hpp"

class ZLGround {
private:
    ZLDisplaylist groundDisplay;
public:
    void Init();
    void Draw();
};


#endif /* ZLGround_hpp */
