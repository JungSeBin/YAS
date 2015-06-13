#include "MainScene.h"
#include "PlayScene.h"
#include "ShopScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    auto scene = Scene::create();

    auto layer = MainScene::create();

    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    auto playButton = MenuItemImage::create(
        "Play.png",
        "Play.png",
        CC_CALLBACK_1(MainScene::menuCallback0, this));

    auto equipButton = MenuItemImage::create(
        "Equip.png",
        "Equip.png",
        CC_CALLBACK_1(MainScene::menuCallback1, this));

    auto shopButton = MenuItemImage::create(
        "Shop.png",
        "Shop.png",
        CC_CALLBACK_1(MainScene::menuCallback2, this));

    auto menu = Menu::create(playButton, equipButton, shopButton, false);
    menu->alignItemsVerticallyWithPadding(100);
    menu->setPosition(1000, 400);
    this->addChild(menu);

    return true;
}

void MainScene::menuCallback0(cocos2d::Ref* sender)
{
    Director::getInstance()->replaceScene(PlayScene::createScene());
}

void MainScene::menuCallback1(cocos2d::Ref* sender)
{
    //EquipScene
}

void MainScene::menuCallback2(cocos2d::Ref* sender)
{
    Director::getInstance()->replaceScene(ShopScene::createScene());
}
