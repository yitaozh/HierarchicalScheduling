//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Fifo.h"

Fifo::Fifo() {
    this->index = 0;
}


void Fifo::push(Package package) {
    fifo.push_back(package);
}

Package Fifo::pull() {
    if (index < fifo.size())
        return fifo[index++];
    else {
        Package tmp(-1);
        return tmp;
    }
}

bool Fifo::isEmpty() {
    return index < fifo.size();
}
