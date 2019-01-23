//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Packet.h"

Packet::Packet(int flowNum, int packageNum, int arriveCycle,
        int departureRound, int departureCycle, int size){
    this->flowId = flowNum;
    this->packetOrder = packageNum;
    this->arriveCycle = arriveCycle;
    this->departureCycle = departureCycle;
    this->thryDepartureRound = departureRound;
    this->actlDepartureRound = -1;
    this->size = size;
    this->insertLevel = -1;
    this->insertFifo = -1;
    this->fifoPosition = -1;
}

int Packet::getThryDepartureRound() const {
    return thryDepartureRound;
}

int Packet::getFlowId() const {
    return flowId;
}

int Packet::getArriveCycle() const {
    return arriveCycle;
}

void Packet::setThryDepartureRound(int departureRound) {
    this->thryDepartureRound = departureRound;
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

int Packet::getActlDepartureRound() const {
    return actlDepartureRound;
}

void Packet::setActlDepartureRound(int actlDepartureRound) {
    Packet::actlDepartureRound = actlDepartureRound;
}

int Packet::getInsertLevel() const {
    return insertLevel;
}

void Packet::setInsertLevel(int insertLevel) {
    Packet::insertLevel = insertLevel;
}

int Packet::getInsertFifo() const {
    return insertFifo;
}

void Packet::setInsertFifo(int insertFifo) {
    Packet::insertFifo = insertFifo;
}

int Packet::getFifoPosition() const {
    return fifoPosition;
}

void Packet::setFifoPosition(int fifoPosition) {
    Packet::fifoPosition = fifoPosition;
}

int Packet::getArriveRound() const {
    return arriveRound;
}

void Packet::setArriveRound(int arriveRound) {
    Packet::arriveRound = arriveRound;
}
