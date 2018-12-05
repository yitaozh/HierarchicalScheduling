//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Scheduler.h"

Scheduler::Scheduler(int timeStamp) {
    Scheduler(DEFAULT_VOLUMN, timeStamp);
}

Scheduler::Scheduler(int volumn, int timeStamp) {
    currentTimeStamp = timeStamp;
    for (int i = 0; i < volumn; i++) {
        levels.push_back(new Level());
    }
}

void Scheduler::push(Package package) {

}

void Scheduler::pull() {

}