#include <iostream>   // For input/output operations
#include <fstream>    // To read from a file
#include <vector>     // To use the vector data structure
#include <string>     // To use string for text
#include <algorithm>  // For random shuffling
#include <cstdlib>    // For random number functions
#include <ctime>      // To seed random numbers using current time
using namespace std;

void mcqsload(const string& filename, vector<string>& mcqs) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
    
    string line, question;
    while (getline(file, line)) {
        if (line.empty()) {
            // Finalize the current question
            if (!question.empty()) {
                mcqs.push_back(question);
                question.clear();
            }
        } else {
            question += line + "\n";  // Append non-empty lines to the question
        }
    }
    // Add the last question if the file doesn't end with an empty line
    if (!question.empty()) {
        mcqs.push_back(question);
    }

    file.close();
}

int main() {
    srand(time(0));
    vector<string> mcqs;
    string filename = "mcqs.txt";
    mcqsload(filename, mcqs);

    if (mcqs.empty()) {
        cout << "No MCQs found. Please check the file." << endl;
        return 1;
    }

    vector<int> rnum;
    int numQuestions = min(30, static_cast<int>(mcqs.size())); // Limit to the number of available MCQs

    // Generate unique random indices
    vector<int> indices(mcqs.size());
    iota(indices.begin(), indices.end(), 0); // Fill indices with 0, 1, 2, ..., mcqs.size() - 1
    random_shuffle(indices.begin(), indices.end());

    // Display the MCQs in random order
    for (int i = 0; i < numQuestions; ++i) {
        cout << mcqs[indices[i]] << endl;
    }

    return 0;
}
