#include <ncurses.h>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // usleep 함수 사용을 위해 추가
#include <vector>
#include <algorithm>

#include "Snake.h"

using namespace std;

#define WIDTH 60
#define HEIGHT 30

class SnakeGame {
public:
    SnakeGame();
    void run();

private:
    void init();
    void draw();
    void input();
    void goForward();
    bool checkCollision();
    void endGame();

    bool gameOver;
    Snake snake;
};

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
    timeout(100); // 0.1초마다 입력을 폴링하도록 설정
}

void SnakeGame::run() {
    while (!gameOver) {
        draw();
        input();
        if (checkCollision()) {
            endGame();
        }
        goForward();
        usleep(100000); // Delay to slow down the game (100000 microseconds = 0.1 seconds)
    }
    endwin();
}

void SnakeGame::draw() { // 화면 그리기
    clear();
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (y == 0 || y == HEIGHT - 1 || x == 0 || x == WIDTH - 1) {
                mvaddch(y, x, ACS_CKBOARD); // Draw the walls
            } 
            else {
                bool isSnakePart = false;
                for (int s = 0; s<snake.getLength(); ++s) {
                    if (snake.body[s].first == y && snake.body[s].second == x) {
                        if (s == 0) {
                            mvprintw(y, x, "h"); // Draw the head
                        } else {
                            mvprintw(y, x, "d"); // Draw the body
                        }
                        isSnakePart = true;
                        break;
                    }
                }
                if (!isSnakePart) {
                    mvprintw(y, x, " "); // Empty space
                }
            }
        }
    }
    refresh();
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


bool SnakeGame::checkCollision() {
    pair<int, int> head = snake.body[0];
    int y = head.first;
    int x = head.second;
    if (x <= 0 || x >= WIDTH - 1 || y <= 0 || y >= HEIGHT - 1) {
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

int main() {
    SnakeGame game;
    game.run();
    return 0;
}