//
// Created by popovadmin on 03.01.18.
//

#ifndef MYGAME_UNIT_H
#define MYGAME_UNIT_H

#include <game/data/LevelData.h>
#include <game/GameObject.h>
#include "cocos2d.h"

class GridNode;

class Unit : public GameObject {
public:
    static Unit* createWithData(UnitData);

public:
    Unit(string);
    ~Unit();

    virtual bool doAction(GridNode*);

    void setWall(bool);
    bool isWall();

    void setMovable(bool);
    bool isMovable();

    void setInteractive(bool);
    bool isInteractive();

    void setUpgradable(bool);
    bool isUpgradable();

private:
    bool _isInteractive;
    bool _isMovable;
    bool _isWall;
    bool _isUpgradable;
};


#endif //MYGAME_UNIT_H
