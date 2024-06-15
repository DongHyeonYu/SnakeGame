#include "SnakeGame.h"
#include "Credit.h"
#include <locale.h>

int main(){
  setlocale(LC_ALL, "");
  Credit credit;
  SnakeGame game;
  int flag = 0;
  while (true){
    flag = credit.showMenu();
    if (flag == -1){
    	endwin();
    	break;
    }
    game.run();
  }
  return 0;
}
