
//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Simulator.h"
using namespace std;

Simulator::Simulator(vector<Flow> flows) {
    timeStamp = 0;
    scheduler = new Scheduler(timeStamp);
    for (const auto &flow: flows) {
        this->flows.push_back(flow);
    }
}

void Simulator::addFlow(Flow flow) {
    flows.push_back(flow);
}