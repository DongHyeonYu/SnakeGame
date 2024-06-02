#include <vector>
using namespace std;

class Item {
    pair<int, int> pos;
    int curTime;
    bool isGrowth;

public:
    Item(int width, int height);

    void generateNewPosition(int width, int height);

    pair<int, int> getPosition();

    bool getIsGrowth();

    void setTime(int t);

    int getTime();
};