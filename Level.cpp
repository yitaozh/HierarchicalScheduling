//
// Created by Zhou Yitao on 2018-12-04.
//

#include "Level.h"

Level::Level() {
    Level(DEFAULT_VOLUME);
}

Level::Level(int volume) {
    this->volume = volume;
    this->currentIndex = 0;
    for (int i = 0; i < volume; i++) {
        Fifo tmp;
        fifos.push_back(tmp);
    }
}

void Level::push(Packet package, int index) {
    fifos[index].push(package);
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
