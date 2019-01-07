#include <iostream>
#include <fstream>

#include "Level.h"
#include "Simulator.h"

using namespace std;

int main() {
    Simulator simulator;

    ofstream outputFile;

    outputFile << "Packet Num: " << simulator.numOfPackets() << endl;

    /*
    for (auto packet: simulator.packets) {
        cout << "FlowNum: " << packet.getFlowId() << " packetNum: " << packet.getPacketOrder() << endl;
    }
    */

    string filename = "schedulingResult.txt";

    outputFile.open(filename);

    for (int cycle = 0, num = 0; num < simulator.numOfPackets(); cycle++) {
        vector<Packet> packets = simulator.runRound();
        if (packets.empty()) continue;
        outputFile << "Round " << cycle << endl;
        for (auto packet: packets) {
            num++;
            outputFile << "FlowNum: " << packet.getFlowId();
            outputFile << " packetNum: " << packet.getPacketOrder();
            outputFile << " serve Cycle: " << packet.getDepartureCycle();
            // outputFile << " arrive Cycle: "<< packet.getArriveCycle();
            outputFile << endl;
        }
    }

    return 0;
}