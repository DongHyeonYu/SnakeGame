#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

#include<vector>

#include "Score.h"

using namespace std;

class StageManager{
  int stage = 0;
  Score score;
  
public:
  StageManager();
  vector<int> getScore();
  void resetScore();
  
  void increaseLengthScore();
  void increaseGrowthScore();
  void increasePoisonScore();
  void increaseGateScore();
  
  void decreaseLengthScore();
  
  int getCurrentStage();
  void nextStage();
  
};
#endif
