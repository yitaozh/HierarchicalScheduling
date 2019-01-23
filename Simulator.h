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
    vector<Packet> packets;
    int currentPacketIndex;
    int packetNum;      // current num of packets in sim.
    vector<int> packetNumRecord;

public:
    Simulator(vector<Flow>, vector<Packet>);
    int calDepartureRound(int, int);
    vector<Packet> runRound();
    // serve package counter, count package from scheduler output
    Packet runCycle();
    int numOfFlows();
    int numOfPackets();
    const vector<int> &getPacketNumRecord() const;
};


#endif //HIERARCHICALSCHEDULING_SIMULATOR_H
