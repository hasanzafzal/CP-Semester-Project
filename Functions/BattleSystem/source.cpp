#include <iostream>
#include <string>
using namespace std;

void quest1() {
    string level_1_qst_inp;

    cout << "LEVEL 1: Explore the Forest" << endl;
    cout << "PROMPT: ....Travelling across the forest..... " << endl;
    cout << "PROMPT: You have reached Grovetopia Falls " << endl;
    cout << "Wait! What's that dark corner right there?...." << endl;
    cout << "A Cave?? I wonder." << endl;
    cout << "PROMPT: TO ENTER THE CAVE, YOU MUST SOLVE THE RIDDLE (3 Attempts)" << endl;

    while (true) {
        for (int attempts = 3; attempts > 0; --attempts) {
            cout << "What is brown and sticky? (" << attempts << " attempts remaining)" << endl;
            getline(cin, level_1_qst_inp);

            if (level_1_qst_inp == "Stick" || level_1_qst_inp == "stick" || level_1_qst_inp == "A stick" || level_1_qst_inp == "A Stick" || level_1_qst_inp == "A STICK" || level_1_qst_inp == "STICK") {
                cout << "Riddle Solved!" << endl;
                return;
            } else {
                cout << "Oops! Incorrect Answer. Try Again. (" << attempts - 1 << " attempts remaining)" << endl;
            }
        }

        cout << "Out of attempts. Riddle not solved. Restarting the quest..." << endl;
    }












}




int main() {
    quest1();
    return 0;
}






