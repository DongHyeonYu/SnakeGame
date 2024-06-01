#include "SnakeGame.h"
#include <locale.h>

int main(){
  setlocale(LC_ALL, "");
  SnakeGame game;
  game.run();
  return 0;
}
