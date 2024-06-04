#ifndef MISSION_H
#define MISSION_H

#include <vector>
using namespace std;

class Mission{
  vector<int> stage1;
  vector<int> stage2;
  vector<int> stage3;
  vector<int> stage4;
  vector<int> stage5;
  vector<int> current;
public:
  Mission();
  vector<int> getMission(const int stage);
};

#endif
