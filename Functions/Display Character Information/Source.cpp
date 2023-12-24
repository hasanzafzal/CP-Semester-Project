#include <iostream>
#include <string>
using namespace std;

struct Character {
    string name;
    string classType;
    int health;
    int experience;
};

Character displayCharacterInfo() {
    Character character;
    cout << "\nCharacter Information:" << endl;
    cout << "Name: " << character.name << endl;
    cout << "Class: " << character.classType << endl;
    cout << "Health: " << character.health << endl;
    cout << "Experience: " << character.experience << endl;
    return character;
}

int main() {
    displayCharacterInfo();
    return 0;
}