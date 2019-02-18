//
// Created by Zhou Yitao on 2018-12-04.
//
#include <cmath>

#include "Scheduler.h"

Scheduler::Scheduler() {
    Scheduler(3);
}

void Scheduler::setCurrentRound(int currentRound) {
    Scheduler::currentRound = currentRound;
}

Scheduler::Scheduler(int volume) {
    this->volume = volume;
    currentRound = 0;
}

void Scheduler::push(Packet packet) {
    int departureRound = packet.getThryDepartureRound();
    departureRound = max(departureRound, currentRound);
    if (departureRound / 100 != currentRound / 100) {
        packet.setInsertLevel(2);
        levels[2].push(packet, (departureRound % 1000) / 100);
    } else if (departureRound / 10 != currentRound / 10) {
        packet.setInsertLevel(1);
        levels[1].push(packet, (departureRound % 1000) / 10 % 10);
    } else {
        packet.setInsertLevel(0);
        levels[0].push(packet, (departureRound % 1000) % 10);
    }
}

Packet Scheduler::serveCycle() {
    Packet packet = levels[0].pull();
    if (packet.getThryDepartureRound() == -1) {
        levels[0].getAndIncrementIndex();

        if (levels[0].getCurrentIndex() == 0) {
            levels[1].getAndIncrementIndex();

            if (levels[1].getCurrentIndex() == 0)
                levels[2].getAndIncrementIndex();
        }
    }
    return packet;
}

vector<Packet> Scheduler::serveUpperLevel(int& currentCycle, int currentRound) {
    vector<Packet> result;

    if (currentRound % 100 == 0 && !levels[2].isCurrentFifoEmpty()) {
        int size = levels[2].getCurrentFifoSize();
        for (int i = 0; i < size; i++) {
            Packet tmp = levels[2].pull();
            if (tmp.getPacketOrder() == -1)
                break;
            currentCycle++;
            tmp.setDepartureCycle(currentCycle);
            tmp.setActlDepartureRound(currentRound);
            result.push_back(tmp);
        }
    }

    if (!levels[1].isCurrentFifoEmpty()) {
        int size = levels[1].getCurrentFifoSize();
        for (int i = 0; i < size; i++) {
            Packet tmp = levels[1].pull();
            if (tmp.getPacketOrder() == -1)
                break;
            currentCycle++;
            tmp.setDepartureCycle(currentCycle);
            tmp.setActlDepartureRound(currentRound);
            result.push_back(tmp);
        }
    }

    return result;
}