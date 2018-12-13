//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Package.h"

Package::Package(int flowNum, int packageNum, int arriveTime, int departureTime, int size){
    this->flowNum = flowNum;
    this->packageNum = packageNum;
    this->arriveTime = arriveTime;
    this->departureTime = departureTime;
    this->size = size;
}

int Package::getDepartureTime() const {
    return departureTime;
};

