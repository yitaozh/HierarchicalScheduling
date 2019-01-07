//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Level.h"

Level::Level(): volume(10), currentIndex(0) {
}

void Level::push(Packet packet, int index) {
    fifos[index].push_back(packet);
}

Packet Level::pull() {
    if (isCurrentFifoEmpty()) {
        Packet tmp(-1, -1, -1, -1, -1, -1);
        return tmp;
    }
    Packet tmp = fifos[currentIndex].front();
    fifos[currentIndex].pop_front();
    return tmp;
}

int Level::getCurrentIndex() {
    return currentIndex;
}

void Level::getAndIncrementIndex() {
    if (currentIndex + 1 < volume) {
        currentIndex++;
    } else {
        currentIndex = 0;
    }
}

bool Level::isCurrentFifoEmpty() {
    return fifos[currentIndex].empty();
}

int Level::getCurrentFifoSize() {
    return static_cast<int>(fifos[currentIndex].size());
}
