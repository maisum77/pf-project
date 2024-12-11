#include <iostream>
#include<random>
#include<cstdlib>
#include <ctime>
#include <vector>
#include<string>

using namespace std ;
int main ()

{
	
	int num;
	srand(time(0));
	vector<int> rnum;
	vector <string> filename ;
	for (int i = 0; i <=30 ; i++) {
	
	
	num = rand() % 101;
	if (num!=0)
	{
		rnum.push_back(num);
	}
	else {};
	};
	
	string temp;
	
	for (auto a : rnum) {
//		cout << a << ".txt" << endl;
		temp = to_string(a) + ".txt";
			
	    filename.push_back(temp) ;
	};
	
	for (auto b : filename) {
		cout << b << endl;
	}
	
	return 0 ;
}