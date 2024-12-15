#include <iostream>
#include<random>
#include<cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>

using namespace std ;
int main ()

{
	
	int num;
	srand(time(0));
	vector <int> rnum;
	vector <string> filename ;
	for (int i = 0; i <=25 ; i++) {
	
	
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
    {
	
	 
      ifstream file;
      
        for (auto b : filename)
        {
            
            file.open(b);
            cout << file.rdbuf();
            file.close();
        }
        cout << endl ;
    };
    
	
	return 0 ;
}