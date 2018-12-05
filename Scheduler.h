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
    static const int DEFAULT_VOLUMN = 3;
    int currentTimeStamp;  //current time
    vector<Level> levels;
public:
    Scheduler(int timeStamp);
    Scheduler(int volumn, int timeStamp);
    void push(Package package);
    void pull();
};


#endif //HIERARCHICALSCHEDULING_SCHEDULER_H
