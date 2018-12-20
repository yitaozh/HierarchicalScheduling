//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_LIST_H
#define HIERARCHICALSCHEDULING_LIST_H

#include "Packet.h"
#include <vector>

using namespace std;

class Fifo {
private:
    int index;
    vector<Packet> fifo;
public:
    Fifo();
    void push(Packet package);
    Packet pull();
    bool isEmpty();
};


#endif //HIERARCHICALSCHEDULING_LIST_H
