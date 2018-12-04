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
    vector<Level> level;
public:
    Scheduler();
    void push(Package package);
    void pull();
};


#endif //HIERARCHICALSCHEDULING_SCHEDULER_H
