#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

class StartScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    void menuCallback0(cocos2d::Ref* sender);
    void menuCallback1(cocos2d::Ref* sender);
    virtual bool init();

    CREATE_FUNC(StartScene);
};

#endif