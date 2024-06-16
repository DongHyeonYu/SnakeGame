# 🐍**SNAKE GAME**
<div align="center">
    Kookmin Univ. C++ SNAKE GAME Project<br><br>
    <img src="assets/snake-game-logo.png">
</div>

## How to RUN?
#### Install libncurses
    $ sudo apt-get update && sudo apt-get install libncurses5-dev libncursesw5-dev

#### g++ -o snake <every .cpp files> -lncursesw<br>
    $ g++ -o snake main.cpp SnakeGame.cpp Snake.cpp Map.cpp Item.cpp Gate.cpp Mission.cpp ScoreBoard.cpp StageManager.cpp Score.cpp -lncursesw

#### or just use make
    $ make


## Unicode Character
    wall = L'◼'; 
    head = L'●';
    body = L'○';

    ◼ : \u25fc
    ● : \u25cf
    ○ : \u25cb

## InGame
<img src="assets/snake-game-rule.png" width=50% height=auto>
<img src="assets/snake-game-ingame1.png" width=50% height=auto>
