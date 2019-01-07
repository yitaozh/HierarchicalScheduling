//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Packet.h"

Packet::Packet(int flowNum, int packageNum, int arriveCycle,
        int departureRound, int departureCycle, int size){
    this->flowId = flowNum;
    this->packetOrder = packageNum;
    this->arriveCycle = arriveCycle;
    this->departureRound = departureRound;
    this->departureCycle = departureCycle;
    this->size = size;
}

int Packet::getDepartureRound() const {
    return departureRound;
}

int Packet::getFlowId() const {
    return flowId;
}

int Packet::getArriveCycle() const {
    return arriveCycle;
}

void Packet::setDepartureRound(int departureRound) {
    this->departureRound = departureRound;
};

int Packet::getSize() const {
    return size;
}

int Packet::getPacketOrder() const {
    return packetOrder;
}

int Packet::getDepartureCycle() const {
    return departureCycle;
}

void Packet::setDepartureCycle(int departureCycle) {
    Packet::departureCycle = departureCycle;
}
