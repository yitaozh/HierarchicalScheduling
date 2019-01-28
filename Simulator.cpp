#include <utility>

#include <utility>

#include <utility>


//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Simulator.h"
#include <cmath>

using namespace std;

Simulator::Simulator(vector<Flow> flows, vector<Packet> packets) {
//    for (auto flow: flows)
//        this->flows.push_back(flow);
//    for (auto packet: packets)
//        this->packets.push_back(packet);
    this->flows = move(flows);
    this->packets = move(packets);
    currentRound = 0;
    currentCycle = 0;
    currentPacketIndex = 0;
    packetNum = 0;
}

/* in every round(one level 0 fifo serve out)
 * we run cycle function until all packets in
 * current fifo are served out
 * */
vector<Packet> Simulator::runRound() {
    vector<Packet> result;
    if (currentRound % 10 == 0) {
        vector<Packet> upperLevelPackets = scheduler.serveUpperLevel(currentCycle, currentRound);

        for (int i = 0; i < upperLevelPackets.size(); i++) {
            packetNumRecord.push_back(packetNum);
            packetNum--;
        }

        result.insert(result.end(), upperLevelPackets.begin(), upperLevelPackets.end());
    }

    Packet tmp = runCycle();
    // backup cycle for the idling situation
    int currentCycle_backup = currentCycle;
    // if no packet in current fifo, it will return a
    // empty packet marked with packet order -1
    while (tmp.getPacketOrder() != -1) {
        packetNumRecord.push_back(packetNum);
        packetNum--;
        currentCycle++;
        tmp.setDepartureCycle(currentCycle);
        tmp.setActlDepartureRound(currentRound);
        result.push_back(tmp);
        tmp = runCycle();
    }

    //current round done
    currentRound++;
    // in case there's no packet being served, cycle increase 1 as idling
    if (currentCycle == currentCycle_backup) {
        packetNumRecord.push_back(packetNum);
        currentCycle++;
    }
    scheduler.setCurrentRound(currentRound);
    return result;
}

/* in every cycle(real world time), we push multiple
 * packets and pop 1 (or 0) packet
 * */
Packet Simulator::runCycle() {
    //push arrive packets to scheduler
    while (currentPacketIndex < packets.size() && packets[currentPacketIndex].getArriveCycle() <= currentCycle) {
        Packet packet = packets[currentPacketIndex++];
        int departureRound = calDepartureRound(packet.getFlowId() - 1, packet.getSize());
        packet.setArriveRound(currentRound);
        packet.setThryDepartureRound(departureRound);
        scheduler.push(packet);
        packetNum++;
    }
    //pull one packet out
    return scheduler.serveCycle();
}

int Simulator::calDepartureRound(int flowId, int packetSize) {
    int departureRound = static_cast<int>(ceil(max(currentRound, flows[flowId].getLastDepartureRound())
            + 1 / flows[flowId].getWeight() * packetSize));
    flows[flowId].setLastDepartureRound(departureRound);
    return departureRound;
}

int Simulator::numOfFlows() {
    return static_cast<int>(flows.size());
}

int Simulator::numOfPackets() {
    return static_cast<int>(packets.size());
}

const vector<int> &Simulator::getPacketNumRecord() const {
    return packetNumRecord;
}
