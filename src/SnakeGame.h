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

using namespace std;

class SnakeGame{
  void init();
  void draw(const vector<vector<int>> &current_map);
  bool input();
  void goForward();
  bool checkCollision();
  void endGame();
  void manageItems();
  bool checkItemCollision();

  bool gameOver;
  Snake snake;
  vector<Item> items;

  static const int ITEM_DURATION = 50; // 아이템 지속시간 최대 5초
  static const int MAX_ITEMS = 3;
  
public:  
  SnakeGame();
  void run();
};
#endif
