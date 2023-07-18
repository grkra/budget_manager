#include "UserManager.h"

void UserManager::registerNewUser() {
    User user = enterDataOfNewUser();

    users.push_back(user);
    savedUsersXmlFile.addUserToFile(user);

    cout << endl << "Added new user" << endl << endl;
    Sleep (700);
}

User UserManager::enterDataOfNewUser() {
    User user;

    user.userId = checkIdForNewUser();
    string username;

    system ("cls");
    cout << "REGISTRATION" << endl;

    do {
        cout << "Enter username:";
        username = AuxiliaryMethods::takeTextLineFromUser();
        user.username = username;
    } while (doesUsernameAlreadyExist(username) == true);

    cout << "Enter password: ";
    user.password = AuxiliaryMethods::takeTextLineFromUser();

    cout << "Enter first name: ";
    user.firstName = AuxiliaryMethods::convertFirstLetterToCapitalAndOtherToSmall(AuxiliaryMethods::takeTextLineFromUser());

    cout << "Enter last name: ";
    user.lastName = AuxiliaryMethods::convertFirstLetterToCapitalAndOtherToSmall(AuxiliaryMethods::takeTextLineFromUser());

    return user;
}

int UserManager::checkIdForNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().userId + 1;
}

bool UserManager::doesUsernameAlreadyExist(string username) {
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].username == username) {
            cout << "User with this username already exist, please choose another username" << endl;
            return true;
        }
    }
    return false;
}

void UserManager::logInUser() {
    User user;
    string typedUsername = "";
    string typedPassword = "";

    system ("cls");
    cout << "LOGGING IN" << endl;

    if(users.size() == 0) {
        cout << "No users registered." << endl;
        Sleep (700);
        return;
    }

    cout << "Enter username: ";
    typedUsername = AuxiliaryMethods::takeTextLineFromUser();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr->username == typedUsername) {
            for (int tries = 3; tries > 0; tries--) {
                cout << "Enter username. Tries left: " << tries << ": ";
                typedPassword = AuxiliaryMethods::takeTextLineFromUser();

                if (itr->password == typedPassword) {
                    cout << endl << "Password correct, logged in." << endl << endl;
                    Sleep (700);
                    idOfLoggedInUser = itr->userId;
                    return;
                }
            }
            cout << "Entered wrong password 3 times." << endl;
            Sleep (700);
            return;
        }
        itr++;
    }
    cout << "No user with entered username" << endl << endl;
    Sleep (700);
    return;
}

bool UserManager::isUserLoggedIn() {
    return idOfLoggedInUser > 0? true : false;
}

void UserManager::changePassword() {
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::takeTextLineFromUser();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr->userId == idOfLoggedInUser) {
            itr->password = newPassword;
            savedUsersXmlFile.updateUserInFile(*itr);
            cout << "Password changed." << endl ;
            Sleep (700);
        }
    }
}

void UserManager::logOutUser() {
    idOfLoggedInUser = 0;
}

int UserManager::getIdOfLoggedInUser() {
    return idOfLoggedInUser;
}
