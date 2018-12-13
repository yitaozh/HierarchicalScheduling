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

void Scheduler::push(Package package) {
    int timeStamp = package.getDepartureTime();
    timeStamp = max(timeStamp, currentTimeStamp);
    if (timeStamp - currentTimeStamp >= 100)
        levels[0].push(package, timeStamp / 100);
    else if (timeStamp - currentTimeStamp >= 10)
        levels[1].push(package, timeStamp / 10 % 10);
    else levels[2].push(package, timeStamp % 10);
}

void Scheduler::serveRound() {
    while (pull().getDepartureTime() != -1) {
        // TODO
        // push package
    }
    levels[2].getAndIncrementIndex();
    if (levels[2].getCurrentIndex() == 0) {
        levels[1].getAndIncrementIndex();
        if (levels[1].getCurrentIndex() == 0)
            levels[0].getAndIncrementIndex();
    }
    currentTimeStamp++;
}

Package Scheduler::pull() {
    currentCycle++;
    return levels[2].pull();
}