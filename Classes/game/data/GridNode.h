//
// Created by popovadmin on 05.01.18.
//

#ifndef MYGAME_GRIDNODE_H
#define MYGAME_GRIDNODE_H


#include <game/units/Unit.h>
#include <string>
#include <game/cells/Cell.h>

class GridNode {
public:
    float tileX, tileY, centerX, centerY;
    Unit* object = nullptr;
    Cell* cell = nullptr;
};


#endif //MYGAME_GRIDNODE_H
