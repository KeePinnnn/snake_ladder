#include <iostream>

using namespace std;

class dice {
    int min = 1;
    int max = 6;

    public:
        int roll(int num);
};

int dice::roll(int num) {
    int moves = 0;
    // since rand() does not generate a random number 
    // using srand to change the starting point of the sequence is necessary
    // to obtain different value everytime it is being run  
    srand(time(NULL));
    for (int i = 0; i < num; i++) {
        moves += (min + rand() % max);
    }
    cout << moves << endl;
    return moves;
}

int main() {
    dice d = dice();
    d.roll(2);
}