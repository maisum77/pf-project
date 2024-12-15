#include <iostream>   // For input/output operations
#include <fstream>    // To read from a file
#include <vector>     // To use the vector data structure
#include <string>     // To use string for text
#include <algorithm>  // For random shuffling
#include <cstdlib>    // For random number functions
#include <ctime>      // To seed random numbers using current time
using namespace std ;

void mcqsload (string filename , vector<string> mcqs )
{
    ifstream file (filename) ;
    string line , question ;
    while (getline (file,line))
    {
        if (line.empty())
        {
            if (!question.empty()) 
            { 
                mcqs.push_back(question); 
                question.clear();
            }
            else 
            {
                question += line + "\n" ;
            }
        }
    }
    file.close();
    
}
int main ()
{
    srand(time(0));
    vector<string> mcqs ;
    string filename = "mcqs.txt" ;
    mcqsload(filename,mcqs);

    vector<int> rnum;
	for (int i = 0; i <=30 ; i++) {
	
	int num ;
	num = rand() % 101;
	if (num!=0)
	{
		rnum.push_back(num);
	}
	else {};
	};
    for (int j=0; j<=30 ; j++)
    {
        cout << mcqs[rnum[j]] ;
    }
    return 0;
	

}