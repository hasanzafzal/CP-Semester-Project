#include <iostream>
using namespace std;

int embquest() {
    int questopt;
    while (true) {
        cout << "\nChoose which quest you want to begin with" << endl;
        cout << "Enter 1 for Quest 1: A journey through GROVETOPIA (Easy)" << endl;
        cout << "Enter 2 for Quest 2: Exploring the Heartlands (Moderate)" << endl;
        cout << "Enter 3 for Quest 3: Through the Hove Desert (Hard)" << endl;
        cin >> questopt;

        if (questopt == 1 || questopt == 2 || questopt == 3) {
            if (questopt == 1) {
                cout << "Smart decision!" << endl;
                cout << "You've chosen Quest 1";
            }
            else if (questopt == 2) {
                cout << "You've chosen Quest 2";
            }
            else if (questopt == 3) {
                cout << "You've chosen Quest 3" << endl;
                cout << "Best of Luck :D";
            }
            break; 
        }
        else {
            cout << "Invalid input, Please select a valid choice!" << endl;
            cin.clear(); 
            cin.ignore(); 
        }
    }
    return questopt;
}

int main() {
    embquest();
    return 0;
}