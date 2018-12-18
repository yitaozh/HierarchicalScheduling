
//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Simulator.h"
using namespace std;

Simulator::Simulator() {
    readFile(packages);
    timeStamp = 0;
    currentPacketIndex = 0;
}

void Simulator::run() {
    while (packages[currentPacketIndex].getDepartureTime() == timeStamp)
        scheduler.push(packages[currentPacketIndex++]);
    scheduler.serveRound();
    timeStamp++;
}