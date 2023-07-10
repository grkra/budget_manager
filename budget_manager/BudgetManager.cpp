#include "BudgetManager.h"

void BudgetManager::registerNewUser() {
    userManager.registerNewUser();
}

void BudgetManager::logInUser() {
    userManager.showAllUsers();
    userManager.logInUser();
    if(userManager.isUserLoggedIn()) {
    }
}

bool BudgetManager::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}

char BudgetManager::showMainMenuAndChooseOption(){
    char optionSelection;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register new user" << endl;
    cout << "2. Log in" << endl;
    cout << "0. Close program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    optionSelection = AuxiliaryMethods::takeCharacterFromUser();

    return optionSelection;
}

void BudgetManager::changePassword() {
    userManager.changePassword();
}

char BudgetManager::showUserMenuAndChoseOption() {
    char optionSelection;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show balance for current mounth" << endl;
    cout << "4. Show balance for last mounth" << endl;
    cout << "5. Show balance for different period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "0. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    optionSelection = AuxiliaryMethods::takeCharacterFromUser();

    return optionSelection;
}
