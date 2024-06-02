#include "Item.h"
#include <utility>
#include <cstdlib>
#include <ctime>
#include <vector>

Item::Item(int width, int height) {
    srand(time(0));
    generateNewPosition(width, height);
    curTime = 0;
    isGrowth = rand() % 2;
}

void Item::generateNewPosition(int width, int height) {
    pos.first = rand() % height;
    pos.second = rand() % width;
}

pair<int, int> Item::getPosition() {
    return pos;
}

bool Item::getIsGrowth() {
    return isGrowth;
}

void Item::setTime(int t) {
    curTime = t;
}

int Item::getTime() {
    return curTime;
}