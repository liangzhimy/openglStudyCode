//
//  ZLList.h
//  openglTest
//
//  Created by zhaoliang on 2017/4/13.
//  Copyright © 2017年 liangzhimy. All rights reserved.
//

#ifndef ZLList_h
#define ZLList_h

class ZLList {
public:
    void *next;
    
    template<typename T>
    T *Next() {
        return (T *)next;
    }
    
    void PushBack(ZLList *next) {
        ZLList *last = this;
        while (last->next != NULL) {
            last = last->Next<ZLList>();
        }
        last->next = next;
    }
};

class ZLRenderableObject : public ZLList {
public:
    void Draw() {
        while (next != NULL) {
            Next<ZLRenderableObject>()->Draw();
        }
    }
};

#endif /* ZLList_h */
