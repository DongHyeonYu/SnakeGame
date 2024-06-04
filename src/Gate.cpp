#include "Gate.h"
#include <cstdlib>
#include <ctime>

Gate::Gate(int width, int height) {
    srand(time(0));
    genGate(width, height, vector<vector<int>>(), deque<pair<int, int>>());
    curTime = -20;
}

void Gate::genGate(int width, int height, const vector<vector<int>>& map, const deque<pair<int, int>>& snakeBody) {
    bool validGate = false;
    while (!validGate) {
        g1pos.first = rand() % height;
        g1pos.second = rand() % width;
        g2pos.first = rand() % height;
        g2pos.second = rand() % width;

        if (map.empty() || map[0].empty()) return;

        if (map[g1pos.first][g1pos.second] == 1 && map[g2pos.first][g2pos.second] == 1) {
            validGate = true;
            for (const auto& part : snakeBody) {
                if (part == g1pos || part == g2pos) {
                    validGate = false;
                    break;
                }
            }
            if(g1pos.first == g2pos.first && g1pos.second == g2pos.second) validGate = false;
        }
        else continue;
    }
    
}

pair<int, int> Gate::getGate1Pos() {
    return g1pos;
}

pair<int, int> Gate::getGate2Pos() {
    return g2pos;
}

void Gate::setTime(int t) {
    curTime = t;
}

int Gate::getTime() {
    return curTime;
}

//진출 도중 게이트 소멸을 방지할 시간 일시정지/시작 기능
void Gate::pauseTime() {
    if (!isPaused) {
        pausedTime = curTime;
        isPaused = true;
    }
}

void Gate::resumeTime() {
    if (isPaused) {
        curTime = pausedTime;
        isPaused = false;
    }
}
