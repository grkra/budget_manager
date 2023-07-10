#ifndef SAVEDUSERSXMLFILE_H
#define SAVEDUSERSXMLFILE_H

#include <vector>

#include "XmlFile.h"
#include "User.h"

class SavedUsersXmlFile : public XmlFile
{
    User getUserData(CMarkup xmlFile);

public:
    SavedUsersXmlFile(string savedUsersFileName): XmlFile(savedUsersFileName){
    };

    void addUserToFile (User user);
    vector <User> getUsersFromFile();
    void updateUserInFile (User user);
};

#endif // SAVEDUSERSXMLFILE_H
