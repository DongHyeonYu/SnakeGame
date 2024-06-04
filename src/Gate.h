#ifndef GATE_H
#define GATE_H

#include <vector>
#include <deque>
using namespace std;

class Gate {
    pair<int, int> g1pos;
    pair<int, int> g2pos;
    int curTime;
    bool isPaused;
    int pausedTime;

public:
    Gate(int width, int height);

    void genGate(int width, int height, const vector<vector<int>>& map, const deque<pair<int, int>>& snakeBody);
    pair<int, int> getGate1Pos();
    pair<int, int> getGate2Pos();
    void pauseTime();
    void resumeTime();
    void setTime(int t);
    int getTime();
};

#endif
