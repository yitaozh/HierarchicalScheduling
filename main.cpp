#include <iostream>
#include <fstream>

#include "Level.h"
#include "Simulator.h"

using namespace std;

int main(int argc, char **argv) {
    // get input file name as a parameter of the program
    string inputFilename = argv[1];

    // get output file name
    string delimiter = ".";
    string outputFilename = inputFilename.substr(0, inputFilename.find(delimiter)) + ".output";
    string outputRecordFilename = inputFilename.substr(0, inputFilename.find(delimiter)) + "_record.output";
    string outputDetailedFilename = inputFilename.substr(0, inputFilename.find(delimiter)) + "_detailed.output";

    // open output file
    ofstream outputFile;
    outputFile.open(outputFilename);
    ofstream outputRecordFile;
    outputRecordFile.open(outputRecordFilename);
    ofstream outputDetailedFile;
    outputDetailedFile.open(outputDetailedFilename);


    vector<Flow> tmpFlows;
    vector<Packet> tmpPackets;
    readFile(inputFilename, tmpFlows, tmpPackets);

    Simulator simulator(tmpFlows, tmpPackets);

    outputFile << "Packet Num: " << simulator.numOfPackets() << endl;

    // output file name

    vector<vector<Packet>> flows(simulator.numOfFlows(), vector<Packet>(3000));

    for (int cycle = 0, packetNum = 0; packetNum < simulator.numOfPackets() - simulator.getDropPacketNum(); cycle++) {
        vector<Packet> packets = simulator.runRound();

        if (packets.empty()) continue;

        for (auto packet: packets) {
            // packet.setThryDepartureRound(cycle);

            flows[packet.getFlowId() - 1][packet.getPacketOrder()] = packet;

            packetNum++;
        }
    }

    vector<Packet> droppedPackets = simulator.getDroppedPackets();

    for (auto packet: droppedPackets)
        flows[packet.getFlowId() - 1][packet.getPacketOrder()] = packet;

    //output to graph python program
    for (int i = 0; i < simulator.numOfFlows(); i++) {
        outputFile << "flow " << i + 1 << endl;
        for (auto packet: flows[i]) {
            outputFile << packet.getPacketOrder() << " ";
            outputFile << packet.getThryDepartureRound() << " ";
            outputFile << packet.getActlDepartureRound() << " ";
            outputFile << packet.getDepartureCycle() << " ";
            outputFile << packet.getArriveCycle() << endl;
        }
    }

    //output to detailed file
    for (int i = 0; i < simulator.numOfFlows(); i++) {
        outputDetailedFile << "flow " << i + 1 << endl;
        outputDetailedFile << "Packet" << "\t" << "ArrCycle" << "\t";
        outputDetailedFile << "ArrRound" << "\t";
        outputDetailedFile << "ThryDepRnd" << "\t" << "ActlDepRnd" << "\t";
        outputDetailedFile << "DepCycle" << "\t" << "InsLvl" << "\t";
        outputDetailedFile << "InsFifo" << "\t" << "PosInFifo" << endl;

        for (auto packet: flows[i]) {
            outputDetailedFile << packet.getPacketOrder() << "\t\t";
            outputDetailedFile << packet.getArriveCycle() << "\t\t\t";
            outputDetailedFile << packet.getArriveRound() << "\t\t\t";
            outputDetailedFile << packet.getThryDepartureRound() << "\t\t\t";
            outputDetailedFile << packet.getActlDepartureRound() << "\t\t\t";
            outputDetailedFile << packet.getDepartureCycle() << "\t\t\t";
            outputDetailedFile << packet.getInsertLevel() << "\t\t";
            outputDetailedFile << packet.getInsertFifo() << "\t\t";
            outputDetailedFile << packet.getFifoPosition() << endl;
        }
    }

    vector<int> packetNumRecord = simulator.getPacketNumRecord();
    for (int i = 0; i < packetNumRecord.size(); i++) {
        outputRecordFile << i << " ";
        outputRecordFile << packetNumRecord[i] << endl;
    }


    return 0;
}