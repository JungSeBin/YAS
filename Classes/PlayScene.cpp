#include "PlayScene.h"
#include "Player.h"
#include "Character.h"

USING_NS_CC;

Scene* PlayScene::createScene()
{
    auto scene = Scene::create();

    auto layer = PlayScene::create();

    scene->addChild(layer);

    return scene;
}

bool PlayScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyPressed = CC_CALLBACK_2(PlayScene::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

    auto winSize = Director::getInstance()->getWinSize();
    auto background = Sprite::create("Field.png");
    background->setAnchorPoint(Point(0.5,0.5));
    background->setPosition(winSize.width / 2, winSize.height / 2);
    this->addChild(background);

    auto character = Player::getInstance()->GetCharacter();

    auto characSprite = character->GetSprite();
    characSprite->setAnchorPoint(Point(0.5, 0));
    characSprite->setPosition(winSize.width / 2, winSize.height / 8);
    characSprite->setScale(2.0f);
    this->addChild(characSprite);

    this->schedule(schedule_selector(PlayScene::Tick), 0.2f);
    return true;
}

void PlayScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, Event* event)
{
    if (keyCode == cocos2d::EventKeyboard::KeyCode ::KEY_SPACE)
    {
        Player::getInstance()->GetCharacter()->Turn();
        Player::getInstance()->GetCharacter()->GetSprite()->stopAllActions();
    }
}

void PlayScene::Tick(float dt)
{
    Player::getInstance()->GetCharacter()->Move();
}
