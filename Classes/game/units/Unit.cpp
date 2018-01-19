//
// Created by popovadmin on 03.01.18.
//

#include <game/data/Storage.h>
#include "Unit.h"
#include "Bottle.h"

bool Unit::doAction(GridNode *target) {
    CCLOG("Unit:: doAction");
    return true;
}

void Unit::setWall(bool value) {
    this->_isWall = value;
}

bool Unit::isWall() {
    return this->_isWall;
}

void Unit::setMovable(bool value) {
    this->_isMovable = value;
}

bool Unit::isMovable() {
    return this->_isMovable;
}

Unit *Unit::createWithData(UnitData data) {
    if(data.type == "empty") {
        return nullptr;
    }
    CCLOG("Creating unit :: type = %s", data.type.c_str());

    if(data.type == "Bottle") {
        const BottleConfig *bCfg = Storage::getInstance()->bottlesConfig->at(data.subType);

        auto unit = new Bottle(bCfg->textures.at((unsigned)data.level - 1));

        unit->setLevelTextureNames(bCfg->textures);
        unit->setLevel(data.level);
        unit->setType(data.subType);
        unit->setMaxLevel(bCfg->maxLevel);
        unit->setMovable(data.movable);
        unit->setWall(data.isWall);
        unit->setUpgradable(true);
        return unit;

    }
    else if(data.type == "Unit") {
        auto unit = new Unit(data.view);
        unit->setMovable(data.movable);
        unit->setWall(data.isWall);
        return unit;
    }
    return nullptr;
}

void Unit::setInteractive(bool value) {
    this->_isInteractive = value;
}

bool Unit::isInteractive() {
    return this->_isInteractive;
}

void Unit::setUpgradable(bool value) {
    this->_isUpgradable = value;
}

bool Unit::isUpgradable() {
    return this->_isUpgradable;
}

Unit::~Unit() {
    CCLOG("Unit:: destructor");
}

Unit::Unit(string textureName) : GameObject(textureName) {}


