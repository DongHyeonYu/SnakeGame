#include "SnakeGame.h" // Header File
#include <iostream>

int debug = 0;
Map refMap;
const int WIDTH = refMap.getWidth();
const int HEIGHT = refMap.getHeight();
// 이거도 map에 width랑 height불러오는거 고쳐야할듯 

pair<int, int> head_lc = make_pair(-1, -1);

using namespace std;
 
SnakeGame::SnakeGame() : gameOver(false), snake(WIDTH, HEIGHT), gate(WIDTH, HEIGHT), stage(0), timeTick(100000) {
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
  bool inputProcessed = false;
  while (!gameOver) {
      isCleared = false;
      isCleared = board.isCleared(board.lengthCleared, board.growthCleared, board.poisonCleared, board.gateCleared);
      stage = board.getCurrentStage();
    if(!isCleared){
      stage = board.getCurrentStage();

      makeMap(); // map에 요소들 뱀, 아이템 위치 저장 시키고(현재는 map클래스의 map변수에다가 직접 변경)

      draw(map.getMap(stage));

      if (checkCollision()) {
        endGame();
      }
      if (!inputProcessed) {
        inputProcessed = input();
      }

      goForward();
      manageItems();
      manageGate();
 
      checkItemCollision();

      if (gate.getTime() > 0) checkGateEnter();
      usleep(timeTick);

      inputProcessed = false;
    }
    else{
      isCleared = false;
      clear();
      mvprintw(9, 33, "================");
      mvprintw(10, 33, "* Stage Clear! *");
      mvprintw(11, 33, "================");
      mvprintw(13, 33, "    Press Key...");
      refresh();
      timeTick = 100000;
      snake.resetSnake(WIDTH, HEIGHT);
      board.resetScore();
      isCleared = false;
      nodelay(stdscr, FALSE);
      getch();
      timeout(100);
    }
  }
  endwin();
}

void SnakeGame::makeMap(){
  Map tmpMap;

  vector<vector<int>> copiedMap = tmpMap.getMap(stage);

  map.setAllMap(stage, tmpMap.getMap(stage));

  // map에다가 아이템 그리기
  for(int s = 0; s < items.size(); ++s){
    int curY = items[s].getPosition().first;
    int curX = items[s].getPosition().second;

    if(items[s].getItemType() == 0){
      map.setMap(stage, curY, curX, 5); // Growth Item은 5
    }
    else if(items[s].getItemType() == 1){
      map.setMap(stage, curY, curX, 6); // Poison Item은 6
    }
    else if(items[s].getItemType() == 2){
      map.setMap(stage, curY, curX, 7);
    }
    else if(items[s].getItemType() == 3){
      map.setMap(stage, curY, curX, 8);
    }
  }

  // map에다가 뱀 그리기
  for (int s = 0; s < snake.getLength(); ++s) {
    
    int curY = snake.body[s].first;
    int curX = snake.body[s].second;

    // 만약 벽이면은 밑에 collision함수에서 충돌 알아서 처리하게 무시
    if(map.getMap(stage)[curY][curX] == 1){
      continue;
    }

    if (s == 0) {
      map.setMap(stage, curY, curX, 3); // Head는 3
    } else {
      map.setMap(stage, curY, curX, 4); // Body는 4                        
    }
  }
}

void SnakeGame::draw(const vector<vector<int>> current_map) {
    clear();
    const wchar_t wall = L'🧱';
    const wchar_t head = L'😈';
    const wchar_t body = L'🟣';
    const wchar_t space = ' ';
    const wchar_t growthItem = L'🍎';
    const wchar_t poisonItem = L'💀';
    const wchar_t gatemark = L'🌀';
    const wchar_t fastItem = L'⏩';
    const wchar_t slowItem = L'⏪';
    const wchar_t block = L'■';
    const wstring border = L"■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■"; 
    mvprintw(0, 0, "%ls", border.c_str());
    mvprintw(22, 0, "%ls", border.c_str());
    int adjust = 4;
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            mvaddnwstr(y+1,0, &block, 1); 
            mvaddnwstr(y+1,78, &block, 1);
            if (current_map[y][x] == 1 || current_map[y][x] == 2) {
                mvaddnwstr(y+1, x * 2+adjust, &wall, 1); // Wall
            } 
            else if(current_map[y][x] ==3){
              mvaddnwstr(y+1, x * 2+adjust, &head, 1); // Head
            }
            else if(current_map[y][x] == 4){
              mvaddnwstr(y+1, x * 2+adjust, &body, 1); // Body
            }
            else if(current_map[y][x] == 5){
              mvaddnwstr(y+1, x * 2+adjust, &growthItem, 1); // Growth Item
            }
            else if(current_map[y][x] == 6){
              mvaddnwstr(y+1, x * 2+adjust, &poisonItem, 1); // Growth Item
            }
            else if(current_map[y][x] == 7){
              mvaddnwstr(y+1, x * 2+adjust, &fastItem, 1); // Fast Item
            }
            else if(current_map[y][x] == 8){
              mvaddnwstr(y+1, x * 2+adjust, &slowItem, 1); // Slow Item
            }
            else{
              mvaddnwstr(y+1, x * 2+adjust, &space, 1); // Empty space
            }
            
            board.drawBoard();
            board.printScore();
            // Gate 표시를 벽과 다른 순서로 처리하여 위치 조정
            if (gate.getTime() >= 0) { // 게이트가 활성화된 상태일 때만 그리기
                bool isGate = (y == gate.getGate1Pos().first && x == gate.getGate1Pos().second) || (y == gate.getGate2Pos().first && x == gate.getGate2Pos().second);

                if (isGate) {
                    mvaddnwstr(y+1, x * 2+adjust, &gatemark, 1); // Gate
                }
            }
        }
    }
    refresh();
}
     

void SnakeGame::goForward() {
    snake.move();
}


bool SnakeGame::input() {
  int ch = getch();
  switch (ch) {
    case KEY_UP:
        if (snake.dir != DOWN && snake.dir != UP) snake.dir = UP;
        else if(snake.dir == UP) return false;
        break;
    case KEY_DOWN:
        if (snake.dir != UP && snake.dir != DOWN) snake.dir = DOWN;
        else if(snake.dir == DOWN) return false;
        break;
    case KEY_LEFT:
        if (snake.dir != RIGHT && snake.dir != LEFT) snake.dir = LEFT;
        else if(snake.dir == LEFT) return false;
        break;
    case KEY_RIGHT:
        if (snake.dir != LEFT && snake.dir != RIGHT) snake.dir = RIGHT;
        else if(snake.dir == RIGHT) return false;
        break;
    default:
        return false;
  }
  return true;
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

  vector<vector<int>> current_map = refMap.getMap(stage);
  // 최대 item은 3개
  if(items.size() < MAX_ITEMS){
    Item newItem(WIDTH, HEIGHT);

    pair<int, int> itemPos = newItem.getPosition();

    if(current_map[itemPos.first][itemPos.second] != 0 ){
      return;
    }

    for(int i=0; i<items.size(); ++i){
      if(itemPos == items[i].getPosition()){
        return;
      }
    }

    items.push_back(newItem);
  }
}

void SnakeGame::manageGate(){
  gate.setTime(gate.getTime() + 1);
  vector<vector<int>> current_map = map.getMap(stage);

    // 게이트가 GATE_DURATION보다 더 필드 위에 있으면 삭제하고 대기시간 시작
    if (gate.getTime() > GATE_DURATION) {
        map.setMap(stage, gate.getGate1Pos().first, gate.getGate1Pos().second, 2);
        map.setMap(stage, gate.getGate2Pos().first, gate.getGate2Pos().second, 2);
        gate.setTime(-GATE_COOLDOWN);
    }

    // 대기시간이 끝나면 새로운 게이트 생성
    if (gate.getTime() == 0) {
        gate.genGate(WIDTH, HEIGHT, current_map, snake.body);
        map.setMap(stage, gate.getGate1Pos().first, gate.getGate1Pos().second, 0);
        map.setMap(stage, gate.getGate2Pos().first, gate.getGate2Pos().second, 0);
    }
}

bool SnakeGame::checkCollision() {
  vector<vector<int>> current_map = map.getMap(stage);

  pair<int, int> head = snake.body[0];
  int y = head.first;
  int x = head.second;
  if (current_map[y][x]==1 ) {
    return true;
  } 
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

void SnakeGame::checkItemCollision(){
  auto head = snake.body.front();
  for (auto it = items.begin(); it != items.end(); ) {
      if (head == it->getPosition()) {
          if (it->getItemType() == 0) {
              //Need to Adjustment
              board.increase(5);
              //===================
              snake.grow();
          } else if (it->getItemType() == 1){
              if (snake.getLength() > 3) { // snake의 몸이 3이하면 사망
              //Need to Adjustment
                  board.increase(6);
              //===================
                  snake.body.pop_back();
              } else {
                  endGame();
              }
          }
          else if(it->getItemType() == 2){
            timeTick /= 1.5;
          }
          else if(it->getItemType() == 3){
            timeTick *= 1.5;
          }
          
          it = items.erase(it);
          return;
      } else {
          ++it;
      }
  }
  return;
}

void SnakeGame::checkGateEnter(){
  auto head = snake.body.front();
  vector<vector<int>> current_map = map.getMap(stage);

  if(head.first == gate.getGate1Pos().first && head.second == gate.getGate1Pos().second){
  //===================
    board.increase(7);
  //===================
    snake.dir = snake.gateDicisionDir(map.getHeight(), map.getWidth(), snake.dir, gate.getGate2Pos(), current_map);
    snake.gateEntry(gate.getGate2Pos(), snake.dir);
    gate.pauseTime();
    head_lc = snake.body.front();
  } else if(head.first == gate.getGate2Pos().first && head.second == gate.getGate2Pos().second){
    board.increase(7);
    snake.dir = snake.gateDicisionDir(map.getHeight(), map.getWidth(), snake.dir, gate.getGate1Pos(), current_map);
    snake.gateEntry(gate.getGate1Pos(), snake.dir);
    gate.pauseTime();
    head_lc = snake.body.front();
  }
  if(head_lc.first == snake.body.back().first && head_lc.second == snake.body.back().second) gate.resumeTime();
}

void SnakeGame::endGame() {
  gameOver = true;
  mvprintw(9, 33, "================");
  mvprintw(10, 33, "*   Game Over  *");
  mvprintw(11, 33, "================");
  mvprintw(13, 33, "    Press Key...");
  refresh();
  nodelay(stdscr, FALSE);
  getch();
}
