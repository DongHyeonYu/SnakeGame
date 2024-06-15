#include <vector>
using namespace std;

class Item {
    pair<int, int> pos;
    int curTime;
    int itemType;

public:
    Item(int width, int height);

    void generateNewPosition(int width, int height);

    pair<int, int> getPosition();

    int getItemType();

    void setTime(int t);

    int getTime();
};