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
    int departureCycle;
    int thryDepartureRound;
    int actlDepartureRound;
    int size;
    int insertLevel;
    int insertFifo;
    int fifoPosition;

public:
    Packet(int flowNum, int packageNum, int arriveCycle,
            int departureRound, int departureCycle, int size);

    int getArriveCycle() const;

    int getDepartureCycle() const;

    void setDepartureCycle(int departureCycle);

    int getThryDepartureRound() const;

    void setThryDepartureRound(int departureRound);

    int getActlDepartureRound() const;

    void setActlDepartureRound(int actlDepartureRound);

    int getFlowId() const;

    int getSize() const;

    int getPacketOrder() const;

    int getInsertLevel() const;

    void setInsertLevel(int insertLevel);

    int getInsertFifo() const;

    void setInsertFifo(int insertFifo);

    int getFifoPosition() const;

    void setFifoPosition(int fifoPosition);
};


#endif //HIERARCHICALSCHEDULING_PACKAGE_H
