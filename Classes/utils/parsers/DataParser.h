//
// Created by popovadmin on 04.01.18.
//

#ifndef MYGAME_LEVELPARSER_H
#define MYGAME_LEVELPARSER_H

#include "cocos2d.h"
#include <game/data/LevelData.h>
#include <game/data/ConfigDataObjects.h>

class LevelParser {
public:
    static void parse(short, vector<LevelData*> &);

};

class UnitConfigParser {
public:
    static void parse(map< string, BottleConfig* >&);
};


#endif //MYGAME_LEVELPARSER_H
