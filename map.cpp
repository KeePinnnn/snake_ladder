#include <iostream>
#include <string>
#include <list>

// include snake and ladder when initialising the map
#include "Snakes.cpp"
#include "Ladder.cpp"

using namespace std;

class Map {
    static const int row = 10;
    static const int col = 10;
    int grid[row][col];

    public:
        void initialise();
};

void Map::initialise() {
    Snakes s = Snakes();
    s.set_list();

    Ladder l = Ladder();
    l.set_list();
}

int main() {
    Map m = Map();
    m.initialise();
}