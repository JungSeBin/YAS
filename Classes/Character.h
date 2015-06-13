#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Character
{
public:
    Character();
    ~Character();

    void Init();
    void Move();

    Sprite* GetSprite(){ return m_Sprite; }

private:
    bool m_IsRight;
    Sprite* m_Sprite;
};

