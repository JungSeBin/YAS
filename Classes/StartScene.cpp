#include "StartScene.h"

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

    return true;
}