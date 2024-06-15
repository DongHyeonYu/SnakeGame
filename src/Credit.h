#ifndef CREDIT_H
#define CREDIT_H

#include <ncurses.h>
#include <vector> 
#include <string>

using namespace std;

class Credit{
  vector<vector<int>> creditMap;
  wstring title1, title2, title3, title4, title5, title6;  
  string menu1, menu2, menu3;
  wstring maker, maker_end, name1, name2, name3;
  int currentSelection;
  const wchar_t wall, lud, rud, ldd, rdd, space;
public:
  Credit();

  void init();
  void draw();
  void start();
  void end();
  int showMenu();
  void showHowToPlay();
};
#endif
