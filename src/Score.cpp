#include "Score.h"

Score::Score(){
  lengthScore = 3;
  growthScore = 0;
  poisonScore = 0;
  gateScore = 0;
  score = {lengthScore, growthScore, poisonScore, gateScore};
}

vector<int> Score::getScore(){
  return score;
}

void Score::resetScore(){
  lengthScore = 3;
  growthScore = 0;
  poisonScore = 0;
  gateScore = 0;
  update();
}

void Score::update(){
  score = {lengthScore, growthScore, poisonScore, gateScore};
}

void Score::increaseLengthScore(){
  ++lengthScore;
  update();
}
void Score::increaseGrowthScore(){
  ++growthScore;
  update();
}
void Score::increasePoisonScore(){
  ++poisonScore;
  update();
}
void Score::increaseGateScore(){
  ++gateScore;
  update();
}
void Score::decreaseLengthScore(){
  --lengthScore;
  update();
}
