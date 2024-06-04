#ifndef SCORE_H
#define SCORE_H

#include <vector>
using namespace std;

class Score{
  int lengthScore, growthScore, poisonScore, gateScore;
  vector<int> score; 
  void update();

public:
  Score();
  vector<int> getScore();
  void resetScore();
  
  void increaseLengthScore();
  void increaseGrowthScore();
  void increasePoisonScore();
  void increaseGateScore();
  
  void decreaseLengthScore();
  

};  
#endif
