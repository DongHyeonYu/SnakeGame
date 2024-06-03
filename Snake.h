#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

class Snake{
public:
    Snake(int width=30, int height=30);

    void move();
    void grow();
    int getLength();
    void gateEntry(const pair<int, int> pos, const Direction dir);

    Direction gateDicisionDir(int width, int height, Direction dir, const pair<int, int> pos, const vector<vector<int>>& map);

    deque<pair<int,int>> body; // 2차원 배열 기준 (y, x)
    Direction dir;
};
