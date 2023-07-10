#include "AuxiliaryMethods.h"

char AuxiliaryMethods::takeCharacterFromUser() {
    string input = "";
    char character  = {0};

    while (true) {
        cin.sync();
        getline(cin, input);
        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "It isn't single character. Please type again." << endl;
    }
    return character;
}

string AuxiliaryMethods::takeTextLineFromUser() {
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}
