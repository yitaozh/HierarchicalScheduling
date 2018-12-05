//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_HIERARCHY_H
#define HIERARCHICALSCHEDULING_HIERARCHY_H

#include "Fifo.h"
#include <vector>
using namespace std;

class Level {
private:
    static const int DEFAULT_VOLUMN = 10;
    int volumn;
    int currentIndex;   //current serving fifo
    vector<Fifo> myFifo;

public:
    Level();
    Level(int volumn);
    void push(Package packge);
    void pull();
    int getAvailabeTimeStamp();
};


#endif //HIERARCHICALSCHEDULING_HIERARCHY_H
