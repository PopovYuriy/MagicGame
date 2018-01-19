//
// Created by popovadmin on 09.01.18.
//

#ifndef MYGAME_MOVEEVENT_H
#define MYGAME_MOVEEVENT_H

#include "cocos2d.h"

USING_NS_CC;

class MoveEvent : public EventCustom {
public:
    MoveEvent(const std::string &e);
    void setDirection(short);
    short getDirection();
private:
    short direction;
};


#endif //MYGAME_MOVEEVENT_H
