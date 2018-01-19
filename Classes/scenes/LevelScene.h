//
// Created by popovadmin on 03.01.18.
//

#ifndef MYGAME_LEVELSCENE_H
#define MYGAME_LEVELSCENE_H

#include <cocos/2d/CCScene.h>

class LevelScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(LevelScene);
};
#endif //MYGAME_LEVELSCENE_H
