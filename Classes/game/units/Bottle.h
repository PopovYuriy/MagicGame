//
// Created by popovadmin on 11.01.18.
//

#ifndef MYGAME_BOTTLE_H
#define MYGAME_BOTTLE_H


#include "Unit.h"

class Bottle : public Unit {
public:
    Bottle(string);
    bool doAction(GridNode*);
    void levelUp();
    void levelDown();
    void setMaxLevel(int);
    void setLevel(int);
    int getLevel();
    bool canUpgrade();
    void setType(string);
    string getType();

    void setLevelTextureNames(const vector<string>&);
private:
    string type;
    int _level, _maxLevel;
    const vector<string> *levelTextureNames;
};


#endif //MYGAME_BOTTLE_H
