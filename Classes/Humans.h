#pragma once
#include "cocos2d.h"

USING_NS_CC;

enum HumanType
{
    HT_NONE,
    HT_POORMAN,
    HT_POORWOMAN,
    HT_MUSCLEMAN
};
class Humans
{
public:
    Humans();
    virtual ~Humans();

    void        Action(bool isLeft);
    Sprite*     GetSprite(){ return m_Sprite; }
    HumanType   GetType(){ return m_Type; }
protected:
    Sprite* m_Sprite;
    HumanType m_Type;
};

