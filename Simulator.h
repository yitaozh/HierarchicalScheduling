//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_SIMULATOR_H
#define HIERARCHICALSCHEDULING_SIMULATOR_H

#include "Scheduler.h"
#include "Flow.h"
using namespace std;

class Simulator {
private:
    int timeStamp;
    Scheduler* scheduler;
    vector<Flow> flows;

public:
    Simulator(vector<Flow> flows);
    // add flow
    void addFlow(Flow flow);

    // TODO
    // package generator, feed package into scheduler

    // TODO
    // serve package counter, count package from scheduler output
};


#endif //HIERARCHICALSCHEDULING_SIMULATOR_H
