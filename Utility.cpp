//
// Created by Zhou Yitao on 2018-12-12.
//
#include <iostream>
#include <fstream>
#include "Utility.h"
using namespace std;

void readFile(vector<Package>& packages) {
    ifstream inputFile;
    string filename;
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

    inputFile >> numOfPackage;

    for (int i = 0; i < numOfPackage; i++) {
        int flowNum, packageNum, arriveTime, departureTime, size;
        inputFile >> flowNum;
        inputFile >> packageNum;
        inputFile >> arriveTime;
        inputFile >> departureTime;
        inputFile >> size;
        Package tmp(flowNum, packageNum, arriveTime, departureTime, size);
        packages.push_back(tmp);
    }

    inputFile.close();
}