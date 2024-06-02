#include <deque>
#include <algorithm>

using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

class Snake{
public:
    Snake(int width=30, int height=30);

    void move();
    void grow();
    int getLength();

    deque<pair<int,int>> body; // 2차원 배열 기준 (y, x)
    Direction dir;
};
