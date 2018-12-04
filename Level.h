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
    int volumn;
    int currentTimeStamp;  //current time
    int currentIndex;   //current serving fifo
    vector<Fifo> myFifo;

public:
    Level(int volumn);
    void push(Packge packge);
    void pull();
    int getAvailabeTimeStamp();
};


#endif //HIERARCHICALSCHEDULING_HIERARCHY_H
