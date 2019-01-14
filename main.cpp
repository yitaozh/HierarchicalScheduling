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

    string filename = "schedulingResultTest.output";

    outputFile.open(filename);

    vector<vector<Packet>> flows(static_cast<unsigned long>(simulator.numOfFlows()));

    for (int cycle = 0, packetNum = 0; packetNum < simulator.numOfPackets(); cycle++) {
        vector<Packet> packets = simulator.runRound();
        if (packets.empty()) continue;

        for (auto packet: packets) {
            // packet.setDepartureRound(cycle);
            flows[packet.getFlowId() - 1].push_back(packet);

            packetNum++;
        }
    }

    for (int i = 0; i < simulator.numOfFlows(); i++) {
        outputFile << "flow " << i + 1 << endl;
        for (auto packet: flows[i]) {
//            outputFile << "packet order: " << packet.getPacketOrder() << " ";
//            outputFile << "arrive cycle: " << packet.getArriveCycle() << " ";
//            outputFile << "depart round: " << packet.getDepartureRound() << " ";
//            outputFile << "depart cycle: " << packet.getDepartureCycle() << endl;
            outputFile << packet.getPacketOrder() << " ";
            outputFile << packet.getDepartureRound() << " ";
            outputFile << packet.getDepartureCycle() << endl;
        }
    }
    return 0;
}