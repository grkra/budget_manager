#include <iostream>
#include "BudgetManager.h"
using namespace std;

int main() {
    BudgetManager budgetManager("users.xml", "incomes.xml", "expenses.xml");

    char optionSelection;
    enum type {income, expense};

    while(true) {
        if(!budgetManager.isUserLoggedIn()) {
            optionSelection = budgetManager.showMainMenuAndChooseOption();
            switch (optionSelection) {
            case '1':
                budgetManager.registerNewUser();
                break;
            case '2':
                budgetManager.logInUser();
                break;
            case '0':
                exit (0);
                break;
            default:
                cout << "Wrong input - there is no such option" << endl;
                Sleep (700);
                break;
            }
        } else {
            optionSelection = budgetManager.showUserMenuAndChoseOption();
            switch (optionSelection) {
            case '1':
                budgetManager.addNewIncome();
                break;
            case '2':
                budgetManager.addNewExpense();
                break;
            case '3':
                budgetManager.showCurrentMonthBalance();
                break;
            case '4':
                budgetManager.showLastMonthBalance();
                break;
            case '5':
                budgetManager.showSpecifiedPeriodBalance();
                break;
            case '6':
                budgetManager.changePassword();
                break;
            case '0':
                budgetManager.logOutUser();
                break;
            default:
                cout << "Wrong input - there is no such option" << endl;
                Sleep (700);
                break;
            }
        }
    }

    return 0;
}
