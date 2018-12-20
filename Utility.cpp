//
// Created by Zhou Yitao on 2018-12-12.
//
#include <iostream>
#include <fstream>
#include "Utility.h"
using namespace std;

void readFile(vector<Flow>& flows, vector<Packet>& packages) {
    ifstream inputFile;
    string filename;
    int numOfFlows;
    int numOfPackage;
    cout << "Please enter the filename, press ENTER to use result.txt directly" << endl;

    getline(cin, filename);
    if (filename.empty())
        filename = "result.txt";

    inputFile.open(filename);
    if (!inputFile) {
        cout << "Couldn't open " << filename << " !" << endl;
        exit(1);
    }
    inputFile >> numOfFlows;
    for (int i = 0; i < numOfFlows; i++) {
        int flowId;
        float flowWeight;
        inputFile >> flowId;
        inputFile >> flowWeight;

        Flow tmp(flowId, flowWeight);
        flows.push_back(tmp);
    }

    inputFile >> numOfPackage;

    for (int i = 0; i < numOfPackage; i++) {
        int flowNum, packageNum, arriveCycle, size;
        inputFile >> flowNum;
        inputFile >> packageNum;
        inputFile >> arriveCycle;
        inputFile >> size;
        Packet tmp(flowNum, packageNum, arriveCycle, 0, size);
        packages.push_back(tmp);
    }

    inputFile.close();
}