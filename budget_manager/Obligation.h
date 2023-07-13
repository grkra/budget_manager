#ifndef OBLIGATION_H
#define OBLIGATION_H

using namespace std;

struct Obligation {
    int userId = 0;
    int id = 0;
    int date = 0;
    string description = "";
    double value = 0.0;
};

#endif // OBLIGATION_H
