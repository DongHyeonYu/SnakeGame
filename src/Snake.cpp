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

void Snake::grow(){
    body.push_back(body.back());
}

int Snake::getLength(){
    return body.size();
}
