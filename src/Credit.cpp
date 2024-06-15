#include "Credit.h"

#define WIDTH 40
#define HEIGHT 23
Credit::Credit():wall(L'■'),lud(L'◢'),rud(L'◣'), ldd(L'◥'), rdd(L'◤'),space(L' ')
  {
  creditMap = {
  		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,4,2,2,2,2,2,2,2,2,2,2,2,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,6,2,2,2,2,2,2,2,2,2,2,2,7,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  };
  title1 = L"  _____             _          _____";                       
  title2 = L" / ____|           | |        / ____|";                     
  title3 = L"| (___  _ __   __ _| | __ ___ | |  __  __ _ _ __ ___   ___"; 
  title4 = L" \\___ \\| '_ \\ /  ` | |/ // _ \\| | |_ |/ _` | '_ ` _ \\ / _ \\";
  title5 = L" ____) | | | | (_| | ' <|  __/| |__| | (_| | | | | | | | _/";
  title6 = L"|_____/|_| |_|\\__,_|_|\\_\\\\___|\\_____/ \\__,_|_| |_| |_|\\___|";
                             
  menu1 = "Game Start";
  menu2 = "How To Play";
  menu3 = "Exit";
  
  currentSelection = 0; 
  
  maker = L"======Maker======";
  name1 = L"|20203104 유동현|";
  name2 = L"|20212972 김민찬|";
  name3 = L"|20213074 장종아|";
  maker_end = L"=================";
}
void Credit::init(){
  initscr();
  clear();
  noecho();
  cbreak;
  curs_set(0);
  keypad(stdscr, TRUE);
}
void Credit::draw(){
  clear();
  for (int y = 0; y<HEIGHT; ++y){
    for (int x = 0; x<WIDTH; ++x){
      if (creditMap[y][x] == 1) mvaddnwstr(y, x * 2, &wall, 1);
      else if (creditMap[y][x] == 2) mvaddnwstr(y, x*2, &wall, 1);
      else if (creditMap[y][x] == 4) mvaddnwstr(y, x*2, &wall ,1);
      else if (creditMap[y][x] == 5) mvaddnwstr(y, x*2, &wall ,1);
      else if (creditMap[y][x] == 6) mvaddnwstr(y, x*2, &wall, 1);
      else if (creditMap[y][x] == 7) mvaddnwstr(y, x*2, &wall, 1);
      else mvaddnwstr(y, x *2, &space, 1);
    }
  }
  mvprintw(3, 11, "%ls", title1.c_str());
  mvprintw(4, 11, "%ls", title2.c_str());
  mvprintw(5, 11, "%ls", title3.c_str());
  mvprintw(6, 11, "%ls", title4.c_str());
  mvprintw(7, 11, "%ls", title5.c_str());
  mvprintw(8, 11, "%ls", title6.c_str());
  
  mvprintw(16, 59, "%ls", maker.c_str());
  mvprintw(17, 59, "%ls", name1.c_str());
  mvprintw(18, 59, "%ls", name2.c_str());
  mvprintw(19, 59, "%ls", name3.c_str());
  mvprintw(20, 59, "%ls", maker_end.c_str());
  
}
int Credit::showMenu(){
  int ch;
  while (true) { 
    draw();
    
    mvprintw(13, 34, "%s", menu1.c_str());
    mvprintw(15, 34, "%s", menu2.c_str());
    mvprintw(17, 34, "%s", menu3.c_str());
    
    if (currentSelection == 0) {
      mvchgat(13, 33, 13, A_REVERSE, 0, NULL);
    } 
    else if (currentSelection == 1) {
      mvchgat(15, 33, 13, A_REVERSE, 0, NULL);
    }
    else if (currentSelection == 2) {
      mvchgat(17, 33, 13, A_REVERSE, 0, NULL);
    }
    refresh();
    
    ch = getch();    
    switch (ch) {
      case KEY_UP:
        if (currentSelection == 0){
          currentSelection = 2;
        }
        else{
          currentSelection --;
        }
        break;
      case KEY_DOWN:
        if (currentSelection == 2){
          currentSelection == 0;
        }
        else {
         currentSelection ++;
        }
        
        break;
      case '\n':
        if (currentSelection == 0) {
          endwin();
          return 0;
        } 
        else if (currentSelection == 1){
          showHowToPlay();
        }
        
        else if (currentSelection == 2) {
        endwin();
        return -1;
        }
        break;
    }
  }
}
void Credit::showHowToPlay()
{
  wstring rule0, rule1, rule2, rule3, rule4, rule5, rule6, rule7, rule8, rule9, rule10, rule11;
  rule0 = L"How To Play?";
  rule1 = L"1. You can change the direction with the input.";
  rule2 = L"2. If you hit the wall, the game will end.";
  rule3 = L"3. If press the key in the direction of your body, the game will end.";
  rule4 = L"4. The game ends when the length of the snake becomes 3 or less.";
  rule5 = L"5. If you clear the mission, you will move on to the next stage.";
  rule6 = L"==============================Item====================================";
  rule7 = L"🍎 : Growth Item. When you eat it, its length becomes longer.";
  rule8 = L"💀 : Poison Item. When you eat it, its length becomes shorter.";
  rule9 = L"🌀 : Gate. When you go in, you come out on the other side.";
  rule10 = L"⏩ : SpeedUP. When you eat it, make you faster";
  rule11 = L"⏪ : SpeedDown. When you eat it, make you slower";
  clear();
  for (int y = 0; y<HEIGHT; ++y){
    for (int x = 0; x<WIDTH; ++x){
      if (creditMap[y][x] == 1) mvaddnwstr(y, x * 2, &wall, 1);
      else mvaddnwstr(y, x *2, &space, 1);
    }
  }
  mvprintw(2, 4, "%ls", rule0.c_str());
  mvprintw(4, 4, "%ls", rule1.c_str());
  mvprintw(6, 4, "%ls", rule2.c_str());
  mvprintw(8, 4, "%ls", rule3.c_str());
  mvprintw(10, 4, "%ls", rule4.c_str());
  mvprintw(12, 4, "%ls", rule5.c_str());
  
  mvprintw(14, 4, "%ls", rule6.c_str());
  mvprintw(16, 4, "%ls", rule7.c_str());
  mvprintw(17, 4, "%ls", rule8.c_str());
  mvprintw(18, 4, "%ls", rule9.c_str());
  mvprintw(19, 4, "%ls", rule10.c_str());
  mvprintw(20, 4, "%ls", rule11.c_str());
  refresh();
  int ch1;
  while (true){
    ch1 = getch();
    if (ch1 != ERR) break;
  }
}






