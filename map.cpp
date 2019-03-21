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
    
    int value = 0;
    for (int i = 0; i < row; i++) {
        for (int n = 0; n < col; n++) {
            value += 1;
            grid[i][n] = value;
        }
    }
}

int main() {
    Map m = Map();
    m.initialise();
}