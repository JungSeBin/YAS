#include "ShopScene.h"

USING_NS_CC;

Scene* ShopScene::createScene()
{
    auto scene = Scene::create();

    auto layer = ShopScene::create();

    scene->addChild(layer);

    return scene;
}

bool ShopScene::init()
{
    if (!Layer::init())
    {
        return false;
    }


    return true;
}
