#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "SavedUsersXmlFile.h"

class UserManager {
    int idOfLoggedInUser;
    vector <User> users;
    SavedUsersXmlFile savedUsersXmlFile;

    User enterDataOfNewUser();
    int checkIdForNewUser();
    bool doesUsernameAlreadyExist(string username);
public:
    UserManager(string savedUsersFileName): savedUsersXmlFile(savedUsersFileName) {
    idOfLoggedInUser = 0;
    users = savedUsersXmlFile.getUsersFromFile();
    }

    void registerNewUser();
    void logInUser();
    bool isUserLoggedIn();
    void changePassword();
    void logOutUser();
    int getIdOfLoggedInUser();
};

#endif // USERMANAGER_H
