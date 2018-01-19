//
// Created by popovadmin on 13.01.18.
//

#include "Cell.h"
#include "TargetCell.h"

Cell::Cell(string textureName) : GameObject(textureName) {}

Cell::~Cell() {}

bool Cell::doAction(GridNode *) {
    CCLOG("Cell:: doAction");
    return true;
}

Cell *Cell::createWithData(CellData data) {
    CCLOG("Creating cell :: type = %s", data.type.c_str());

    if (data.type == "empty") {

        auto cell = new Cell(data.view);
        return cell;
    }
    else if (data.type == "TargetCell"){
        auto cell = new TargetCell(data.view);
        return cell;
    }

    return nullptr;
}

