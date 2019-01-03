//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_PACKAGE_H
#define HIERARCHICALSCHEDULING_PACKAGE_H


class Packet {
private:
    int flowId;            //Identify flow
    int packetOrder;         //Packet number in flow
    int arriveCycle;
    int departureRound;
    int size;

public:
    int getDepartureRound() const;

    int getArriveCycle() const;

    void setDepartureRound(int departureRound);

    Packet(int flowNum, int packageNum, int arriveCycle, int departureRound, int size);

    int getFlowId() const;

    int getSize() const;

    int getPacketOrder() const;
};


#endif //HIERARCHICALSCHEDULING_PACKAGE_H
