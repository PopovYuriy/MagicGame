//
// Created by popovadmin on 04.01.18.
//

#ifndef MYGAME_GAMEFIELD_H
#define MYGAME_GAMEFIELD_H


#include <game/data/LevelData.h>
#include <controllers/game/MoveActionController.h>
#include "game/data/GridNode.h"
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class GameField : public Node{
public:
    GameField(vector< vector<GridNodeData*> > &);
    ~GameField();

    void initialization(float);

private:
    float solveItemSize();
    void createGrid(vector< vector<GridNodeData*> > &);

    vector< vector<GridNode>* >* grid;
    unsigned long columns, rows;
    float itemSize, itemScale;

    Node *groundLayer, *objectLayer;

    MoveActionController* _moveController;
};


#endif //MYGAME_GAMEFIELD_H
