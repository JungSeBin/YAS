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

    return true;
}