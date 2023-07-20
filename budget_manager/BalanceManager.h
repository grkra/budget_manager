#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>

#include "Obligation.h"
#include "SavedObligationsXmlFile.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"
#include "Type.h"

using namespace std;

class BalanceManager {
    const int ID_OF_LOGGED_IN_USER;
    vector <Obligation> incomes;
    vector <Obligation> expenses;
    SavedObligationsXmlFile savedIncomesXmlFile;
    SavedObligationsXmlFile savedExpensesXmlFile;

    Obligation takeObligationDetails(const Type obligationType);
    void addObligation(const Type obligationType);
    void showAddObligationMenu(const Type obligationType);
    void showObligationDetails(Obligation obligation);
    void showIncomesExpensesAndBalance(int startDate, int endDate);
    double showListOfObligations(const Type obligationType, int startDate, int endDate);
    void showHeaderInTableOfObligations (string text);
    void showSummaryOfObligations (double value);
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
    void showCurrentMonthBalance();
    void showLastMonthBalance();
    void showSpecifiedPeriodBalance();
};

#endif // BALANCEMANAGER_H
