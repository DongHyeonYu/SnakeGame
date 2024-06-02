#include "SnakeGame.h" // Header File
#include <iostream>

Map map(0);
vector<vector<int>> current_map = map.getMap(0);

const int WIDTH = map.getWidth();
const int HEIGHT = map.getHeight();

using namespace std;
 
SnakeGame::SnakeGame() : gameOver(false), snake(WIDTH, HEIGHT) {
  init();
  srand(time(0));
} 

void SnakeGame::init() {
  initscr();
  clear();
  noecho();
  cbreak();
  curs_set(0);
  
  keypad(stdscr, TRUE);
  timeout(100);
}

void SnakeGame::run() {
  while (!gameOver) {
    draw(current_map);
    if (checkCollision()) {
      endGame();
    }
    if(!input()){
      goForward();
    }
    manageItems();
    checkItemCollision();
    usleep(100000);
  }
  endwin();
}

void SnakeGame::draw(const vector<vector<int>> &current_map) {
  clear();

  const wchar_t wall = L'◼';
  const wchar_t head = L'●';
  const wchar_t body = L'○';
  const wchar_t space = ' ';
  const wchar_t growthItem = L'▲';
  const wchar_t poisonItem = L'▼';
  for (int y=0; y<HEIGHT; ++y) {
    for (int x=0; x<WIDTH; ++x) {
      if (current_map[y][x]==1 || current_map[y][x]==2){
        mvaddnwstr(y, x * 2, &wall, 1); 
      }
      else {
        bool isSnakePart = false;

        for (int s = 0; s<snake.getLength(); ++s) {
          if (snake.body[s].first == y && snake.body[s].second == x) {
            if (s == 0) {
              mvaddnwstr(y, x * 2, &head, 1); // Head
            } 
            else {
              mvaddnwstr(y, x * 2, &body, 1); // Body
            }
            isSnakePart = true;
            break;
          }
        }

        if (!isSnakePart) {
          bool isItemPart = false;
          for(int s =0; s< items.size(); ++s){
            if(items[s].getPosition().first == y && items[s].getPosition().second == x){
              if(items[s].getIsGrowth()){
                mvaddnwstr(y, x * 2, &growthItem, 1); // growthItem
              }
              else{
                mvaddnwstr(y, x * 2, &poisonItem, 1); // poisonItem
              }
              isItemPart = true;
              break;
            }
          }
          if(!isItemPart){
            mvaddnwstr(y, x * 2, &space, 1); // Empty space
          }
        }
      }
      refresh();
    }
  }
}     

void SnakeGame::goForward() {
    snake.move();
}

bool SnakeGame::input() {
  int ch = getch();
  switch (ch) {
    case KEY_UP:
        if (snake.dir != DOWN){
          snake.dir = UP;
        }
        else{
          endGame();
        }
        break;
    case KEY_DOWN:
        if (snake.dir != UP){
            snake.dir = DOWN;

        }
        else{
            endGame();
        }
        break;
    case KEY_LEFT:
        if (snake.dir != RIGHT){
            snake.dir = LEFT;

        }
        else{
            endGame();
        }
        break;
    case KEY_RIGHT:
        if (snake.dir != LEFT){
            snake.dir = RIGHT;

        }
        else{
            endGame();
        }
        break;
    }
  snake.move();
  if(ch){
    return true;
  }
  else{
    return false;
  }
}

void SnakeGame::manageItems(){
  for(auto it = items.begin(); it != items.end(); ){
    it -> setTime(it->getTime() + 1);

    // item이 ITEM_DURATION보다 더 필드 위에 있으면 삭제
    if(it->getTime() > ITEM_DURATION) {
      it = items.erase(it);
    } else{
      ++it;
    }
  }

  // 최대 item은 3개
  while(items.size() < MAX_ITEMS){
    Item newItem(WIDTH, HEIGHT);

    bool onSnake = false;

    // 만약 아이템 위치에 스네이크가 없으면 아이템 생성
    for(int i=0; i< snake.getLength(); ++i){
      if(snake.body[i] == newItem.getPosition()){
        onSnake = true;
        break;
      }
    }

    if(!onSnake){
      items.push_back(newItem);
    }
  }
}

bool SnakeGame::checkCollision() {
  pair<int, int> head = snake.body[0];
  int y = head.first;
  int x = head.second;
  if (current_map[y][x]==1) return true; 
  if (x <= 0 || x >= WIDTH - 1 || y <= 0 || y >= HEIGHT - 1 ) {
    return true;
  }
  for (int i = 1; i < snake.getLength(); ++i) {
    if (snake.body[i].first == y && snake.body[i].second == x) {
      return true;
    }
  }
  return false;
}

bool SnakeGame::checkItemCollision(){
  auto head = snake.body.front();
  for (auto it = items.begin(); it != items.end(); ) {
      if (head == it->getPosition()) {
          if (it->getIsGrowth()) {
              snake.grow();
          } else {
              if (snake.getLength() > 3) { // snake의 몸이 3이하면 사망
                  snake.body.pop_back();
              } else {
                  endGame();
              }
          }
          it = items.erase(it);
          return true;
      } else {
          ++it;
      }
  }
  return false;
}

void SnakeGame::endGame() {
  gameOver = true;
  mvprintw(HEIGHT / 2, WIDTH / 2 - 5, "Game Over!");
  refresh();
  nodelay(stdscr, FALSE);
  getch();
}