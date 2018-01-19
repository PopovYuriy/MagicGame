//
// Created by popovadmin on 05.01.18.
//

#ifndef MYGAME_LEVELDATA_H
#define MYGAME_LEVELDATA_H

#include <string>
#include <vector>

using namespace std;

struct CellData {
    string view;
    string type;
};

struct UnitData {
    string type;
    string subType;
    string view;
    bool isWall = false;
    bool movable = false;
    int level;
};

struct GridNodeData {
    UnitData unit;
    CellData cell;
};

class LevelData {
public:
    int width;
    int height;
    vector<vector<GridNodeData*>> grid;
};


#endif //MYGAME_LEVELDATA_H
