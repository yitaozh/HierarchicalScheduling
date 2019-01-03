#include <iostream>
#include <fstream>

#include "Level.h"
#include "Simulator.h"

using namespace std;

int main() {
    Simulator simulator;

    ofstream outputFile;

    outputFile << "Packet Num: " << simulator.packets.size() << endl;

    /*
    for (auto packet: simulator.packets) {
        cout << "FlowNum: " << packet.getFlowId() << " packetNum: " << packet.getPacketOrder() << endl;
    }
    */

    string filename = "schedulingResult.txt";

    outputFile.open(filename);

    for (int i = 0; i < 100; i++) {
        vector<Packet> packets = simulator.runRound();
        if (packets.empty()) continue;
        outputFile << "Round " << i << endl;
        for (auto packet: packets) {
            outputFile << "FlowNum: " << packet.getFlowId();
            outputFile << " packetNum: " << packet.getPacketOrder() << endl;
        }
    }

    return 0;
}