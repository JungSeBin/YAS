#include "StartScene.h"
#include "MainScene.h"
#include "ShopScene.h"
#include "Player.h"
#include "Character.h"

USING_NS_CC;

Scene* StartScene::createScene()
{
    auto scene = Scene::create();

    auto layer = StartScene::create();

    scene->addChild(layer);

    return scene;
}

bool StartScene::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto winSize = Director::getInstance()->getWinSize();

    auto startButton = MenuItemImage::create(
        "Start.png",
        "Start.png",
        CC_CALLBACK_1(StartScene::menuCallback0, this));

    auto exitButton = MenuItemImage::create(
        "Exit.png",
        "Exit.png",
        CC_CALLBACK_1(StartScene::menuCallback1, this));

    auto menu = Menu::create(startButton, exitButton, false);
    menu->alignItemsVerticallyWithPadding(50);
    menu->setPosition(winSize.width / 2, winSize.height / 2);

    this->addChild(menu);
    return true;
}

void StartScene::menuCallback0(cocos2d::Ref* sender)
{
    //Player::getInstance()->GetCharacter()->Init();
    Director::getInstance()->replaceScene(MainScene::createScene());
}

void StartScene::menuCallback1(cocos2d::Ref* sender)
{
    exit(1);
}
