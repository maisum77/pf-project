#include <iostream>
#include<random>
#include<cstdlib>
#include <ctime>
#include <vector>

using namespace std ;
int main ()

{
	
	int num;
	srand(time(0));
	vector<int> xaviers;
	for (int i = 0; i <=30 ; i++) {
	
	
	num = rand() % 101;
	if (num!=0)
	{
		xaviers.push_back(num);
	}
	else {};
	};
	
		
	
	for (auto xavier : xaviers) {
		cout << xavier << endl;
	};
	
	return 0 ;
}