//
// Created by Zhou Yitao on 2018-12-12.
//
#include <iostream>
#include <fstream>
#include "Utility.h"
using namespace std;

void readFile(string inputFilename, vector<Flow>& flows, vector<Packet>& packets) {
    ifstream inputFile;
    int numOfFlows;
    int numOfPackage;

    inputFile.open(inputFilename);
    if (!inputFile) {
        cout << "Couldn't open " << inputFilename << " !" << endl;
        exit(1);
    }
    cout << inputFilename << " open successfully!" << endl;
    inputFile >> numOfFlows;
    for (int i = 0; i < numOfFlows; i++) {
        int flowId;
        float flowWeight;
        inputFile >> flowId;
        inputFile >> flowWeight;

        Flow flow(flowId - 1, flowWeight);
        flows.push_back(flow);
    }

    inputFile >> numOfPackage;

    for (int i = 0; i < numOfPackage; i++) {
        int flowNum, packageNum, arriveCycle, size;
        inputFile >> flowNum;
        inputFile >> packageNum;
        inputFile >> arriveCycle;
        inputFile >> size;
        Packet packet(flowNum, packageNum, arriveCycle, -1, -1, size);
        packets.push_back(packet);
    }

    inputFile.close();
}