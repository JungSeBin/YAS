#include "Humans.h"


Humans::Humans()
{
}


Humans::~Humans()
{
}

void Humans::Action(bool isLeft)
{
    RotateTo* action0;
    RotateTo* action1;
    if (isLeft)
    {
        action0 = RotateTo::create(0.05f, -120.0f);
        action1 = RotateTo::create(0.05f, 0.0f);
    }
    else
    {
        action0 = RotateTo::create(0.05f, 120.0f);
        action1 = RotateTo::create(0.05f, 0.0f);
    }

    auto action2 = Sequence::create(action0, action1, false);

    m_Sprite->runAction(action2);
}
