# 🐍**SNAKE GAME**
<div align="center">
    Kookmin Univ. C++ SNAKE GAME Project<br><br>
    <img src="assets/snake-game-logo.png">
</div>

## How to RUN?
#### Install SnakeGame File
    $ git clone https://github.com/DongHyeonYu/SnakeGame.git
    $ cd SnakeGame/src/

#### Install libncurses
    $ sudo apt-get update && sudo apt-get install libncurses5-dev libncursesw5-dev

#### g++ -o snake <every .cpp files> -lncursesw<br>
    $ g++ -o snake Credit.cpp Gate.cpp Item.cpp main.cpp Map.cpp Mission.cpp ScoreBoard.cpp Score.cpp Snake.cpp SnakeGame.cpp StageManager.cpp -lncursesw

#### or just use make
    $ make

#### Run
    $ ./snake

## Used Unicode Character
    wall =        L'🧱';
    head =        L'😈';
    body =        L'🟣';
    space =       ' ';
    Growth Item = L'🍎';
    Poison Item = L'💀';
    Fast Item =   L'⏩';
    Slow Item =   L'⏪';
    Gate  =       L'🌀';
    Block =       L'■';

## InGame
<img src="assets/snake-game-rule.png" width=50% height=auto>
<img src="assets/snake-game-ingame1.png" width=50% height=auto>


