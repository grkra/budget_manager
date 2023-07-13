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

tm AuxiliaryMethods::getCurrentTime() {
    time_t now = time(NULL);
    tm currentTime = *localtime(&now);
    currentTime.tm_year += 1900;
    currentTime.tm_mon += 1;

    return currentTime;
}

bool AuxiliaryMethods::isDateValid(string date) {
    int year = 0, month = 0, dayOfMonth = 0;
    tm currentTime = getCurrentTime();

    if(date.length() != 10) {
        cout << "Wrong format. Please type date again in format yyyy-mm-dd: ";
        return false;
    }
    if(!regex_match(date, regex("[0-9]{4}[-./\\\\]{1}[0-9]{2}[-./\\\\]{1}[0-9]{2}"))) {
        cout << "Wrong format. Please type again in format yyyy-mm-dd: ";
        return false;
    }
    try {
        year = stoi(date.substr(0,4));
        month = stoi(date.substr(5,2));
        dayOfMonth = stoi(date.substr(8,2));
    } catch(const exception &e) {
        cout << "Exception occurred: " << e.what() << endl;
        return false;
    }
    if(year < 2000) {
        cout << "Invalid year. Earliest possible year is 2000. Please type date again: ";
        return false;
    }
    if(month < 1 || month > 12) {
        cout << "Invalid month. Please type date again: ";
        return false;
    }
    if(dayOfMonth < 1) {
        cout << "Invalid day. Please type date again: ";
        return false;
    }
    if(dayOfMonth > checkNumberOfDaysInMonth(year, month)) {
        cout << "Invalid day. Entered month has " << checkNumberOfDaysInMonth(year, month) << " days. Please type date again: ";
        return false;
    }
    if(year > currentTime.tm_year && month > currentTime.tm_mon && dayOfMonth > currentTime.tm_mday) {
        cout << "Invalid date. Latest possible date is todays date. Please type date again: ";
        return false;
    }


    return true;
}

int AuxiliaryMethods::checkNumberOfDaysInMonth(int year, int month) {
    map <int, int> daysPerMonth = {{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
    if (isLeapYear(year)) {
            daysPerMonth[2] = 29;
        }
    return daysPerMonth[month];
}

bool AuxiliaryMethods::isLeapYear (int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

string AuxiliaryMethods::convertDoubleToString(double number) {
    stringstream ss;
    ss.precision(2);
    ss << fixed;

    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::takeDateFromUser() {
    string enteredDate = "";
    cout << "Enter date in format yyyy-mm-dd: ";
    do {
        enteredDate = takeTextLineFromUser();
    } while (!isDateValid(enteredDate));
    return enteredDate;
}
