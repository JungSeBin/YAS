#include "Character.h"
#include "Humans.h"
#include "MuscleMan.h"

USING_NS_CC;

Character::Character()
:m_CurSprite(nullptr), m_IsLeft(true)
{
    m_Human = new MuscleMan;
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

    m_CurSprite->addChild(m_Human->GetSprite());
}

void Character::Move(bool isLeft)
{

    if (isLeft)
    {
        auto animation = Animation::create();
        animation->setDelayPerUnit(0.3f);
        
        for (int i = 1; i < 5; ++i)
        {
            auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("Sword_L%d.png", i));
            animation->addSpriteFrame(frame);
        }
        m_CurSprite->runAction(RepeatForever::create(Animate::create(animation)));

        auto action0 = MoveBy::create(0.1f, Point(-20, 0));
        m_CurSprite->runAction(action0);

        m_Human->GetSprite()->setPosition(Point(40, 50));
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

        auto action1 = MoveBy::create(0.1f, Point(20, 0));
        m_CurSprite->runAction(action1);

        m_Human->GetSprite()->setPosition(Point(80, 50));
    }
}

void Character::Turn()
{
    m_Human->GetSprite()->stopAllActions();
    m_Human->GetSprite()->setRotation(0.0f);

    if (m_IsLeft)
    {
        m_Human->GetSprite()->setPosition(Point(80, 50));

        m_IsLeft = false;
    }
    else
    {
        m_Human->GetSprite()->setPosition(Point(40, 50));

        m_IsLeft = true;
    }
    
    m_Human->Action(m_IsLeft);
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