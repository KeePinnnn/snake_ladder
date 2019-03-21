#include <iostream>

using namespace std;

class Player {
    int currentPos; 
    public:
        void move(int currentPos, int steps);
}

void Player::move(int currentPos, int steps) {
    currentPos = currentPos + steps;
}