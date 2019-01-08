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

    string filename = "schedulingResultTest1.txt";

    outputFile.open(filename);

    vector<Packet> flows[2];

    for (int cycle = 0, packetNum = 0; packetNum < simulator.numOfPackets(); cycle++) {
        vector<Packet> packets = simulator.runRound();
        if (packets.empty()) continue;
        for (auto packet: packets) {
            packet.setDepartureRound(cycle);
            if (packet.getFlowId() == 1)
                flows[0].push_back(packet);
            else
                flows[1].push_back(packet);
            packetNum++;
        }
    }

    for (int i = 0; i < 2; i++) {
        outputFile << "flow " << i + 1 << endl;
        for (auto packet: flows[i]) {
            outputFile << packet.getPacketOrder() << " ";
            outputFile << packet.getDepartureRound() << " ";
            outputFile << packet.getDepartureCycle() << endl;
        }
    }
    return 0;
}