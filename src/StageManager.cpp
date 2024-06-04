#include "StageManager.h"

StageManager::StageManager(){
};

vector<int> StageManager::getScore(){
  return score.getScore();
}

void StageManager::increaseLengthScore(){
  score.increaseLengthScore();
}
void StageManager::increaseGrowthScore(){
  score.increaseGrowthScore();
  }
void StageManager::increasePoisonScore(){
  score.increasePoisonScore();
}
void StageManager::increaseGateScore(){
  score.increaseGateScore();
}
void StageManager::decreaseLengthScore(){
  score.decreaseLengthScore();
}

int StageManager::getCurrentStage(){
  return stage;
}

void StageManager::nextStage(){
  ++stage;
}
void StageManager::resetScore(){
  score.resetScore();
}
