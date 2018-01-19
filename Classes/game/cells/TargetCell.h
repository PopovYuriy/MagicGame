//
// Created by popovadmin on 13.01.18.
//

#ifndef MYGAME_TARGETCELL_H
#define MYGAME_TARGETCELL_H


#include "Cell.h"

class TargetCell : public Cell{
public:
    explicit TargetCell(string);
    ~TargetCell() override;
    bool doAction(GridNode*) override;
};


#endif //MYGAME_TARGETCELL_H
