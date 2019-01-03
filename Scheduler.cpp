//
// Created by Zhou Yitao on 2018-12-04.
//

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
    currentCycle = 0;
}

void Scheduler::push(Packet packet) {
    int departureRound = packet.getDepartureRound();
    departureRound = max(departureRound, currentRound);
    if (departureRound - currentRound >= 100)
        levels[2].push(packet, departureRound / 100);
    else if (departureRound - currentRound >= 10)
        levels[1].push(packet, departureRound / 10 % 10);
    else levels[0].push(packet, departureRound % 10);
}

Packet Scheduler::serveCycle() {
    currentCycle++;
    Packet packet = levels[0].pull();
    if (packet.getDepartureRound() == -1) {
        levels[0].getAndIncrementIndex();

        if (levels[0].getCurrentIndex() == 0) {
            levels[1].getAndIncrementIndex();

            if (levels[1].getCurrentIndex() == 0)
                levels[2].getAndIncrementIndex();
        }
    }
    return packet;
}