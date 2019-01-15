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

    // open output file
    ofstream outputFile;
    outputFile.open(outputFilename);

    vector<Flow> tmpFlows;
    vector<Packet> tmpPackets;
    readFile(inputFilename, tmpFlows, tmpPackets);

    Simulator simulator(tmpFlows, tmpPackets);

    outputFile << "Packet Num: " << simulator.numOfPackets() << endl;

    // output file name

    vector<vector<Packet>> flows(static_cast<unsigned long>(simulator.numOfFlows()));

    for (int cycle = 0, packetNum = 0; packetNum < simulator.numOfPackets(); cycle++) {
        vector<Packet> packets = simulator.runRound();
        if (packets.empty()) continue;

        for (auto packet: packets) {
            // packet.setThryDepartureRound(cycle);

            flows[packet.getFlowId() - 1].push_back(packet);

            packetNum++;
        }
    }

    for (int i = 0; i < simulator.numOfFlows(); i++) {
        outputFile << "flow " << i + 1 << endl;
        for (auto packet: flows[i]) {
            outputFile << packet.getPacketOrder() << " ";
            outputFile << packet.getThryDepartureRound() << " ";
            outputFile << packet.getActlDepartureRound() << " ";
            outputFile << packet.getDepartureCycle() << endl;
        }
    }
    return 0;
}