//
// Created by popovadmin on 16.01.18.
//

#include "GameObject.h"

GameObject::GameObject(std::string textureName) {
    this->_sprite = cocos2d::Sprite::createWithSpriteFrameName(textureName);
    this->_sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
    this->addChild(_sprite);
    this->setContentSize(this->_sprite->getContentSize());
}

GameObject::~GameObject() {
    delete this->_sprite;
}

cocos2d::Sprite *GameObject::getSprite() const {
    return this->_sprite;
}

