#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <regex>
#include <math.h>

using namespace std;

class AuxiliaryMethods {
public:
    static char takeCharacterFromUser();
    static string takeTextLineFromUser();
    static double takeDecimalNumberFromUser();
    static string takeDateFromUser();
    static tm getCurrentTime();
    static bool isDateValid(string date);
    static int checkNumberOfDaysInMonth(int year, int month);
    static bool isLeapYear (int year);
    static string convertDoubleToString (double number);
};

#endif // AUXILIARYMETHODS_H
