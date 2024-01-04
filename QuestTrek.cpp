#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <thread>
using namespace std;


struct Inventory {
    string inventory[5];
    bool healthPotionUsed;
};


struct Player {
    int health;
};


struct Character {
    string name;
    string classType;
    int experience;
    string cname;
};


bool checkForExit() {
    if (cin.peek() == 'x' || cin.peek() == 'X')
    {
        cout << "Exited the game" << endl;
        exit(0);
    }

    return false;
}


// Function to simulate RPG-style output
void rout(const string& text)
{
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50)); // Adjust the delay as needed
    }
}



Character createCharacter() {
    Character character;

    cout << "Enter your player name: ";
    getline(cin, character.name);

    char classInput;
    do {
        cout << "Choose a class\nEnter 'W' for Belisarius(Warrior)\nEnter 'M' for Molazhot(Mage)\nEnter 'R' for Noyan(Rogue)\n: ";
        cin >> classInput;
        classInput = toupper(classInput);
    } while (classInput != 'W' && classInput != 'M' && classInput != 'R');

    switch (classInput) {
    case 'W':
        character.classType = "Warrior";
        character.cname = "Belisarius";
        break;
    case 'M':
        character.classType = "Mage";
        character.cname = "Molazhot";
        break;
    case 'R':
        character.classType = "Rogue";
        character.cname = "Noyan";
        break;
    }

    character.experience = 0;

    return character;
}



Character displayCharacterInfo(Character character) {
    rout("\nCharacter Information:");
    cout << "\nPlayer Name: " << character.name << endl;
    cout << "Character: " << character.cname << endl;
    cout << "Class: " << character.classType << endl;
    cout << "Experience: " << character.experience << endl;
    return character;
}



int embquest() {
    char questopt;
    rout("\n Choose which quest you want to begin with");
    cout << "\nEnter 1 for a journey through GROVETOPIA (Easy)" << endl;
    cout << "Enter 2 to explore the Heartlands (Moderate) " << endl;
    cout << "Enter 3 for going through the Hove Desert (Hard) " << endl;
    cout << "Enter your choice (1-3) or 'X' to exit: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> questopt;
    if (questopt == '1') {
        cout << "Smart decision!" << endl;
        rout("You've chosen Quest 1");
    }
    else if (questopt == '2') {
        rout("You've chosen Quest 2");
    }
    else if (questopt == '3') {
        rout("You've chosen Quest 3");
        cout << "\nBest of Luck :D";
    }
    else if (questopt == 'X' || questopt == 'x') {
        cout << "Exiting the game." << endl;
    }
    else {
        cout << "Invalid input, Please select a valid choice!";
    }
    return questopt;
}



void quest1(Character character) {
    Player player;
    player.health = 100;
    Inventory inventory;
    inventory.healthPotionUsed = false;

    string forestRiddleAnswer;
    bool riddleSolved = false;


    while (true) {
        // Quest 1, Level 1
        cout << endl;
        rout("LEVEL 1: Explore the Forest");
        cout << endl;
        rout("PROMPT: ....Travelling across the forest..... ");
        cout << endl;
        rout("PROMPT: You have reached Grovetopia Falls ");
        cout << endl;
        rout("Wait! What's that dark corner right there?....");
        cout << endl;
        rout("A Cave?? I wonder.");
        cout << endl;
        rout("PROMPT: TO ENTER THE CAVE, YOU MUST SOLVE THE RIDDLE (3 Attempts)");
        cout << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int attempts = 3; attempts > 0; attempts--) {
            cout << "What is brown and sticky? (" << attempts << " attempts remaining)" << endl;
            getline(cin, forestRiddleAnswer);

            if (forestRiddleAnswer == "Stick" || forestRiddleAnswer == "stick" || forestRiddleAnswer == "A stick" || forestRiddleAnswer == "A Stick" || forestRiddleAnswer == "A STICK" || forestRiddleAnswer == "STICK") {
                rout("Riddle Solved!\n");
                riddleSolved = true;
                break;
            }


            else
            {
                cout << "Oops! Incorrect Answer. Try Again or enter X to exit. (" << attempts - 1 << " attempts remaining)" << endl;
                if (checkForExit());
            }

        }

        if (riddleSolved) {
            rout("PROMPT: Added Health Potion to Inventory\n");
            inventory.inventory[1] = "Health Potion";

            cout << "Press Enter to Continue or Press X to exit." << endl;
            checkForExit();
            break;
        }
        else {
            rout("Out of attempts. Riddle not solved. Restarting the quest...");
            checkForExit();

        }
        character.experience += 5;
    }



    cout << endl;
    // Quest 1, Level 2
    cout << "LEVEL 2: Goblin Mania" << endl;
    rout("PROMPT: You have reached inside the cave.... ");
    cout << endl;
    rout("Hmm..., Its darken here. ");
    cout << endl;
    rout("PROMPT: Exploring inside the cave....");
    cout << endl;
    rout("SKREEEEEEEK!");
    cout << endl;
    rout("HUH! WHO's THERE?! ");
    cout << endl;
    rout("GOBLIN: You picked the wrong den kid (AHAAHHAHA) ! ");
    cout << endl;
    rout("PROMPT: THE GOBLINS ARE CONFRONTING YOU FOR TRESPASSING, FEND THEM OFF ! ");
    cout << endl;

    // Battle
    const int nGoblins = 3;
    int Goblin_Health[nGoblins] = { 50, 50, 50 };

    while (true) {
        int defeatedGoblins = 0;

        for (int i = 0; i < nGoblins; i++) {
            cout << "Goblin " << i + 1 << endl;
            cout << " Health: " << max(0, Goblin_Health[i]) << " ";
            cout << endl;
        }

        cout << "Your Health: " << max(0, player.health) << endl;
        cout << "Press '1' to attack, 'p' to use health potion: ";

        // Player Attack
        char battle_choice;
        cin >> battle_choice;

        if (battle_choice == 'p') {
            if (!inventory.healthPotionUsed && inventory.inventory[1] == "Health Potion") {
                player.health += 30;
                inventory.healthPotionUsed = true;
                rout("Used Health Potion. Health +30!");
                cout << endl;
            }
            else if (inventory.healthPotionUsed) {
                rout("Health potion already used in this battle.");
                cout << endl;
                continue; // Go back to the beginning of the loop
            }
            else {
                rout("No health potion available.");
                cout << endl;
                continue; // Go back to the beginning of the loop
            }
        }

        else if (battle_choice == '1') {
            for (int i = 0; i < nGoblins; i++) {
                int player_Attack = rand() % 11 + 1;
                Goblin_Health[i] -= player_Attack;
                cout << "Goblin " << i + 1 << " attacked with " << player_Attack << " damage!" << endl;
            }
        }
        else {
            cout << "Invalid input. Try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Go back to the beginning of the loop
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
            player.health -= max(0, Goblin_Attack);

            cout << "You got attacked by Goblin " << i + 1 << " for " << max(0, Goblin_Attack) << " damage!" << endl;

            if (player.health <= 0) {
                rout("You were defeated by the goblins. Game Over!");
                cout << endl;
                cout << "Press X to exit or press enter to choose another quest" << endl;
                if (checkForExit());
                else
                {
                    embquest();
                }

            }
        }

        // Goblin defeat check
        if (defeatedGoblins == nGoblins) {
            rout("All goblins defeated!");
            cout << endl;
            break;
        }
    }
}


void restartQuest2(Character character);


void quest2(Character character) {
    int playerHealth = 100;
    // Level 1: Hills, Grassland, and a Distant River
    cout << "\n\nQUEST 2: HEARTLANDS" << endl;
    rout("LEVEL 1: HILLS, GRASSLAND AND A DISTANT RIVER\n");
    rout("FIND ANY SIGNS THAT MAY LEAD TO CLUES ABOUT THE ALLEGED SECRETS OF ELDORIA\n");
    rout("You are currently near heartland hills, to cross the river you must solve a riddle:\n");
    rout("\nWhat has a mouth but cant chew?\n");

    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    int attempts = 3;
    string riverRiddleAnswer;
    while (attempts > 0) {
        cout << "Enter your answer (" << attempts << " attempts remaining): ";
        getline(cin, riverRiddleAnswer);

        if (riverRiddleAnswer == "A river" || riverRiddleAnswer == "A River" || riverRiddleAnswer == "RIVER" || riverRiddleAnswer == "A RIVER" || riverRiddleAnswer == "river" || riverRiddleAnswer == "River") {
            cout << endl;
            rout("Riddle Solved! You're on the other side of the river. Let's proceed to the Heartland Hills.\n");
            break;
        }
        else {
            cout << "Incorrect answer. Try again (ENTER) , or press X to quit" << endl;
            attempts--;
            checkForExit();

            if (attempts == 0) {
                if (checkForExit());
                else restartQuest2(character);  // Restart
            }

        }
    }

    // Quest 2 , Level 2: Confrontation with Wolves
    cout << "Level 2: Let's Continue" << endl;
    rout("PROMPT: DID YOU HEAR A WEIRD SOUND? WHAT'S THAT?");
    cout << endl;
    rout("*GRRR! HOWLL! *");
    cout << endl;
    rout("OH NO! THE SOUND SEEMS TO INCREASE, IT'S COMING CLOSER! WHAT DO I DO?");
    cout << endl;
    rout("PROMPT: * YOU'RE CONFRONTED BY A PACK OF WOLVES, FIGHT THEM OFF WITH YOUR WEAPON *");
    cout << endl;

    // Battle with Wolves
    const int nWolves = 3;
    int wolfHealth[nWolves] = { 30, 30, 30 };

    while (true) {
        int defeatedWolves = 0;

        for (int i = 0; i < nWolves; i++) {
            cout << "Wolf " << i + 1 << endl;
            cout << " Health: " << max(0, wolfHealth[i]) << " ";
            cout << endl;
        }

        cout << "Your Health: " << max(0, playerHealth) << endl;
        cout << "Press '1' to attack: ";

        // Player Attack
        char Choice;
        cin >> Choice;

        if (Choice == '1') {
            for (int i = 0; i < nWolves; i++) {
                int playerAttack = rand() % 11 + 1;
                wolfHealth[i] -= playerAttack;
                cout << "Wolf " << i + 1 << " attacked with " << playerAttack << " damage!" << endl;
            }
        }
        else {
            cout << "Invalid input. Try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Go back to the beginning of the loop
        }

        for (int i = 0; i < nWolves; i++) {
            if (wolfHealth[i] <= 0) {
                defeatedWolves++;
                wolfHealth[i] = 0;
            }
        }

        if (defeatedWolves > 0) {
            cout << "Defeated " << defeatedWolves << " wolves!" << endl;
        }

        // Wolves Attack
        for (int i = 0; i < nWolves; i++) {
            int wolfAttack = rand() % 6 + 1;
            playerHealth -= max(0, wolfAttack);

            cout << "You got attacked by Wolf " << i + 1 << " for " << max(0, wolfAttack) << " damage!" << endl;

            if (playerHealth <= 0) {
                rout("You were defeated by the wolves. Game Over! :( ");
                cout << endl;
                return;
            }
        }

        // Wolves defeat check
        if (defeatedWolves == nWolves) {
            rout("All wolves defeated! :D ");
            cout << endl;
            break;
        }
    }

    // Level 3: Heartland Hills Traces
    cout << "LEVEL 3: Let's Continue" << endl;
    rout("The hills seem to have some traces that might help us solve the mystery of Eldoria");
    cout << endl;
    rout("PROMPT: Look there ! Looks like we have found our first trace: [ A ]");
    cout << endl;
    rout("PROMPT: KEEP LOOKING FOR MORE BLUEPRINTS, THERE MUST BE MORE AROUND HERE.");
    cout << endl;
    rout("* Fetching for more traces... *");
    cout << endl;
    rout("* What's this? *");
    cout << endl;

    // Quest 2, Level 3: Arranging Blueprints
    rout("Another trace and not one but two! What a lucky day: [ H, R ]\n");
    rout("We are almost there!");
    cout << endl;
    rout("How about we arrange the existing blueprints in correct order: _AHR_A");
    cout << endl;
    rout("Guess the remaining letters, what can the word be?");
    cout << endl;
    rout("PROMPT: YOU HAVE 3 CHANCES TO GUESS THE WORD CLEARLY");
    cout << endl;

    string CorrectWord;
    for (int guessAttempts = 3; guessAttempts > 0; --guessAttempts) {
        cout << "Enter your guess (" << guessAttempts << " attempts remaining): ";

        cin >> CorrectWord;

        if (CorrectWord == "BAHRIA") {
            rout("YOU GUESSED IT CORRECT! \n Well Done!");
            cout << endl;
            break;
        }
        else {
            cout << "Incorrect guess. Try again" << endl;
        }
    }

    if (CorrectWord != "BAHRIA") {
        restartQuest2(character);

    }

    // Final Trace
    rout("\n\nSearching for the final trace now...");
    cout << endl;
    rout("It must be easy since we guessed the remaining blueprints like the Legend of Eldoria mentioned");
    cout << endl;
    rout("Look over there: [ B I ]");
    cout << endl;
    rout("JUST AS EXPECTED");
    cout << endl;

    // Dialogue
    cout << character.cname;
    rout(" arranges all the discovered blueprints together; it magically forms a hidden map beyond the apparent realm of Eldoria.");
    cout << endl;
    rout("Could this be a way towards the resolution of uncovering the reality of Eldoria?");
    cout << endl;
}



void restartQuest2(Character character) {
    rout("Out of attempts.! :(  Restarting Quest...");
    cout << endl;
    quest2(character);
}



void quest3() {
    int playerHealth = 100;

    // LEVEL 1
    cout << "\nQUEST 3: HOVE DESERT\n";
    rout(" LEVEL 1:\n");
    rout("* Ah, very hot weather, looks like this will be challenging *\n");
    rout("PROMPT: We need to find some water first to avoid dehydration \n");
    rout("* AHH! What was that? *\n");
    rout("PROMPT: A snake has bitten your leg \n");
    rout("* I need to find a cure*\n");
    rout("* There's a desert herb nearby, let's see if I can find something there*\n");
    rout("PROMPT: Time to solve a problem to successfully extract the cure and apply it \n");
    rout("PROMPT: Unjumble the following word: ");
    rout("[AEDOLIR]\n");
    rout("* What can it be? *\n");

    string cureAnswer;
    cin.ignore(); // Clear the newline character left in the buffer
    for (int attempts = 3; attempts > 0; --attempts) {
        cout << "Enter your answer :" << attempts << " attempts remaining";
        getline(cin, cureAnswer);

        if (cureAnswer == "ELDORIA") {
            cout << "You did that correctly! Cure successfully applied, health replenishment ++\n";
            break;
        }
        else {
            rout("Incorrect answer. Try again.\n");
            playerHealth -= 40;
            cout << "Your health is " << playerHealth << "\n";
        }
    }

    if (playerHealth <= 0) {
        rout("Incorrect 3x! THE SNAKE VENOM GOT YOU! GAME OVER!\n");
        return;
    }

    // LEVEL 2
    cout << " LEVEL 2:\n";
    rout("* The dehydration is getting me again *\n");
    rout(" PROMPT: HEALTH --\n");
    rout("* I can't sustain desert heat for long, need to find some water*\n");
    rout("PROMPT: Travelling in search of water \n");
    rout("* I hope I make it *\n");
    rout("* Is that a well right there? Don't give me hope! *\n");
    rout("* Let's reach there before my health gets worse *\n");
    rout("HEALTH --\n");
    rout("* Almost there*\n");
    rout("* Let's fetch some water: *\n");
    rout("PROMPT: Solve a riddle to get some water: \n");
    rout("Feed me and I live. Give me a drink and I die. What am I?\n");
    cout << "ONLY 1 ATTEMPT !" << endl;

    string waterAnswer;
    cout << "Enter your answer: \n";
    cin >> waterAnswer;

    if (waterAnswer == "Fire" || waterAnswer == "FIRE" || waterAnswer == "fire") {
        rout("Correct! HEALTH++\n");
        playerHealth += 50;
    }
    else {
        rout("Incorrect! Game over!\n");
        return;
    }

    // LEVEL 3
    cout << "LEVEL 3: Let's Continue\n";
    rout("* Feeling better now, hydrated at last! *\n");
    rout("* Continuing the journey to discover the truth*\n");
    rout("* What's that creature right there; I hope it's harmless? *\n");
    rout("* Let's see if it leads somewhere? *\n");

    rout("PROMPT: Following the unknown animal, looks like a large bird\n");

    rout("* Creature: [SCREECH !!! GHHHHHHHHH !! KERRRRRRRRRR! ]\n");
    rout("* Is that an eagle? Is that a lion? *\n");

    rout("OH NO! That's a griffin*\n");

    rout("PROMPT: DEFEAT THE BEAST:\n");

    int griffinHealth = 60;

    rout("You encountered a Griffin! Get ready for battle.\n");

    while (true) {
        rout("Griffin Health: " +to_string(max(0, griffinHealth)) + "\n");
        rout("Your Health: " + to_string(max(0, playerHealth)) + "\n");
        rout("Press '1' to attack: ");

        // Player Attack
        char choice;
        cin >> choice;

        if (choice == '1') {
            int playerAttack = rand() % 11 + 1;
            griffinHealth -= playerAttack;
            cout << "You attacked the Griffin with " + to_string(playerAttack) + " damage!\n";

            if (griffinHealth <= 0) {
                rout("You defeated the Griffin! Victory!\n");
                break;
            }

            // Griffin Attack
            int griffinAttack = rand() % 11 + 1;
            playerHealth -= max(0, griffinAttack);

            cout << "The Griffin attacked you with " + to_string(max(0, griffinAttack)) + " damage!\n";

            if (playerHealth <= 0) {
                rout("You were defeated by the Griffin. :( Game Over!");
                cout << endl;
                return;
            }
        }
        else {
            rout("Invalid input. Try again.\n");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Go back to the beginning of the loop
        }
    }

    rout("* Ahh! That was a close one; I wonder what could have happened *\n");
}




int main() {
    rout("Welcome to Quest Trek\n");
    Character player = createCharacter();

    cout << "Welcome, " << player.name << " the " << player.classType << "!" << endl;
    displayCharacterInfo(player);

    char questChoice;

    do {
        // Get the chosen quest from embquest and start the selected quest immediately
        questChoice = embquest();

        switch (questChoice) {
        case '1':
            quest1(player);
            break;
        case '2':
            quest2(player); // Pass the player character to quest2
            break;
        case '3':
            quest3();
            break;
        case 'X':
        case 'x':
            break;
        default:
            rout("Invalid choice. Please enter again.");
            cout << endl;
        }

    } while (questChoice != 'X' && questChoice != 'x');

    return 0;
}