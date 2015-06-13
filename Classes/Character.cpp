#include "Character.h"

USING_NS_CC;

Character::Character()
:m_CurSprite(nullptr), m_IsLeft(true)
{
    Init();
}


Character::~Character()
{
}

void Character::Init()
 {
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Sword_L.plist");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Swrod_R.plist");
    m_CurSprite = Sprite::createWithSpriteFrameName("Sword_L1.png");
}

void Character::Move()
{

    if (m_IsLeft)
    {

        auto animation = Animation::create();
        animation->setDelayPerUnit(0.3f);

        for (int i = 1; i < 5; ++i)
        {
            auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("Sword_L%d.png", i));
            animation->addSpriteFrame(frame);
        }
        m_CurSprite->runAction(RepeatForever::create(Animate::create(animation)));

        auto action0 = MoveBy::create(0.15f, Point(-30, 0));
        m_CurSprite->runAction(action0);
    }
    else
    {
        auto animation = Animation::create();
        animation->setDelayPerUnit(0.3f);

        for (int i = 1; i < 5; ++i)
        {
            auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("Sword_R%d.png", i));
            animation->addSpriteFrame(frame);
        }
        m_CurSprite->runAction(RepeatForever::create(Animate::create(animation)));

        auto action1 = MoveBy::create(0.15f, Point(30, 0));
        m_CurSprite->runAction(action1);
    }
}

void Character::Turn()
{
    if (m_IsLeft)
        m_IsLeft = false;
    else
        m_IsLeft = true;
}

RepeatForever* Character::MakeAnimation(const char* format, int size, float delay)
{
    return RepeatForever::create(MakeAnimationOnce(format, size, delay));
}

Animate* Character::MakeAnimationOnce(const char* format, int size, float delay)
{
    auto animation = Animation::create();
    animation->setDelayPerUnit(delay);

    for (int i = 1; i < size + 1; ++i)
    {
        auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format(format, i));
        animation->addSpriteFrame(frame);
    }

    return Animate::create(animation);
}