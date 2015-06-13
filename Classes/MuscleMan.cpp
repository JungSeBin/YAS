#include "MuscleMan.h"

USING_NS_CC;

MuscleMan::MuscleMan()
{
    m_Sprite = Sprite::create("GoodMan.png");
    m_Sprite->setAnchorPoint(Point(0.5, 0));
    m_Sprite->setScale(0.3f);
    m_Sprite->setScaleX(0.5f);
    m_Sprite->setPosition(Point(40, 50));
    m_Type = HT_MUSCLEMAN;
}


MuscleMan::~MuscleMan()
{
}
