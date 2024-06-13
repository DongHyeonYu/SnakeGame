#ifndef MAP_H
#define MAP_H

#include <vector>
using namespace std;
class Map{

int WIDTH = 21;
int HEIGHT = 21;
vector<vector<vector<int>>> map;
vector<vector<int> > current_map;

public:
  Map(); //생성자
  vector<vector<int> > getMap(const int stage);
  int getWidth();
  int getHeight();
  wchar_t wall;
  void setMap(int stage, int y, int x, int val);
  void setAllMap(int stage, const vector<vector<int>> newMap);
};
#endif 
