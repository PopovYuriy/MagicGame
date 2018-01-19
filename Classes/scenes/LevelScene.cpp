//
// Created by popovadmin on 03.01.18.
//

#include <cocos/base/CCDirector.h>
#include <game/data/LevelData.h>
#include <game/data/Storage.h>
#include <game/GameField.h>
#include <controllers/FieldInputController.h>
#include "LevelScene.h"

using namespace cocos2d;
using namespace ui;

Scene* LevelScene::createScene()
{
    return LevelScene::create();
}

bool LevelScene::init()
{
    CCLOG("LevelScene :: init");
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    LevelData *levelData = Storage::getInstance()->getLevelData(1);

    auto gameField = new GameField(levelData->grid);
    gameField->initialization(visibleSize.width);
    gameField->setPosition((visibleSize.width - gameField->getContentSize().width) / 2, (visibleSize.height - gameField->getContentSize().height) / 2);
    this->addChild(gameField);

    auto controller = new FieldMouseInputController();

    this->addChild(controller);

    return true;
}

