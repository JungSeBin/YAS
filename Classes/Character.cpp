#include "Character.h"

USING_NS_CC;

Character::Character()
:m_Sprite(nullptr)
{
    Init();
}


Character::~Character()
{
}

void Character::Init()
{
    m_Sprite = Sprite::create("Sword1.png");
}

void Character::Move()
{
    if (m_IsRight)
    {
        auto action0 = MoveBy::create(1 / 60, Point(1, 0));
        m_Sprite->runAction(action0);
    }
    else
    {
        auto action1 = MoveBy::create(1 / 60, Point(-1, 0));
        m_Sprite->runAction(action1);
    }
}
