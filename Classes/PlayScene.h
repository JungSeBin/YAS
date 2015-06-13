#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

class PlayScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void Tick(float dt);

    CREATE_FUNC(PlayScene);

    bool prevLeft;
    bool isLeft;
};

#endif