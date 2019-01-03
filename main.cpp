#include <iostream>

#include "Level.h"
#include "Simulator.h"

using namespace std;

int main() {
    Simulator simulator;

    Packet tmp(-1, -1, -1, -1, -1);

    Fifo fifo;
    fifo.push(tmp);

    for (int i = 1; i <= 10; i++) {
        Packet packet = simulator.runCycle();
        cout << i << "th packet:" << packet.getPacketOrder() << endl;
    }


    return 0;
}