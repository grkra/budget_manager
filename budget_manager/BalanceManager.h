#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

#include "Obligation.h"
#include "SavedObligationsXmlFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BalanceManager {
    const int ID_OF_LOGGED_IN_USER;
    vector <Obligation> incomes;
    vector <Obligation> expenses;
    SavedObligationsXmlFile savedIncomesXmlFile;
    SavedObligationsXmlFile savedExpensesXmlFile;
    enum ObligationType {INCOME, EXPENSE};

    int convertTmStructToIntegerDate(tm timeToConvert);
    int convertStringDateWithDashesToIntegerDate(string inputString);
    Obligation takeObligationDetails(const ObligationType obligationType);
    void showAddObligationMenu(const ObligationType obligationType);
public:
    BalanceManager(int idOfLoggedInUser,
                   string savedIncomesFileName,
                   string savedExpensesFileName)
        : ID_OF_LOGGED_IN_USER(idOfLoggedInUser), savedIncomesXmlFile(savedIncomesFileName), savedExpensesXmlFile(savedExpensesFileName) {
        incomes = savedIncomesXmlFile.getObligationsFromFile(ID_OF_LOGGED_IN_USER);
        expenses = savedExpensesXmlFile.getObligationsFromFile(ID_OF_LOGGED_IN_USER);
        }

    void addNewIncome();
    void addNewExpense();
    //DO USUNIECIA
    void showAllIncomes();
    int checkIdForNewIncome();
};

#endif // BALANCEMANAGER_H
