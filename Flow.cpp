//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Flow.h"

Flow::Flow(int id, float weight) {
    lastDepartureRound = 0;
    this->flowId = id;
    this->weight = weight;
}

int Flow::getLastDepartureRound() const {
    return lastDepartureRound;
}

void Flow::setLastDepartureRound(int lastDepartureRound) {
    Flow::lastDepartureRound = lastDepartureRound;
}

float Flow::getWeight() const {
    return weight;
}

void Flow::setWeight(float weight) {
    Flow::weight = weight;
}
