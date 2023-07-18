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
        cout << "It isn't single character. Please type again: ";
    }
    return character;
}

string AuxiliaryMethods::takeTextLineFromUser() {
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

double AuxiliaryMethods::takeDecimalNumberFromUser() {
    string input = "";
    double number = 0.0;

    while (true) {
        getline(cin, input);
        if(regex_match(input, regex("[0-9]*[.,]?[0-9]*"))) {

            size_t found = input.find(",");
            if (found != string::npos) {
                input.replace(found, 1, ".");
            }

            stringstream myStream(input);
            if (myStream >> number) {
                number = round(number*100)/100;
                break;
            }
        }
        cout << "It isn't decimal number. Please type decimal number (e.g. 123.45): ";
    }
    return number;
}

string AuxiliaryMethods::convertDoubleToString(double doubleNumber) {
    stringstream ss;
    ss.precision(2);
    ss << fixed;

    ss << doubleNumber;
    string stringNumber = ss.str();
    return stringNumber;
}

string AuxiliaryMethods::convertFirstLetterToCapitalAndOtherToSmall(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxiliaryMethods::addCommasAsThousandSeparators(string stringNumber) {
    string stringNumberWithCommas = "";
    int length = stringNumber.size();

    if (length < 7) {
        stringNumberWithCommas = stringNumber;
    } else {
        int decimalMark = length-3;
        int counter = 1;
        for (int i = decimalMark - 1; i>=0; i--) {
            stringNumberWithCommas.push_back(stringNumber[i]);
            counter++;
            if(counter>3 && i != 0) {
                stringNumberWithCommas.push_back(',');
                counter=1;
            }
        }
        reverse(stringNumberWithCommas.begin(), stringNumberWithCommas.end());
        stringNumberWithCommas.append(stringNumber.substr(decimalMark,3));
    }
    return stringNumberWithCommas;
}
