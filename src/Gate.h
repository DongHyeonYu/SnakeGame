#ifndef GATE_H
#define GATE_H

#include <vector>
#include <deque>
using namespace std;

class Gate {
    pair<int, int> g1pos, g2pos;
    int curTime;
    int pausedTime; // 일시정지 시간 저장
    bool isPaused;

public:
    Gate(int width, int height);

    void genGate(int width, int height, const vector<vector<int>>& map, const deque<pair<int, int>>& snakeBody);
    pair<int, int> getGate1Pos();
    pair<int, int> getGate2Pos();
    
    void setTime(int t);
    int getTime();

    void pauseTime();
    void resumeTime();
};

#endif
