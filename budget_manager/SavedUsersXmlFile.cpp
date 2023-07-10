#include "SavedUsersXmlFile.h"

void SavedUsersXmlFile::addUserToFile(User user) {
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(getFileName());

    if(!fileExists) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("USERS");
    }

    xmlFile.FindElem("USERS");
    xmlFile.IntoElem();
    xmlFile.AddElem("USER");
    xmlFile.IntoElem();
    xmlFile.AddElem("id", user.userId);
    xmlFile.AddElem("username", user.username);
    xmlFile.AddElem("password", user.password);
    xmlFile.AddElem("firstName", user.firstName);
    xmlFile.AddElem("lastName", user.lastName);

    xmlFile.Save("users.xml");
}

vector <User> SavedUsersXmlFile::getUsersFromFile() {
    CMarkup xmlFile;
    User temporaryUser;
    vector <User> users;
    bool fileExist = xmlFile.Load(getFileName());

    if(fileExist) {
        xmlFile.FindElem("USERS");
        xmlFile.IntoElem();
        while(xmlFile.FindElem("USER")) {
            xmlFile.IntoElem();
            temporaryUser = getUserData(xmlFile);
            users.push_back(temporaryUser);
            xmlFile.OutOfElem();
        }
    }
    return users;
}

User SavedUsersXmlFile::getUserData(CMarkup xmlFile) {
    User temporaryUser;

    xmlFile.FindElem("id");
    temporaryUser.userId = atoi(MCD_2PCSZ(xmlFile.GetData()));

    xmlFile.FindElem("username");
    temporaryUser.username = xmlFile.GetData();

    xmlFile.FindElem("password");
    temporaryUser.password = xmlFile.GetData();

    xmlFile.FindElem("firstName");
    temporaryUser.firstName = xmlFile.GetData();

    xmlFile.FindElem("lastName");
    temporaryUser.lastName = xmlFile.GetData();

    return temporaryUser;
}
