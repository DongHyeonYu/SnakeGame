#include "Mission.h"

Mission::Mission(){
  //{bodyLength, growthItem, poisonItem, Gate}
  
  stage1 = {5,3,1,1};
  stage2 = {7,5,2,2};
  stage3 = {9,7,3,3};
  stage4 = {11,9,4,4};
  stage5 = {13,11,5,5};
  //stage1 = {3,0,0,0};
  //stage2 = {3,0,0,0};
  //stage3 = {3,0,0,0};
  //stage4 = {3,0,0,0};
  //stage5 = {3,0,0,0};
  
  current = stage1;
  
}

vector<int> Mission::getMission(const int stage){
  switch (stage) {
    case 0:
      current = stage1;
      break;
    case 1:
      current = stage2;
      break;
    case 2:
      current = stage3;
      break;
    case 3:
      current = stage4;
      break;
    case 4:
      current = stage5;
      break;
  }
  return current;
}
