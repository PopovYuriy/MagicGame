//
// Created by popovadmin on 04.01.18.
//

#include <string>
#include <external/json/document.h>
#include "utils/parsers/DataParser.h"

using namespace cocos2d;
using namespace rapidjson;

void LevelParser::parse(short id, vector<LevelData*> &container) {
    std::string path = "levels/l_";
    path = path.append(std::to_string(id)).append(".json");
    CCLOG("Start parsing level %d from %s", id, path.c_str());

    std::string data = FileUtils::getInstance()->getStringFromFile(path);

    Document doc;
    doc.Parse<0>(data.c_str());

    container.push_back(new LevelData());
    LevelData *levelData = container.at(container.size() - 1);

    levelData->width = doc["width"].GetInt();
    levelData->height = doc["height"].GetInt();

    for(SizeType n = 0; n < levelData->height; n++) {
        levelData->grid.emplace_back(vector<GridNodeData*>());
    }

    for(SizeType i = 0; i != levelData->height; i++) {

        for(SizeType j = 0; j < levelData->width; j++) {
            levelData->grid[i].push_back(new GridNodeData());
            GridNodeData* node = levelData->grid[i].at(j);

            levelData->grid[i].at(j)->cell.view = doc["grid"][i][j]["cell"]["view"].GetString();
            levelData->grid[i].at(j)->cell.type = doc["grid"][i][j]["cell"]["type"].GetString();

            node->unit.type = doc["grid"][i][j]["object"]["type"].GetString();

            if(doc["grid"][i][j]["object"].HasMember("view")) {
                node->unit.view = doc["grid"][i][j]["object"]["view"].GetString();
            }
            if(doc["grid"][i][j]["object"].HasMember("subType")) {
                node->unit.subType = doc["grid"][i][j]["object"]["subType"].GetString();
            }
            if(doc["grid"][i][j]["object"].HasMember("level")) {
                node->unit.level = doc["grid"][i][j]["object"]["level"].GetInt();
            }
            if(doc["grid"][i][j]["object"].HasMember("isWall")) {
                node->unit.isWall = doc["grid"][i][j]["object"]["isWall"].GetBool();
            }
            if(doc["grid"][i][j]["object"].HasMember("movable")) {
                node->unit.movable = doc["grid"][i][j]["object"]["movable"].GetBool();
            }
        }
    }

    CCLOG("Level parsing success");
}
