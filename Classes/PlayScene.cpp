#include "PlayScene.h"

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
    background->setPosition(640, 400);
    this->addChild(background);


    return true;
}