//
// Created by popovadmin on 11.01.18.
//

#ifndef MYGAME_STORAGE_H
#define MYGAME_STORAGE_H

#include <map>
#include <string>
#include <vector>
#include "LevelData.h"
#include "ConfigDataObjects.h"

using namespace std;

class Storage {
public:
    void init();
    static Storage* getInstance();

    const int levelsCount = 1;

    LevelData* getLevelData(int);
    BottleConfig* getBottleConfig(string);

    map<string, BottleConfig*> *bottlesConfig;
private:
    Storage();
    ~Storage();
    Storage(Storage const&) = delete;
    Storage operator= (Storage const&) = delete;

    static Storage* _instance;

    void parseBottleConfig();
    void parseLevels();

    vector<LevelData*> *levelsData;
};


#endif //MYGAME_STORAGE_H
