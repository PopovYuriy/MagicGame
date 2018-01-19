//
// Created by popovadmin on 09.01.18.
//

#include "MoveEvent.h"

MoveEvent::MoveEvent(const std::string &e) : EventCustom(e){

}

void MoveEvent::setDirection(short value) {
    this->direction = value;
}

short MoveEvent::getDirection() {
    return this->direction;
}
