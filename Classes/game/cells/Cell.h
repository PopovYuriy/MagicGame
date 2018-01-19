//
// Created by popovadmin on 13.01.18.
//

#ifndef MYGAME_CELL_H
#define MYGAME_CELL_H

#include <game/data/LevelData.h>
#include <game/GameObject.h>
#include "cocos2d.h"

USING_NS_CC;

class GridNode;

class Cell : public GameObject{
public:
    static Cell* createWithData(CellData);

public:
    explicit Cell(string);
    ~Cell() override;
    virtual bool doAction(GridNode*);
};

#endif //MYGAME_CELL_H
