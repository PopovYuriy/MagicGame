//
// Created by popovadmin on 16.01.18.
//

#ifndef MYGAME_GAMEOBJECT_H
#define MYGAME_GAMEOBJECT_H


#include <cocos/2d/CCNode.h>
#include <cocos/2d/CCSprite.h>

class GameObject : public cocos2d::Node{
public:
    explicit GameObject(std::string);
    ~GameObject();
    cocos2d::Sprite* getSprite() const;
protected:
    cocos2d::Sprite* _sprite;
};


#endif //MYGAME_GAMEOBJECT_H
