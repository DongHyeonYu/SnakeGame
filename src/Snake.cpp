#include "Snake.h"
#include <iostream>
using namespace std;

Snake::Snake(int width, int height){
    dir = LEFT; // 처음엔 LEFT로 
    // 초기 Snake의 위치는 가운데
    body.push_back(make_pair(height/2, width/2-1));
    body.push_back(make_pair(height/2, width/2));
    body.push_back(make_pair(height/2, width/2+1));
}

void Snake::move() {
    auto head = body.front();
    pair<int, int> newHead = head;
    
    switch (dir) {
        case LEFT: newHead.second--; break;
        case RIGHT: newHead.second++; break;
        case UP: newHead.first--; break;
        case DOWN: newHead.first++; break;
    }
    body.push_front(newHead);
    body.pop_back();
}

//게이트 진입 시 헤드 좌표 변경
void Snake::gateEntry(const pair<int, int> pos, const Direction dir){
    auto head = body.front();
    pair<int, int> newHead = head;
    switch(dir){
        case UP:
            newHead.first = pos.first - 1;
            newHead.second = pos.second;
            break;
        case DOWN:
            newHead.first = pos.first + 1;
            newHead.second = pos.second;
            break;
        case RIGHT:
            newHead.first = pos.first;
            newHead.second = pos.second + 1;
            break;
        case LEFT:
            newHead.first = pos.first;
            newHead.second = pos.second - 1;
            break;
    }
    body.push_front(newHead);
    body.pop_back();
}

//게이트 진출 시 방향 설정
Direction Snake::gateDicisionDir(int width, int height, Direction dir, const pair<int, int> pos, const vector<vector<int>>& map){
    int dirNum;
    Direction dirList[4] = {UP, RIGHT, DOWN, LEFT};
    for(int i = 0; i < 4; i++){
        if(dir == dirList[i]) {
            dirNum = i;
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        Direction newDir = dirList[(dirNum + i) % 4];
        switch (newDir) {
            case UP:
                if (pos.first - 1 >= 0 && map[pos.first - 1][pos.second] == 0) return UP;
                break;
            case RIGHT:
                if (pos.second + 1 < map[0].size() && map[pos.first][pos.second + 1] == 0) return RIGHT;
                break;
            case DOWN:
                if (pos.first + 1 < map.size() && map[pos.first + 1][pos.second] == 0) return DOWN;
                break;
            case LEFT:
                if (pos.second - 1 >= 0 && map[pos.first][pos.second - 1] == 0) return LEFT;
                break;
        }
    }
    return dir;
}

void Snake::grow(){
    body.push_back(body.back());
}

int Snake::getLength(){
    return body.size();
}
