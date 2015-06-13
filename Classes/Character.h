#pragma once
#include "cocos2d.h"
#include <vector>

USING_NS_CC;

class Character
{
public:
    Character();
    ~Character();

    void            Init();
    void            Move();

    Sprite*         GetSprite(){ return m_CurSprite; }
    void            Turn();

    RepeatForever*  MakeAnimation(const char* format, int size, float delay);
    Animate*        MakeAnimationOnce(const char* format, int size, float delay);

private:
    bool m_IsLeft;
    Sprite* m_CurSprite;
    Sprite* m_PrevSprite;
};

