//
// Created by popovadmin on 04.01.18.
//

#include <string>
#include <external/json/document.h>
#include "utils/parsers/DataParser.h"

using namespace rapidjson;

void UnitConfigParser::parse(map< string, BottleConfig* >& container) {
    CCLOG("Parse bottle config");
    string path = "config/units.json";
    string data = cocos2d::FileUtils::getInstance()->getStringFromFile(path);

    Document doc;
    doc.Parse<0>(data.c_str());

    int count = doc["bottles"].GetArray().Size();
    for(int i = 0; i < count; i++) {
        auto *bottle = new BottleConfig();
        bottle->maxLevel = doc["bottles"][i]["maxLevel"].GetInt();

        int tCount = doc["bottles"][i]["textures"].GetArray().Size();
        for(int j = 0; j < tCount; j++) {
            bottle->textures.emplace_back(doc["bottles"][i]["textures"][j].GetString());
        }
        string key = doc["bottles"][i]["subType"].GetString();
        container.emplace(key,bottle);
    }
}