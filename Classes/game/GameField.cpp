//
// Created by popovadmin on 04.01.18.
//

#include <game/data/GridNode.h>
#include "GameField.h"

GameField::GameField(vector< vector<GridNodeData*> > &grid):Node() {
    this->rows = grid.size();
    this->columns = grid[0].size();
    this->createGrid(grid);

    _moveController = new MoveActionController(this->grid);
}

GameField::~GameField() {
    delete _moveController;

    for(auto i = grid->begin(); i != grid->end(); i++) {
        (*i)->clear();
    }
    grid->clear();
    delete grid;
}

void GameField::initialization(float screenWidth) {

    groundLayer = Node::create();
    this->addChild(groundLayer, -1);

    objectLayer = Node::create();
    this->addChild(objectLayer, 1);

    this->itemSize = solveItemSize();
    float requiredItemWidth = screenWidth / this->columns;
    this->itemScale = requiredItemWidth / itemSize;
    GridNode *node;
    vector< GridNode > *row;
    float x = 0, y = 0;
    for(vector< vector <GridNode> >::size_type i = 0; i < rows; i++) {
        row = this->grid->at(i);
        for(vector<GridNode>::size_type j = 0; j < columns; j++) {
            node = &row->at(j);

            node->cell->setScale(this->itemScale);
            node->cell->setAnchorPoint(Vec2(0, 0));
            node->cell->setPosition(x, y);
            groundLayer->addChild(node->cell, -1);

            node->tileX = x;
            node->tileY = y;
            node->centerX = x + requiredItemWidth / 2;
            node->centerY = y + requiredItemWidth / 2;

            if(node->object) {
                node->object->setScale(this->itemScale);
                node->object->setAnchorPoint(Vec2(.5, .5));
                node->object->setPosition(x + requiredItemWidth / 2, y + requiredItemWidth / 2);
                objectLayer->addChild(node->object, 1);
            }
            x += requiredItemWidth;
        }
        x = 0;
        y += requiredItemWidth;
    }
    this->setContentSize(Size(columns * requiredItemWidth, rows * requiredItemWidth));
}

float GameField::solveItemSize() {
    return this->grid->at(0)->at(0).cell->getContentSize().width;
}

void GameField::createGrid(vector< vector<GridNodeData*> > &gridData) {
    this->grid = new vector< vector<GridNode>* >();

    for(int i = 0; i < this->rows; i++) {
        auto *row = new vector< GridNode>();
        for(int j = 0; j < this->columns; j++) {
            GridNode node;
            node.cell = Cell::createWithData(gridData[i][j]->cell);
            node.object = Unit::createWithData(gridData[i][j]->unit);

            row->push_back(node);
        }

        this->grid->push_back(row);
    }
}
