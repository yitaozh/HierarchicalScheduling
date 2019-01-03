
//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Simulator.h"
#include <cmath>

using namespace std;

Simulator::Simulator() {
    readFile(flows, packets);
    currentRound = 0;
    currentCycle = 0;
    currentPacketIndex = 0;
}

vector<Packet> Simulator::runRound() {
    vector<Packet> result;
    Packet tmp = runCycle();
    while (tmp.getPacketOrder() != -1) {
        result.push_back(tmp);
        tmp = runCycle();
    }
    currentRound++;
    scheduler.setCurrentRound(currentRound);
    return result;
}

Packet Simulator::runCycle() {
    while (packets[currentPacketIndex].getArriveCycle() == currentCycle) {
        Packet packet = packets[currentPacketIndex++];
        int tmp = calDepartureRound(packet.getFlowId() - 1, packet.getSize());
        packet.setDepartureRound(tmp);
        scheduler.push(packet);
    }
    currentCycle++;
    return scheduler.serveCycle();
}

int Simulator::calDepartureRound(int flowId, int packetSize) {
    int departureRound = round(max(currentRound, flows[flowId].getLastDepartureRound())
            + 1 / flows[flowId].getWeight() * packetSize);
    flows[flowId].setLastDepartureRound(departureRound);
    return departureRound;
}