#include "PoorWoman.h"


PoorWoman::PoorWoman()
{
    m_Sprite = Sprite::create("PoorWoman.png");
    m_Sprite->setAnchorPoint(Point(0.5, 0));
    m_Sprite->setScale(0.3f);

    m_Sprite->setPosition(Point(40, 50));
    m_Type = HT_POORWOMAN;
}


PoorWoman::~PoorWoman()
{
}
