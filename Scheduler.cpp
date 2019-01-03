//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Scheduler.h"

Scheduler::Scheduler() {
    Scheduler(3);
}

Scheduler::Scheduler(int volume) {
    this->volume = volume;
    currentTimeStamp = 0;
}

void Scheduler::push(Packet packet) {
    int timeStamp = packet.getDepartureRound();
    timeStamp = max(timeStamp, currentTimeStamp);
    if (timeStamp - currentTimeStamp >= 100)
        levels[2].push(packet, timeStamp / 100);
    else if (timeStamp - currentTimeStamp >= 10)
        levels[1].push(packet, timeStamp / 10 % 10);
    else levels[0].push(packet, timeStamp % 10);
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