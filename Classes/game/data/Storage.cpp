//
// Created by popovadmin on 11.01.18.
//

#include <external/json/document.h>
#include <utils/parsers/DataParser.h>
#include "Storage.h"
#include "cocos2d.h"

using namespace rapidjson;

Storage* Storage::_instance = 0;

Storage *Storage::getInstance() {
    if(_instance == 0) _instance =  new Storage();
    return _instance;
}

Storage::Storage() {
    CCLOG("STORAGE");
    this->bottlesConfig = new map< string, BottleConfig* >();
    this->levelsData = new vector< struct LevelData* >();
}

void Storage::init() {
    parseBottleConfig();
    parseLevels();
}

void Storage::parseBottleConfig() {
    UnitConfigParser::parse(*this->bottlesConfig);
}

void Storage::parseLevels() {
    CCLOG("Parsing levels data.");
    for(short i = 1; i <= levelsCount; i++) {
        LevelParser::parse(i, *levelsData);
    }
}

LevelData *Storage::getLevelData(int id) {
    LevelData *ld = levelsData->at(id - 1);
    return ld;
}
