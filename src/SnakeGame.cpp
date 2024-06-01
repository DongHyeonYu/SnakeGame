
#include "SnakeGame.h" // Header File


  
Map map(0);
vector<vector<int>> current_map = map.getMap(0);

const int WIDTH = map.getWidth();
const int HEIGHT = map.getHeight();
 
SnakeGame::SnakeGame() : gameOver(false), snake(WIDTH, HEIGHT) {
  init();
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
    input();
    if (checkCollision()) {
      endGame();
    }
    goForward();
    usleep(100000);
  }
  endwin();
}

void SnakeGame::draw(const std::vector<std::vector<int>> &current_map) {
  clear();

  const wchar_t wall = L'◼';
  const wchar_t head = L'●';
  const wchar_t body = L'○';
  const wchar_t space = ' ';
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
                mvaddnwstr(y, x * 2, &head, 1); // Draw the head
              } 
              else {
                mvaddnwstr(y, x * 2, &body, 1); // Draw the body
              }
              isSnakePart = true;
              break;
            }
          }
        if (!isSnakePart) {
          mvaddnwstr(y, x * 2, &space, 1); // Empty space
        }
      }
    }
  }
}     

void SnakeGame::input() {
  int ch = getch();
  switch (ch) {
    case KEY_UP:
      if (snake.dir != DOWN){
        snake.dir = UP;
        snake.moveUp();
      }
      else{
        endGame();
      }
      break;
    case KEY_DOWN:
        if (snake.dir != UP){
            snake.dir = DOWN;
            snake.moveDown();
        }
        else{
            endGame();
        }
        break;
    case KEY_LEFT:
        if (snake.dir != RIGHT){
            snake.dir = LEFT;
            snake.moveLeft();
        }
        else{
            endGame();
        }
        break;
    case KEY_RIGHT:
        if (snake.dir != LEFT){
            snake.dir = RIGHT;
            snake.moveRight();
        }
        else{
            endGame();
        }
        break;
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
void SnakeGame::endGame() {
  gameOver = true;
  mvprintw(HEIGHT / 2, WIDTH / 2 - 5, "Game Over!");
  refresh();
  nodelay(stdscr, FALSE);
  getch();
}

void SnakeGame::goForward() {
    switch (snake.dir) {
    case UP:
        snake.moveUp();
        break;
    case DOWN:
        snake.moveDown();
        break;
    case LEFT:
        snake.moveLeft();
        break;
    case RIGHT:
        snake.moveRight();
        break;
    }
}
