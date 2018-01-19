//
// Created by popovadmin on 11.01.18.
//

#include <game/data/GridNode.h>
#include "Bottle.h"

bool Bottle::doAction(GridNode *node) {
    CCLOG("Bottle:: doAction");
    //Unit::doAction(node);
    if(!this->canUpgrade() || !node->object->isUpgradable()) return false;

    auto target = static_cast<Bottle*>(node->object);

    if(target->getType() != this->getType() || target->getLevel() != this->getLevel()) return false;

    Node* parent = target->getParent();
    parent->removeChild(target, true);

    node->object = nullptr;

    levelUp();

    node->cell->doAction(node);
    return true;
}

void Bottle::levelUp() {
    ++this->_level;
    auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(this->levelTextureNames->at(this->_level - 1));
    this->getSprite()->setSpriteFrame(frame);
}

void Bottle::levelDown() {

}

void Bottle::setMaxLevel(int value) {
    this->_maxLevel = value;
}

void Bottle::setLevel(int value) {
    this->_level = value;
}

int Bottle::getLevel() {
    return this->_level;
}

bool Bottle::canUpgrade() {
    return this->_level < this->_maxLevel;
}

void Bottle::setType(string value) {
    this->type = value;
}

string Bottle::getType() {
    return this->type;
}

void Bottle::setLevelTextureNames(const vector<string> &value) {
    this->levelTextureNames = &value;
}

Bottle::Bottle(string textureName) : Unit(textureName){}
