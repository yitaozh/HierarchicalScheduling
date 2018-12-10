//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_LIST_H
#define HIERARCHICALSCHEDULING_LIST_H

#include "Package.h"
#include <vector>

using namespace std;

class Fifo {
private:
    int index;
    vector<Package> fifo;
public:
    Fifo();
    void push(Package package);
    Package pull();
    bool isEmpty();
};


#endif //HIERARCHICALSCHEDULING_LIST_H
