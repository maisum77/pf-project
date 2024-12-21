#include <iostream>   // For input/output operations
#include <fstream>    // To read from a file
#include <vector>     // To use the vector data structure
#include <string>     // To use string for text
#include <algorithm>  // For random shuffling
#include <cstdlib>    // For random number functions
#include <ctime>      // To seed random numbers using current time
using namespace std ;


void mcqsload ( string& filename , vector<string>& mcqs )
{
    ifstream file (filename) ;
    string line , question ;
    while (getline (file,line))
    {
        if (line.empty())
        {
             
             
                mcqs.push_back(question); 
                question.clear();
        }
            else 
            {
                question += line + "\n" ;
            }
        
        
    }
    
    file.close();
    
    
}
void answers (string& filename , vector<string>& ans)
{
    ifstream file (filename);
    string line ;
    while (getline(file,line))
    {
        ans.push_back(line);
        line.clear();
        cout<<"\n";

    }
    file.close();
}
int main ()
{
    srand(time(0));
    //for mcqs
    vector<string> mcqs ;
    string filename = "mcqs.txt" ;
    mcqsload(filename,mcqs);
    if (mcqs.empty()) {
        cout << "No MCQs found. Please check the file." << endl;
        return 1;
    }
    //for answers 
    vector<string> ans ;
    string answerfile ="answers.txt";
    answers (answerfile,ans);
    // for random numbers
    vector<int> rnum;
    int count = 1 ;
	for (int i = 0; i<=30 ; i++) {
	int num ;
	num = rand() % 101;
	if (num!=0)
	{
		rnum.push_back(num);
	}
	else {};
	};
    // for printing mcqs and answers 
    string userans [30] ;
    int correct=0 ,wrong=0 ;
    for (int j=0; j<=10 ; j++)
    {
        cout << count <<") " << mcqs[rnum[j]] << endl;
        cout<< "your answer=";
        cin >>userans[j];
        if (userans[j] == ans[rnum[j]])
        {
            cout<< ans[rnum[j]] <<" is the correct answer "<< endl;
            correct++;
        }
        else {

        cout << "correct answer is =" <<ans[rnum[j]] << endl ;
        wrong++;
        }
        count++ ;
    }
    cout << "correct answeers="<< correct <<endl ;
    cout << "wrong answers="<< wrong << endl;
    return 0;
	

}