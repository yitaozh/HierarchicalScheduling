
//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Simulator.h"
using namespace std;

Simulator::Simulator() {
    readFile(packages);
    for (auto package: packages)
        scheduler.push(package);
}