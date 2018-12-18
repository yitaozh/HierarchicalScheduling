//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_SIMULATOR_H
#define HIERARCHICALSCHEDULING_SIMULATOR_H

#include "Scheduler.h"
#include "Flow.h"
#include "Utility.h"
using namespace std;

class Simulator {
private:
    int timeStamp;
    Scheduler scheduler;
    vector<Package> packages;
    int currentPacketIndex;

public:
    Simulator();
    // serve package counter, count package from scheduler output
    void run();
};


#endif //HIERARCHICALSCHEDULING_SIMULATOR_H
