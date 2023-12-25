#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void quest1() {
    string level_1_qst_inp;
    bool riddleSolved = false;

    while (true) {
        // Quest 1 , Level 1
        cout << "LEVEL 1: Explore the Forest" << endl;
        cout << "PROMPT: ....Travelling across the forest..... " << endl;
        cout << "PROMPT: You have reached Grovetopia Falls " << endl;
        cout << "Wait! What's that dark corner right there?...." << endl;
        cout << "A Cave?? I wonder." << endl;
        cout << "PROMPT: TO ENTER THE CAVE, YOU MUST SOLVE THE RIDDLE (3 Attempts)" << endl;

        for (int attempts = 3; attempts > 0; --attempts) {
            cout << "What is brown and sticky? (" << attempts << " attempts remaining)" << endl;
            getline(cin, level_1_qst_inp);

            if (level_1_qst_inp == "Stick" || level_1_qst_inp == "stick" || level_1_qst_inp == "A stick" || level_1_qst_inp == "A Stick" || level_1_qst_inp == "A STICK" || level_1_qst_inp == "STICK") {
                cout << "Riddle Solved!" << endl;
                riddleSolved = true;
                break;
            } else {
                cout << "Oops! Incorrect Answer. Try Again. (" << attempts - 1 << " attempts remaining)" << endl;
            }
        }

        if (riddleSolved) {
            cout << "Proceeding to the next level..." << endl;
            break;
        } else {
            cout << "Out of attempts. Riddle not solved. Restarting the quest..." << endl;
        }
    }

    //Quest 1 Level 2
    cout << "LEVEL 2: Goblin Mania" << endl;
    cout << "PROMPT: You have reached inside the cave.... " << endl;
    cout << "Hmm..., Its darken here. " << endl;
    cout << "PROMPT: Exploring inside the cave...." << endl;
    cout << "SKREEEEEEEK!" << endl;
    cout << "HUH! WHO's THERE?! " << endl;
    cout << "GOBLIN: You picked the wrong den kid (AHAAHHAHA) ! " << endl;
    cout << "PROMPT: THE GOBLINS ARE CONFRONTING YOU FOR TRESPASSING, FEND THEM OFF ! " << endl;

    //Battle
    const int nGoblins = 3;
    int Goblin_Health[nGoblins] = {50, 50, 50};
    int player_Health = 100;

    while (true) {
        int defeatedGoblins = 0;

        for (int i = 0; i < nGoblins; i++) {
            cout << "Goblin " << i + 1 << endl;
            cout << " Health: " << max(0, Goblin_Health[i]) << " ";
            cout << endl;
        }

        cout << "Your Health: " << max(0, player_Health) << endl;
        cout << "Press '1' to attack: ";

        // Player Attack
        char battle_choice;
        cin >> battle_choice;

        if (battle_choice == '1') {
            for (int i = 0; i < nGoblins; i++) {
                int player_Attack = rand() % 11 + 1;
                Goblin_Health[i] -= player_Attack;
                cout << "Goblin " << i + 1 << " attacked with " << player_Attack << " damage!" << endl;
            }
        } else {
            cout << "Invalid input. Try again." << endl;
             cin.clear();  
            cin.ignore('\n');  
            continue;
        }

        for (int i = 0; i < nGoblins; i++) {
            if (Goblin_Health[i] <= 0) {
                defeatedGoblins++;
                Goblin_Health[i] = 0;
            }
        }

        if (defeatedGoblins > 0) {
            cout << "Defeated " << defeatedGoblins << " goblins!" << endl;
        }

        // Goblins Attack
        for (int i = 0; i < nGoblins; ++i) {
            int Goblin_Attack = rand() % 6 + 1;
            player_Health -= max(0, Goblin_Attack);

            cout << "You got attacked by Goblin " << i + 1 << " for " << max(0, Goblin_Attack) << " damage!" << endl;

            if (player_Health <= 0) {
                cout << "You were defeated by the goblins. Game Over!" << endl;
                return;
            }
        }

        // Goblin defeat check
        if (defeatedGoblins == nGoblins) {
            cout << "All goblins defeated!" << endl;
            break;
        }
    }
}

int main() {
    quest1();
    return 0;
}
