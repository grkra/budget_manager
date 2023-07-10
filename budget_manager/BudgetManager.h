#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>

#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetManager {
    UserManager userManager;

public:
    BudgetManager(string savedUsersFileName): userManager(savedUsersFileName) {
    }

    void registerNewUser();
    void logInUser();
    bool isUserLoggedIn();
    void changePassword();
    char showMainMenuAndChooseOption();
    char showUserMenuAndChoseOption();
};

#endif // BUDGETMANAGER_H
