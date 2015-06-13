#include "Player.h"
#include "Character.h"

Player::Player()
:m_Character(nullptr), m_Money(0)
{
    m_Character = new Character;
}


Player::~Player()
{
}

Player* Player::m_Instance = nullptr;

Player* Player::getInstance()
{
    if (m_Instance == nullptr)
    {
        m_Instance = new Player;
    }

    return m_Instance;
}

void Player::releaseInstance()
{
    if (m_Instance != nullptr)
    {
        delete m_Instance;
        m_Instance = nullptr;
    }
}
