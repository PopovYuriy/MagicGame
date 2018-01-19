//
// Created by popovadmin on 13.01.18.
//

#include <game/data/GridNode.h>
#include <game/units/Bottle.h>
#include "TargetCell.h"


TargetCell::TargetCell(string textureName): Cell(textureName) {}

TargetCell::~TargetCell() {}

bool TargetCell::doAction(GridNode *node) {
    CCLOG("TargetCell :: doAction");
    if(node->object->isUpgradable()) {
        Bottle* unit = (Bottle*)node->object;
        if(unit->getType() == "greenBottle" && unit->getLevel() == 2) {
            CCLOG("Unit catch!!!! URA");
            return true;
        }
    }
    return true;
}
