#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    const char* temp [2] = {"1.txt", "2.txt"};

    ifstream file;
    file.open(temp[1]);
    cout << file.rdbuf();
    file.close();
    return 0;
}