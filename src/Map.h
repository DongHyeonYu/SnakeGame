#ifndef MAP_H
#define MAP_H

#include <vector>

class Map{

int WIDTH = 21;
int HEIGHT = 21;
std::vector<std::vector<std::vector<int> > >  map;
std::vector<std::vector<int> > current_map;

public:
  Map(const int stage); //생성자
  std::vector<std::vector<int> > getMap(const int stage);
  int getWidth();
  int getHeight();
  wchar_t wall;
};
#endif 
