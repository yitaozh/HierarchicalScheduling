
//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Simulator.h"
#include <cmath>

using namespace std;

Simulator::Simulator() {
    readFile(flows, packages);
    timeStamp = 0;
    currentPacketIndex = 0;
}

Packet Simulator::runCycle() {
    while (packages[currentPacketIndex].getArriveCycle() == timeStamp) {
        Packet package = packages[currentPacketIndex];
        int tmp = calDepartureRound(package.getFlowId(), package.getSize());
        packages[currentPacketIndex].setDepartureRound(tmp);
        scheduler.push(packages[currentPacketIndex++]);
    }
    timeStamp++;
    return scheduler.serveCycle();
}

int Simulator::calDepartureRound(int flowId, int packageSize) {
    int departureRound = round(max(timeStamp, flows[flowId].getLastDepartureRound())
            + 1 / flows[flowId].getWeight() * packageSize);
    flows[flowId].setLastDepartureRound(departureRound);
    return departureRound;
}