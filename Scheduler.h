//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_SCHEDULER_H
#define HIERARCHICALSCHEDULING_SCHEDULER_H

#include "Level.h"
#include <vector>

using namespace std;

class Scheduler {
private:
    static const int DEFAULT_VOLUME = 3;
    int volume;                     // num of levels in scheduler
    int currentTimeStamp;           // current time
    int currentCycle;               // current cycle
    vector<Level> levels;
public:
    Scheduler();
    explicit Scheduler(int volume);
    void push(Package package);
    Package pull();
    void serveRound();              // one round: one pull, multi push
};


#endif //HIERARCHICALSCHEDULING_SCHEDULER_H
