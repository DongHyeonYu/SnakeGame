#include "SnakeGame.h"
#include "Credit.h"
#include <locale.h>

int main(){
  setlocale(LC_ALL, "");
  Credit credit;
  int flag = 0;
  while (true){
    SnakeGame game;
    
    flag = credit.showMenu();
    if (flag == -1){
    	endwin();
    	break;
    }
    game.run();
  }
  return 0;
}
