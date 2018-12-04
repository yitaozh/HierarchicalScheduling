//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_TASK_H
#define HIERARCHICALSCHEDULING_TASK_H

// will be used in package-send function
#include <vector>
#include "Package.h"

class Flow {
private:
    int weight;
    int length;     // How many package in total
    vector<Package> packages;

public:
    Flow(int weight, int length);
    void setWeight(int weight);
    void setLength(int length);
    Package getNextPackage();
};


#endif //HIERARCHICALSCHEDULING_TASK_H
