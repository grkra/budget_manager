#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>

#include "UserManager.h"
#include "BalanceManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetManager {
    UserManager userManager;
    BalanceManager *balanceManager;
    const string SAVED_INCOMES_FILE_NAME;
    const string SAVED_EXPENSES_FILE_NAME;
public:
    BudgetManager(string savedUsersFileName,
                  string savedIncomesFileName,
                  string savedExpensesFileName)
        : userManager(savedUsersFileName), SAVED_INCOMES_FILE_NAME(savedIncomesFileName), SAVED_EXPENSES_FILE_NAME(savedExpensesFileName) {
        balanceManager = NULL;
    }
    ~BudgetManager() {
        delete balanceManager;
        balanceManager = NULL;
    }

    void registerNewUser();
    void logInUser();
    bool isUserLoggedIn();
    void changePassword();
    void logOutUser();
    void addNewIncome();
    void addNewExpense();
    char showMainMenuAndChooseOption();
    char showUserMenuAndChoseOption();
};

#endif // BUDGETMANAGER_H
