//
// Created by popovadmin on 07.01.18.
//

#include <controllers/FieldInputController.h>
#include <events/GameEvent.h>
#include <events/MoveEvent.h>
#include "MoveActionController.h"

MoveActionController::MoveActionController(vector<vector<GridNode>* >* &grid) {
    this->grid = grid;

    _listenerMove = cocos2d::EventListenerCustom::create(
            GameEvent::MOVE,
            std::bind(&MoveActionController::onMoveEvent, this, std::placeholders::_1)
    );

    _listenerMoverFinish = cocos2d::EventListenerCustom::create(
            GameEvent::MOVER_FINISH,
            std::bind(&MoveActionController::moverFinish, this, std::placeholders::_1)
    );

    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(_listenerMove, 1);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(_listenerMoverFinish, 1);

    this->rows = grid->size();
    this->columns = grid->at(0)->size();
    this->_moverList = new vector<UnitMover*>();
    this->_moving = false;
    //showGrid();
}

MoveActionController::~MoveActionController() {
    this->grid = nullptr;
    cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(_listenerMove);
    cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(_listenerMoverFinish);
    delete _listenerMove;
    delete _listenerMoverFinish;
    this->_moverList->clear();
    delete _moverList;
}

void MoveActionController::onMoveEvent(cocos2d::EventCustom * e) {
    if(_moving) {
        return;
    }
    //showGrid();
    _moving = true;
    short direction = dynamic_cast<MoveEvent*>(e)->getDirection();

    switch(direction){

        case FieldInputController::DIRECTION_DOWN:
            this->moveDown();
            break;
        case FieldInputController::DIRECTION_LEFT:
            this->moveLeft();
            break;
        case FieldInputController::DIRECTION_RIGHT:
            this->moveRight();
            break;
        case FieldInputController::DIRECTION_UP:
            this->moveUp();
            break;
        default:
            break;
    }
    for(auto i = _moverList->begin(); i < _moverList->end(); i++) {
        (*i)->checkMove();
    }
    //showGrid();
}

void MoveActionController::moveRight() {

    for(auto i = 0; i < rows; i++) {
        auto data = new vector<GridNode*>();
        for(int j = 0; j < columns; j++) {
            data->push_back(&grid->at(i)->at(j));
        }
        createMover(data, i);
    }
}

void MoveActionController::moveLeft() {

    for(int i = 0; i < rows; i++) {
        auto data = new vector<GridNode*>();
        for(int j = (int)columns - 1; j >= 0; j--) {
            data->push_back(&grid->at(i)->at(j));
        }
        createMover(data, i);
    }
}

void MoveActionController::moveUp() {

    for(int i = 0; i < columns; i++) {
        auto data = new vector<GridNode*>();
        for(int j = 0; j < (int)rows; j++) {
            data->push_back(&grid->at(j)->at(i));
        }
        createMover(data, i);
    }
}

void MoveActionController::moveDown() {

    for(int i = 0; i < columns; i++) {
        auto data = new vector<GridNode*>();
        for(int j = (int)rows - 1; j >= 0; j--) {
            data->push_back(&grid->at(j)->at(i));
        }
        createMover(data, i);
    }
}

void MoveActionController::moverFinish(cocos2d::EventCustom * e) {
    auto id = static_cast<char*>(e->getUserData());
    --this->_startedMover;
    if(this->_startedMover == 0) {
        for(auto i = _moverList->begin(); i < _moverList->end(); i++) {
            delete *i;
        }
        _moverList->clear();
        _moverList->resize(0);

        _moving = false;
    }
}


void MoveActionController::createMover(vector<GridNode *> *data, int id) {
    ++this->_startedMover;
    auto *mover = new UnitMover(*data, id);
    _moverList->push_back(mover);
}

void MoveActionController::showGrid() {
    string s = "";
    for(int i = (int)rows -1; i >= 0; i--) {
        for(int j = 0; j < (int)columns; j++) {
            s += "[";
            s += to_string(grid->at(i)->at(j).object == nullptr ? 0 : grid->at(i)->at(j).object->isWall()) + ", ";
            s += to_string(grid->at(i)->at(j).object == nullptr ? 0 : grid->at(i)->at(j).object->isMovable()) + "] ";
        }
        s+="\n";
    }
    CCLOG("%s", s.c_str());
}


UnitMover::UnitMover(vector<GridNode *> &data, int id) {
    this->data = &data;
    this->id = id;
}

UnitMover::~UnitMover() {
    this->data = nullptr;
}

void UnitMover::checkMove() {
    int moveCount = 0;

    for(auto i = this->data->end() - 1; i >= this->data->begin(); i--) {
        GridNode *node = (*i);
        if(node->object != nullptr && node->object->isMovable()) {

            if(i + 1 >= this->data->end()) {
                continue;
            }
            GridNode *nextNode = *(i + 1);

            if(nextNode->object && nextNode->object->isWall()) {
                nextNode->object->doAction(node);
                continue;
            }
            if(!nextNode->object) {
                moveCount++;
                doMove(i, i + 1);
            }
        }
    }
    if(moveCount == 0) {
        EventCustom event(GameEvent::MOVER_FINISH);
        shared_ptr<int> buff = make_shared<int>(this->id);
        event.setUserData(buff.get());
        Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
    }
}

void UnitMover::doMove(vector<GridNode *>::iterator from, vector<GridNode*>::iterator to) {
    GridNode *toNode = *to;
    ++this->countCurrentActions;

    toNode->object = (*from)->object;
    (*from)->object = nullptr;

    auto moveTo = MoveTo::create(.045, Vec2(toNode->centerX, toNode->centerY));
    auto callback = CallFuncN::create([&, toNode](Node* sender) {
        --countCurrentActions;

        if(toNode->object) {
            toNode->cell->doAction(toNode);
        }
        if(countCurrentActions == 0) {
            checkMove();
        }
    });
    auto sequence = Sequence::create(moveTo, callback, NULL);


    toNode->object->runAction(sequence);

}
