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
    int currentRound;
    int currentCycle;
    Scheduler scheduler;
    vector<Flow> flows;
    int currentPacketIndex;

public:
    vector<Packet> packets;

    Simulator();
    int calDepartureRound(int, int);
    vector<Packet> runRound();
    // serve package counter, count package from scheduler output
    Packet runCycle();
};


#endif //HIERARCHICALSCHEDULING_SIMULATOR_H
