#include "BalanceManager.h"

void BalanceManager::addNewIncome() {
    Obligation newIncome;
    newIncome = takeObligationDetails (INCOME);
    incomes.push_back(newIncome);
    savedIncomesXmlFile.addObligationToFile(newIncome);
}

void BalanceManager::addNewExpense() {
    Obligation newExpense;
    newExpense = takeObligationDetails (EXPENSE);
    expenses.push_back(newExpense);
    savedExpensesXmlFile.addObligationToFile(newExpense);
}

Obligation BalanceManager::takeObligationDetails(const ObligationType obligationType) {
    int inputDate = 0;
    Obligation newObligation;
    newObligation.userId = ID_OF_LOGGED_IN_USER;

    showAddObligationMenu(obligationType);
    do {
        char optionSelection = AuxiliaryMethods::takeCharacterFromUser();
        switch(optionSelection) {
        case '1':
            inputDate = convertTmStructToIntegerDate(AuxiliaryMethods::getCurrentTime());
            break;
        case '2':
            inputDate = convertStringDateWithDashesToIntegerDate(AuxiliaryMethods::takeDateFromUser());
            break;
        default:
            cout << "Wrong input. Try again." << endl;
            Sleep (700);
            break;
        }
    } while(inputDate == 0);
    newObligation.date = inputDate;

    cout << "Enter description: ";
    newObligation.description = AuxiliaryMethods::takeTextLineFromUser();
    cout << "Enter value: ";
    newObligation.value = AuxiliaryMethods::takeDecimalNumberFromUser();

    switch(obligationType) {
    case INCOME:
        newObligation.id = savedIncomesXmlFile.getIdOfLastObligationInFile() + 1;
        incomes.push_back(newObligation);
        break;
    case EXPENSE:
        newObligation.id = savedExpensesXmlFile.getIdOfLastObligationInFile() + 1;
        expenses.push_back(newObligation);
        break;
    }

    return newObligation;
}

int BalanceManager::convertTmStructToIntegerDate(tm timeToConvert) {
    stringstream ss;
    int date;

    ss << timeToConvert.tm_year << (timeToConvert.tm_mon < 10 ? "0" : "") << timeToConvert.tm_mon << (timeToConvert.tm_mday < 10 ? "0" : "") << timeToConvert.tm_mday;
    ss >> date;

    return date;
}

int BalanceManager::convertStringDateWithDashesToIntegerDate(string inputString) {
    stringstream ss;
    int date;

    ss << inputString.substr(0,4) << inputString.substr(5,2) << inputString.substr(8,2);
    ss >> date;

    return date;
}

void BalanceManager::showAddObligationMenu(const ObligationType obligationType) {
    string obligationTypeName = "";

    switch(obligationType) {
    case INCOME:
        obligationTypeName = "INCOME";
        break;
    case EXPENSE:
        obligationTypeName = "EXPENSE";
        break;
    }
    system("cls");
    cout << "NEW " << obligationTypeName << endl;
    cout << "---------------------------" << endl;
    transform(obligationTypeName.begin(), obligationTypeName.end(), obligationTypeName.begin(), ::tolower);
    cout << "1. Add new " << obligationTypeName << " with current date" << endl;
    cout << "2. Add new " << obligationTypeName << " with different date" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
}










//DO USUNIECIA
void BalanceManager::showAllIncomes() {
    for (size_t i = 0; i < incomes.size(); i++) {
        cout << "ID: " << incomes[i].id << ", ";
        cout << "DATE: " << incomes[i].date << ", ";
        cout << "VALUE: " <<  incomes[i].value << endl;
        cout << "DESCRIPTION: " <<  incomes[i].description << endl << endl;
    }
    system("pause");
}

int BalanceManager::checkIdForNewIncome() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().id + 1;
}
