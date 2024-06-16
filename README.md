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


## Member
| | 학과 | 학번 | 이름 |
|:----:|:-------:|:---:|:---:|
|조장|소프트웨어학부|20203104|유 동현|
|조원|소프트웨어학부|20212972|김 민찬|
|조원|소프트웨어학부|20213074|장 종아|



## Demonstration Youtube Link
#### 시연영상 1 
[![SnakeGame 시연 #1]( https://img.youtube.com/vi/oFQDgPBdkuY/0.jpg)](https://youtu.be/oFQDgPBdkuY)

#### 시연영상 2
[![SnakeGame 시연 #2]( https://img.youtube.com/vi/5UV8QhsDFPY/0.jpg)](https://youtu.be/5UV8QhsDFPY)