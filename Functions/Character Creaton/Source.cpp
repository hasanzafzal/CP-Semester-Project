#include <iostream>
#include <string>
using namespace std;

struct Character {
    string name;
    string classType;  
    int health;
    int experience;
};

Character createCharacter() {
    Character character;

    cout << "Enter your player name: ";
    cin >> character.name;

    char classInput;
    do {
        cout << "Choose a class\nEnter W for Belisarius(Warrior class)\nEnter M for Molazhot( Mage Class)\nEnter R for Noyan(Rogue class)\n: ";
        cin >> classInput;
    } while (classInput != 'W' && classInput != 'M' && classInput != 'R');

    switch (classInput) {
    case 'W':
        character.classType = "Belisarius";
        character.health = 100;
        break;
    case 'M':
        character.classType = "Molazhot";
        character.health = 80;
        break;
    case 'R':
        character.classType = "Noyan";
        character.health = 70;
        break;
    }

    character.experience = 0; 

    return character;
}

int main() {
    Character player = createCharacter();

    cout << "Welcome, " << player.name << " the " << player.classType << "!" << endl;

    return 0;
}
