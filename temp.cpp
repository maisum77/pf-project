#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void mcqsload(string& filename, vector<string>& mcqs) {
    ifstream file(filename);
    string line, question;
    while (getline(file, line)) {
        if (line.empty()) {
            mcqs.push_back(question);
            question.clear();
        } else {
            question += line + "\n";
        }
    }
    if (!question.empty()) { // Add the last question if there's no trailing newline
        mcqs.push_back(question);
    }
    file.close();
}

void answers(string& filename, vector<string>& ans) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        ans.push_back(line);
    }
    file.close();
}

int main() {
    int choice, TQ;
    again:
    cout << "-------------choice what you want to go with-------------" << endl;
    cout << "1=premade template\n2=custom generation" << endl;
    cin >> choice;
    if (choice == 1) {
        TQ = 30;
    } else if (choice == 2) {
        cout << "::enter number of mcqs you want to generate::" << endl;
        cout << "enter=";
        cin >> TQ;
    } else {
        cout << "invalid choice!!";
        goto again;
    }

    // Load MCQs
    vector<string> mcqs;
    string filename = "mcqs.txt";
    mcqsload(filename, mcqs);
    if (mcqs.empty()) {
        cout << "No MCQs found. Please check the file." << endl;
        return 1;
    }

    // Load answers
    vector<string> ans;
    string answerfile = "answers.txt";
    answers(answerfile, ans);

    // Check if TQ exceeds available questions
    if (TQ > mcqs.size()) {
        cout << "Not enough questions available. Reducing to " << mcqs.size() << " questions." << endl;
        TQ = mcqs.size();
    }

    // Generate unique random indices
    vector<int> indices(mcqs.size());
    for (int i = 0; i < mcqs.size(); ++i) {
        indices[i] = i;
    }
    srand(time(0));
    random_shuffle(indices.begin(), indices.end());

    // For printing MCQs and answers
    vector<string> userans(TQ);
    int correct = 0, wrong = 0;
    for (int j = 0; j < TQ; j++) {
        cout << j + 1 << ") " << mcqs[indices[j]] << endl;
        cout << "your answer=";
        cin >> userans[j];
        if (userans[j] == ans[indices[j]]) {
            cout << " the correct answer " << endl;
            correct++;
        } else {
            cout << "incorrect" << endl;
            wrong++;
        }
    }

    cout << "------------KEY------------" << endl;
    for (int k = 0; k < TQ; k++) {
        cout << ans[indices[k]] << endl;
    }
    cout << "correct answers=" << correct << endl;
    cout << "wrong answers=" << wrong << endl;
    return 0;
}