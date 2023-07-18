#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <regex>
#include <math.h>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {
public:
    static char takeCharacterFromUser();
    static string takeTextLineFromUser();
    static double takeDecimalNumberFromUser();
    static string convertDoubleToString (double doubleNumber);
    static string convertFirstLetterToCapitalAndOtherToSmall(string text);
    static string addCommasAsThousandSeparators(string stringNumber);
};

#endif // AUXILIARYMETHODS_H
