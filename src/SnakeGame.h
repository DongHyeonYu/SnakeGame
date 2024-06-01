#ifndef _SNAKEGAME_H
#define _SNAKEGAME_H

#include <ncurses.h>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <vector>
#include <algorithm>

#include "Map.h" // Map 
#include "Snake.h" // Snake

class SnakeGame{
void init();
void draw(const std::vector<std::vector<int>> &current_map);
void input();
void goForward();
bool checkCollision();
void endGame();

bool gameOver;
Snake snake; 
  
public:  
  SnakeGame();
  void run();
};
#endif
