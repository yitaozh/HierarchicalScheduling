//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_HIERARCHY_H
#define HIERARCHICALSCHEDULING_HIERARCHY_H

#include "Fifo.h"
#include <vector>
using namespace std;

class Level {
private:
    static const int DEFAULT_VOLUME = 10;
    int volume;                         // num of fifos in one level
    int currentIndex;                   // current serve index
    Fifo fifos[10];
public:
    Level();
    Level(int volume);
    void push(Packet packet, int index);
    Packet pull();
    int getCurrentIndex();
    void getAndIncrementIndex();
    int getAvailabeTimeStamp();
};


#endif //HIERARCHICALSCHEDULING_HIERARCHY_H
