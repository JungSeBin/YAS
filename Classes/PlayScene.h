#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

class PlayScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(PlayScene);
};

#endif