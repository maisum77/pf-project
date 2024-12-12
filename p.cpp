#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

int main() {
    srand(time(0));
    vector<int> renum;
    vector<string> filename;

    // Generate non-zero random numbers
    for (int i = 0; i <= 30; i++) {
        int num = rand() % 101;
        if (num != 0) {
            renum.push_back(num);
        }
    }

    
    for (auto a : renum) {
        filename.push_back(to_string(a) + ".txt");
    }

    for (const auto& file : filename) {
        cout << file << endl;
    }

    return 0;
}