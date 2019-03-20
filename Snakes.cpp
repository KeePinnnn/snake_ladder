#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Snakes {
    map<int, int> snake_dict;
    vector<int> snake_vector;
    public: 
        void set_list();
};

void Snakes::set_list() {
    for (int i = 0; i < 20; i++) {
        snake_vector.push_back(rand() % 100);
    }

    while(true) {
        sort(snake_vector.begin(), snake_vector.end());
        snake_vector.erase(unique(snake_vector.begin(), snake_vector.end()), snake_vector.end());

        if (snake_vector.size() != 20) {
            for (int n = snake_vector.size(); n < 20; n++) {
                snake_vector.push_back(rand() % 100);
            }
        }
        else {
            break;
        }
    }

    for (auto i = snake_vector.begin(); i != snake_vector.end(); i++) 
        cout << *i << endl;

    while (snake_vector.size() > 0) {
        int head_index = rand() % snake_vector.size();
        int head_value = snake_vector[head_index];
        snake_vector.erase(snake_vector.begin() + head_index);
        
        int value_index = rand() % snake_vector.size();
        int value_value = snake_vector[value_index];
        snake_vector.erase(snake_vector.begin() + value_index);

        snake_dict[head_value] = value_value;
    }

    // testing to see if the list works
    // for (auto i = snake_vector.begin(); i != snake_vector.end(); i++) 
    //     cout << *i << endl;

    // testing to see if dict works 
    for (auto element : snake_dict) {
        cout << element.first << " after first, here is second " << element.second << "\n";
    }
}

// for testing purpose
// int main() {
//     Snakes s = Snakes();
//     s.set_list();
// }