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
#include "ScoreBoard.h"
#include "StageManager.h"

using namespace std;

class SnakeGame{
  void init();
  void draw(const vector<vector<int>> current_map);
  bool input();
  void goForward();
  bool checkCollision();
  void endGame();
  void manageItems();
  void manageGate();
  void checkItemCollision();
  void checkGateEnter();
  void makeMap();

  bool gameOver;
  bool isCleared;
  int stage;
  int timeTick;

  Snake snake;
  Gate gate;
  vector<Item> items;
  ScoreBoard board;
  StageManager stageManager;
  Map map;

  static const int ITEM_DURATION = 50; // 아이템 지속시간 최대 5초
  static const int GATE_DURATION = 100; // 게이트 지속시간 최대 10초
  static const int MAX_ITEMS = 3;
  static const int GATE_COOLDOWN = 20; // 게이트 재생성 대기 시간

  
public:
  SnakeGame();
  void run();  
};
#endif
