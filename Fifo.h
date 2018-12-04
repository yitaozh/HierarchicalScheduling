//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_LIST_H
#define HIERARCHICALSCHEDULING_LIST_H

#include "Package.h"

class Fifo {
private:
    int index;
    int volumn;
public:
    Fifo(int index, int volumn);
    void setVolumn(int volumn);
    void push(Package package);
    void pull();
};


#endif //HIERARCHICALSCHEDULING_LIST_H
