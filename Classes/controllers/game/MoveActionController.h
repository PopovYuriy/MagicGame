//
// Created by popovadmin on 07.01.18.
//

#ifndef MYGAME_MOVEACTIONCONTROLLER_H
#define MYGAME_MOVEACTIONCONTROLLER_H

#include <vector>
#include <game/data/GridNode.h>
#include "cocos/base/CCEventDispatcher.h"

using namespace std;

class UnitMover;

class MoveActionController {
public:
    MoveActionController(vector< vector<GridNode>* >* &);
    ~MoveActionController();

private:
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void moverFinish(cocos2d::EventCustom*);
    void createMover(vector<GridNode*>*, int);
    void showGrid();

    unsigned long columns, rows;
    int _startedMover = 0;
    vector< vector<GridNode>* > *grid;
    cocos2d::EventListenerCustom *_listenerMove, *_listenerMoverFinish;
    vector<UnitMover*>* _moverList;
    bool _moving;

    void onMoveEvent(cocos2d::EventCustom*);
};

class UnitMover {
public:
    UnitMover(vector<GridNode*> &, int);
    ~UnitMover();
    void checkMove();
    int id;
private:
    void doMove(vector<GridNode*>::iterator, vector<GridNode*>::iterator);
    vector<GridNode*> *data;
    int countCurrentActions = 0;
};


#endif //MYGAME_MOVEACTIONCONTROLLER_H
