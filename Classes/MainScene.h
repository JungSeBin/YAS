#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"

class MainScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    void menuCallback0(cocos2d::Ref* sender);
    void menuCallback1(cocos2d::Ref* sender);
    void menuCallback2(cocos2d::Ref* sender);

    virtual bool init();

    CREATE_FUNC(MainScene);
};

#endif