//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Level.h"

Level::Level() {
    this->volume = 10;
    this->currentIndex = 0;
}

void Level::push(Packet packet, int index) {
    fifos[index].push(packet);
}

Packet Level::pull() {
    return  fifos[currentIndex].pull();
}

int Level::getAvailabeTimeStamp() {

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
