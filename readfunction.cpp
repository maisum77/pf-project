#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream file;
    file.open("1.txt");
    cout << file.rdbuf();
    file.close();
    return 0;
}