#pragma once
#include "cocos2d.h"
#include <vector>

USING_NS_CC;

class Humans;
class Character
{
public:
    Character();
    ~Character();

    void            Init();
    void            Move(bool isLeft);

    Sprite*         GetSprite(){ return m_CurSprite; }
    Humans*         GetHuman(){ return m_Human; }
    bool            IsLeft(){ return m_IsLeft; }
    void            Turn();

    RepeatForever*  MakeAnimation(const char* format, int size, float delay);
    Animate*        MakeAnimationOnce(const char* format, int size, float delay);

private:
    bool m_IsLeft;
    Sprite* m_CurSprite;
    Humans* m_Human;
};

