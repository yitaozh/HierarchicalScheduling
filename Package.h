//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_PACKAGE_H
#define HIERARCHICALSCHEDULING_PACKAGE_H


class Package {
private:
    int flowNum;            //Identify flow
    int packageNum;         //Packet number in flow
    int arriveTime;
    int departureTime;
    int size;
public:
    int getDepartureTime() const;

public:
    Package(int flowNum, int packageNum, int arriveTime, int departureTime, int size);
};


#endif //HIERARCHICALSCHEDULING_PACKAGE_H
