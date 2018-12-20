//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Scheduler.h"

Scheduler::Scheduler() {
    Scheduler(DEFAULT_VOLUME);
}

Scheduler::Scheduler(int volume) {
    this->volume = volume;
    currentTimeStamp = 0;
    for (int i = 0; i < volume; i++) {
        Level tmp(i);
        levels.push_back(tmp);
    }
}

void Scheduler::push(Packet package) {
    int timeStamp = package.getDepartureRound();
    timeStamp = max(timeStamp, currentTimeStamp);
    if (timeStamp - currentTimeStamp >= 100)
        levels[2].push(package, timeStamp / 100);
    else if (timeStamp - currentTimeStamp >= 10)
        levels[1].push(package, timeStamp / 10 % 10);
    else levels[0].push(package, timeStamp % 10);
}

vector<Packet> Scheduler::serveRound() {
    vector<Packet> result;
    // fake package mark the end with departureTime -1
    while (pull().getDepartureRound() != -1) {

    }
    levels[0].getAndIncrementIndex();
    if (levels[0].getCurrentIndex() == 0) {
        levels[1].getAndIncrementIndex();
        if (levels[1].getCurrentIndex() == 0)
            levels[2].getAndIncrementIndex();
    }
    currentTimeStamp++;
    return result;
}

Packet Scheduler::pull() {
    currentCycle++;
    return levels[0].pull();
}