#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <sstream>
#include <regex>

#include "AuxiliaryMethods.h"

using namespace std;

class DateMethods {
public:
    static string takeDateFromUser();
    static tm getCurrentTime();
    static bool isDateValid(string date);
    static int checkNumberOfDaysInMonth(int year, int month);
    static bool isLeapYear (int year);
    static int convertTmStructToIntegerDate(tm timeToConvert);
    static int convertStringDateWithDashesToIntegerDate(string stringDate);
    static string convertIntegerDateToStringDateWithDashes(int integerDate);
    static tm calculateDateMonthAgoFromToday(tm month);
};

#endif // DATEMETHODS_H
