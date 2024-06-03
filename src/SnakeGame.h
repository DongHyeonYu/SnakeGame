#ifndef _SNAKEGAME_H
#define _SNAKEGAME_H

#include <ncurses.h>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <algorithm>

#include "Map.h"
#include "Snake.h"
#include "Item.h"
#include "Gate.h"

using namespace std;

class SnakeGame{
  void init();
  void draw(const vector<vector<int>> &current_map);
  bool input();
  void goForward();
  bool checkCollision();
  void endGame();
  void manageItems();
  void manageGate();
  bool checkItemCollision();
  void checkGateEnter();

  bool gameOver;
  Snake snake;
  Gate gate;
  vector<Item> items;

  static const int ITEM_DURATION = 50; // 아이템 지속시간 최대 5초
  static const int GATE_DURATION = 100; // 게이트 지속시간 최대 10초
  static const int MAX_ITEMS = 3;
  static const int GATE_COOLDOWN = 30; // 게이트 재생성 대기 시간

  
public:
  SnakeGame();
  void run();
};
#endif
