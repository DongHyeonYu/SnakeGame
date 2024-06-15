#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <ncurses.h>
#include <vector>
#include <locale.h>
#include <string>
using namespace std;

#include "Mission.h"
#include "StageManager.h"

#define BOARD_W 15
#define BOARD_H 21
#define MAP_W 44
#define CHAR_X MAP_W+7
#define MAX_PROGRESS 5

class ScoreBoard{
  vector<vector<int>> scoreBoard; 
  vector<int> currentMission;
  vector<int> currentScore;
  const wchar_t boardWall = L'■';
  const wchar_t partition = L'║';
  StageManager stageManager;
  Mission mission;
  
  
  
  //int lengthProgress, growthProgress, poisonProgress, gateProgress;
  wstring lengthProgressBar, growthProgressBar, poisonProgressBar, gateProgressBar;
  string LENGTH, GROWTH, POISON, GATE;
  int lengthScore, growthScore, poisonScore, gateScore;
  int currentStage;
  int adjust; 
public:  
  ScoreBoard();
  
  bool flag, lengthCleared, growthCleared, poisonCleared, gateCleared;
  void resetScore();
  void drawBoard();
  void printScore();
  int getCurrentStage();
  void increase(const int item);
  bool isCleared(bool &length, bool &growth, bool &poison, bool &gate);
};

#endif

