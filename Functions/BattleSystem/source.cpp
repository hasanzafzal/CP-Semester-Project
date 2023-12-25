#include <iostream>
#include <string>
using namespace std;

void quest1() {
    string level_1_qst_inp;
// Quest 1 , Level 1
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
        if (level_1_qst_inp != "Stick" && level_1_qst_inp != "stick" && level_1_qst_inp != "A stick" && level_1_qst_inp != "A Stick" && level_1_qst_inp != "A STICK" && level_1_qst_inp != "STICK")
        cout << "Out of attempts. Riddle not solved. Restarting the quest..." << endl;
    }
//Quest 1 Level 2
    cout << "LEVEL 2: Goblin Mania" << endl;
    cout << "PROMPT: You have reached inside the cave.... " << endl;
    cout << "Hmm..., Its darken here. " << endl;
    cout << "PROMPT: Exploring inside the cave...." << endl;
    cout << "SKREEEEEEEK!"<< endl;
    cout << "HUH! WHO's THERE?! "<< endl;
    cout << "GOBLIN: You picked the wrong den kid (AHAAHHAHA) ! "<< endl;
    cout << "PROMPT: THE GOBLINS ARE CONFRONTING YOU FOR TRESPASSING, FEND THEM OFF ! "<<endl;

//Battle   
    const int nGoblins= 3;               
    int Goblin_Health[nGoblins] = {50,50,50}; 
    int player_Health = 100;
   

    while (true) 
    {
       for (int i = 0; i < nGoblins; i++) 
        {
         cout << "Goblin " << i + 1 << endl;
         cout << " Health: " << Goblin_Health[i] << " ";
         cout <<endl;
        }
        
        char<<battle_choice;
        cin >>battle_choice;

        cout<<"Your Health: "<< player_Health << endl;
        cout << "Press '1' to attack: ";
       

//Player Attack
        if (battle_choice == '1')
        {   
        int player_Attack = rand() % 13 + 1;
        Goblin_Health[0] -= player_Attack; 
        cout << "Goblin attacked with" << player_Attack << " damage!" << endl;
        }

        if (Goblin_Health[0] <= 0)
        {
            cout << "Goblin defeated!" << endl;
            break;  
        }

        else 
        {
            cout << "Invalid input. Try again." << endl;
            continue;
        }

// Goblins Attack
        for (int i = 0; i < nGoblins; ++i) {
            int Goblin_Attack = rand() % 6 + 1;  
            player_Health -= Goblin_Attack;

            cout << "You got attacked by"<<"Goblin"<< i + 1 << "for" << Goblin_Attack << " damage!" << endl;

            
            if (player_Health <= 0) 
            {
                cout << "You were defeated by the goblins. Game Over!" << endl;
                return;  
            }

}
    }
       }  

int main() {
    quest1();
    return 0;
}






