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
                system("pause");
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
                cout << "SHOW CURRENT MOUNTH BALANCE" << endl;
                system("pause");
                break;
            case '4':
                cout << "SHOW LAST MOUNTH BALANCE" << endl;
                system("pause");
                break;
            case '5':
                cout << "SHOW BALANCE FOR SPECIFIED PERIOD" << endl;
                system("pause");
                break;
            case '6':
                budgetManager.changePassword();
                break;
            case '0':
                budgetManager.logOutUser();
                break;
            default:
                cout << "Wrong input - there is no such option" << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
