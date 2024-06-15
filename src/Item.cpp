#include "Item.h"
#include <utility>
#include <cstdlib>
#include <ctime>
#include <vector>

Item::Item(int width, int height) {
    srand(time(0));
    generateNewPosition(width, height);
    curTime = 0;
    itemType = rand() % 4; // 0 이면 Growth 1이면 Poison 2이면 FastTick
}

void Item::generateNewPosition(int width, int height) {
    pos.first = rand() % height;
    pos.second = rand() % width;
}

pair<int, int> Item::getPosition() {
    return pos;
}

int Item::getItemType() {
    return itemType;
} 

void Item::setTime(int t) {
    curTime = t;
}

int Item::getTime() {
    return curTime;
}