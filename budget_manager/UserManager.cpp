#include "UserManager.h"

void UserManager::registerNewUser() {
    User user = enterDataOfNewUser();

    users.push_back(user);
    savedUsersXmlFile.addUserToFile(user);

    cout << endl << "Added new user" << endl << endl;
    system("pause");
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
    user.firstName = AuxiliaryMethods::takeTextLineFromUser();

    cout << "Enter last name: ";
    user.lastName = AuxiliaryMethods::takeTextLineFromUser();

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
    cout << "Enter username: ";
    typedUsername = AuxiliaryMethods::takeTextLineFromUser();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr->username == typedUsername) {
            for (int tries = 3; tries > 0; tries--) {
                cout << "Enter username. Tries left: " << tries << ": ";
                typedPassword = AuxiliaryMethods::takeTextLineFromUser();

                if (itr->username == typedPassword) {
                    cout << endl << "Password correct, logged in." << endl << endl;
                    system("pause");
                    idOfLoggedInUser = itr->userId;
                    return;
                }
            }
            cout << "Entered wrong password 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "No user with entered username" << endl << endl;
    system("pause");
    return;
}

bool UserManager::isUserLoggedIn() {
    return idOfLoggedInUser > 0? true : false;
}












//DO USUNIEICA
void UserManager::showAllUsers() {
    for (size_t i = 0; i < users.size(); i++) {
        cout << "ID: " << users[i].userId << ", ";
        cout << "USERNAME: " << users[i].username << ", ";
        cout << "PASSWORD: " <<  users[i].password << ", ";
        cout << "FIRST NAME: " <<  users[i].firstName << ", ";
        cout << "LAST NAME: " <<  users[i].lastName << endl;
    }
    system("pause");
}
