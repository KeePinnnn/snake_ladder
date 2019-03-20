#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Ladder {
    map<int, int> ladder_dict;
    vector<int> ladder_vector;
    public: 
        void set_list();
};

void Ladder::set_list() {
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        ladder_vector.push_back(rand() % 100);
    }

    while(true) {
        sort(ladder_vector.begin(), ladder_vector.end());
        ladder_vector.erase(unique(ladder_vector.begin(), ladder_vector.end()), ladder_vector.end());

        if (ladder_vector.size() != 20) {
            for (int n = ladder_vector.size(); n < 20; n++) {
                ladder_vector.push_back(rand() % 100);
            }
        }
        else {
            break;
        }
    }

    for (auto i = ladder_vector.begin(); i != ladder_vector.end(); i++) 
        cout << *i << endl;

    while (ladder_vector.size() > 0) {
        int head_index = rand() % ladder_vector.size();
        int head_value = ladder_vector[head_index];
        ladder_vector.erase(ladder_vector.begin() + head_index);
        
        int value_index = rand() % ladder_vector.size();
        int value_value = ladder_vector[value_index];
        ladder_vector.erase(ladder_vector.begin() + value_index);

        ladder_dict[head_value] = value_value;
    }

    // testing to see if the list works
    // for (auto i = ladder_vector.begin(); i != ladder_vector.end(); i++) 
    //     cout << *i << endl;

    cout << "ladder is being established" << endl;
    // testing to see if dict works 
    for (auto element : ladder_dict) {
        cout << element.first << " after first, here is second " << element.second << "\n";
    }
}

// for testing purpose
// int main() {
//     Ladder lad = Ladder();
//     lad.set_list();
// }