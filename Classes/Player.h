#pragma once

class Character;
class Player
{
public:
    Player();
    ~Player();

    static Player*  getInstance();
    void            releaseInstance();

    Character*      GetCharacter(){ return m_Character; }
    int             GetPlayerMoney(){ return m_Money; }

private:
    Character*  m_Character;
    int         m_Money;

    static Player* m_Instance;
};

