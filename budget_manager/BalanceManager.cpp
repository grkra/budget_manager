#include "BalanceManager.h"

void BalanceManager::addNewIncome() {
    addObligation(INCOME);
}

void BalanceManager::addNewExpense() {
    addObligation(EXPENSE);
}

void BalanceManager::addObligation(const ObligationType obligationType) {
    Obligation newObligation;
    newObligation = takeObligationDetails (obligationType);
    string obligationTypeName = "";

    switch(obligationType) {
    case INCOME:
        obligationTypeName = "income";
        savedIncomesXmlFile.addObligationToFile(newObligation);
        incomes.push_back(newObligation);
        sort(incomes.begin(), incomes.end());
        break;
    case EXPENSE:
        obligationTypeName = "expense";
        savedExpensesXmlFile.addObligationToFile(newObligation);
        expenses.push_back(newObligation);
        sort(expenses.begin(), expenses.end());
        break;
    }

    cout << endl << "Added new " << obligationTypeName << endl << endl;
    Sleep (700);
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
            inputDate = DateMethods::convertTmStructToIntegerDate(DateMethods::getCurrentTime());
            break;
        case '2':
            cout << "Enter date in format yyyy-mm-dd: ";
            inputDate = DateMethods::convertStringDateWithDashesToIntegerDate(DateMethods::takeDateFromUser());
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
        break;
    case EXPENSE:
        newObligation.id = savedExpensesXmlFile.getIdOfLastObligationInFile() + 1;
        break;
    }
    return newObligation;
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

void BalanceManager::showObligationDetails(Obligation obligation) {
    cout << setw(40) << left << obligation.description;
    cout << setw(10) << DateMethods::convertIntegerDateToStringDateWithDashes(obligation.date);
    cout << setw(20) << right << AuxiliaryMethods::addCommasAsThousandSeparators(AuxiliaryMethods::convertDoubleToString(obligation.value)) << endl;
}

void BalanceManager::showHeaderInTableOfObligations (string text) {
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    cout << setw(70) << setfill('-') << "-" << endl << setfill(' ');
    cout << text << endl;
    cout << setw(70) << setfill('-') << "-" << endl << setfill(' ');
}

void BalanceManager::showSummaryOfObligations (double value) {
    cout << endl;
    cout << setw(50) << left << "Summary: ";
    cout << setw(20) << right << AuxiliaryMethods::addCommasAsThousandSeparators(AuxiliaryMethods::convertDoubleToString(value)) << endl;
    cout << endl;
}

double BalanceManager::showListOfObligations(const ObligationType obligationType, int startDate, int endDate) {
    double sumOfObligations = 0;

    vector <Obligation> *obligations;

    switch(obligationType) {
    case INCOME:
        obligations = &incomes;
        break;
    case EXPENSE:
        obligations = &expenses;
        break;
    }

    for (vector <Obligation> :: iterator itr = obligations->begin(); itr != obligations->end(); itr++) {
        if(itr->date >= startDate && itr->date <= endDate) {
            showObligationDetails(*itr);
            sumOfObligations += itr->value;
            if (itr->date > endDate) {
                break;
            }
        }
    }
    return sumOfObligations;
}

void BalanceManager::showIncomesExpensesAndBalance(int startDate, int endDate) {

    double sumOfIncomes = 0;
    double sumOfExpenses = 0;

    system("cls");
    cout << "Balance from " << DateMethods::convertIntegerDateToStringDateWithDashes(startDate);
    cout << " to " << DateMethods::convertIntegerDateToStringDateWithDashes(endDate) << endl;
    cout << setw(40) << left << "Title:" << setw(10) << "Date:" << setw(20) << right << "Value:" << endl;

    showHeaderInTableOfObligations("incomes:");
    sumOfIncomes = showListOfObligations(INCOME, startDate, endDate);
    showSummaryOfObligations(sumOfIncomes);

    showHeaderInTableOfObligations("expenses:");
    sumOfExpenses = showListOfObligations(EXPENSE, startDate, endDate);
    showSummaryOfObligations(sumOfExpenses);

    showHeaderInTableOfObligations("balance:");
    showSummaryOfObligations(sumOfIncomes-sumOfExpenses);

    system("pause");

}

void BalanceManager::showCurrentMonthBalance() {
    tm currentTime = DateMethods::getCurrentTime();
    int firstDayOfCurrentMounth = 0;
    int lastDayOfCurrentMounth = 0;

    currentTime.tm_mday=1;
    firstDayOfCurrentMounth = DateMethods::convertTmStructToIntegerDate(currentTime);

    currentTime.tm_mday=DateMethods::checkNumberOfDaysInMonth(currentTime.tm_year, currentTime.tm_mon);
    lastDayOfCurrentMounth = DateMethods::convertTmStructToIntegerDate(currentTime);

    showIncomesExpensesAndBalance(firstDayOfCurrentMounth, lastDayOfCurrentMounth);
}
void BalanceManager::showLastMonthBalance() {
    tm currentTimeMinusOneMonth = DateMethods::calculateDateMonthAgoFromToday(DateMethods::getCurrentTime());
    int firstDayOfLastMounth = 0;
    int lastDayOfLastMounth = 0;

    currentTimeMinusOneMonth.tm_mday=1;
    firstDayOfLastMounth = DateMethods::convertTmStructToIntegerDate(currentTimeMinusOneMonth);

    currentTimeMinusOneMonth.tm_mday=DateMethods::checkNumberOfDaysInMonth(currentTimeMinusOneMonth.tm_year, currentTimeMinusOneMonth.tm_mon);
    lastDayOfLastMounth = DateMethods::convertTmStructToIntegerDate(currentTimeMinusOneMonth);

    showIncomesExpensesAndBalance(firstDayOfLastMounth, lastDayOfLastMounth);
}
void BalanceManager::showSpecifiedPeriodBalance() {
    int firstDayOfPeriod = 0;
    int lastDayOfPeriod = 0;

    cout << "Enter start of period in format yyyy-mm-dd: ";
    firstDayOfPeriod = DateMethods::convertStringDateWithDashesToIntegerDate(DateMethods::takeDateFromUser());

    do {
    cout << "Enter end of period in format yyyy-mm-dd: ";
    lastDayOfPeriod = DateMethods::convertStringDateWithDashesToIntegerDate(DateMethods::takeDateFromUser());
    if(lastDayOfPeriod<firstDayOfPeriod) {
        cout << "Invalid date. End date can't be earlier than start date." << endl;
    }
    } while(lastDayOfPeriod<firstDayOfPeriod);

    showIncomesExpensesAndBalance(firstDayOfPeriod, lastDayOfPeriod);
}
