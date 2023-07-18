#include "DateMethods.h"

string DateMethods::takeDateFromUser() {
    string enteredDate = "";
    do {
        enteredDate = AuxiliaryMethods::takeTextLineFromUser();
    } while (!isDateValid(enteredDate));
    return enteredDate;
}

tm DateMethods::getCurrentTime() {
    time_t now = time(NULL);
    tm currentTime = *localtime(&now);
    currentTime.tm_year += 1900;
    currentTime.tm_mon += 1;

    return currentTime;
}

bool DateMethods::isDateValid(string date) {
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

int DateMethods::checkNumberOfDaysInMonth(int year, int month) {
    map <int, int> daysPerMonth = {{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
    if (isLeapYear(year)) {
            daysPerMonth[2] = 29;
        }
    return daysPerMonth[month];
}

bool DateMethods::isLeapYear (int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int DateMethods::convertTmStructToIntegerDate(tm timeToConvert) {
    stringstream ss;
    int date;

    ss << timeToConvert.tm_year << (timeToConvert.tm_mon < 10 ? "0" : "") << timeToConvert.tm_mon << (timeToConvert.tm_mday < 10 ? "0" : "") << timeToConvert.tm_mday;
    ss >> date;

    return date;
}

int DateMethods::convertStringDateWithDashesToIntegerDate(string stringDate) {
    stringstream ss;
    int integerDate;

    ss << stringDate.substr(0,4) << stringDate.substr(5,2) << stringDate.substr(8,2);
    ss >> integerDate;

    return integerDate;
}

string DateMethods::convertIntegerDateToStringDateWithDashes(int integerDate) {
    stringstream ss;
    string stringDate;

    ss << integerDate;
    stringDate = ss.str().substr(0,4) + "-" + ss.str().substr(4,2) + "-" + ss.str().substr(6,2);

    return stringDate;
}

tm DateMethods::calculateDateMonthAgoFromToday(tm month) {
    tm previousMonth = month;
    if(month.tm_mon == 1) {
        previousMonth.tm_mon = 12;
        previousMonth.tm_year -= 1;
    } else {
        previousMonth.tm_mon -=1;
    }

    if(previousMonth.tm_mday > checkNumberOfDaysInMonth(previousMonth.tm_year, previousMonth.tm_mon)) {
        previousMonth.tm_mday = checkNumberOfDaysInMonth(previousMonth.tm_year, previousMonth.tm_mon);
    }
    return previousMonth;
}
