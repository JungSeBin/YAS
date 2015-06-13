#include "PlayScene.h"
#include "Player.h"
#include "Character.h"
#include "Humans.h"

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

    prevLeft = true;

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
    characSprite->setScale(3.0f);
    this->addChild(characSprite);

    return true;
}

void PlayScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, Event* event)
{
    auto character = Player::getInstance()->GetCharacter();

    if (keyCode == cocos2d::EventKeyboard::KeyCode ::KEY_RIGHT_ARROW)
    {
        isLeft = false;
    }
    else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
    {
        isLeft = true;
    }
    else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE)
    {
        character->GetSprite()->stopAllActions();
        character->GetHuman()->Action(isLeft);
        return;
    }
    if (prevLeft != isLeft)
    {
        character->GetSprite()->stopAllActions();
        if (prevLeft)
            prevLeft = false;
        else
            prevLeft = true;
    }
    character->Move(isLeft);
}
