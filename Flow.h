//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_TASK_H
#define HIERARCHICALSCHEDULING_TASK_H

// will be used in package-send function
#include <queue>
#include "Packet.h"
using namespace std;

class Flow {
private:
    int flowId;
    float weight;
    int lastDepartureRound;
    int insertLevel;
public:
    Flow(int id, float weight);

    float getWeight() const;

    int getLastDepartureRound() const;
    void setLastDepartureRound(int lastDepartureRound);

    void setWeight(float weight);

    int getInsertLevel() const;

    void setInsertLevel(int insertLevel);
};


#endif //HIERARCHICALSCHEDULING_TASK_H
