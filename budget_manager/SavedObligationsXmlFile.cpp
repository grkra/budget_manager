#include "SavedObligationsXmlFile.h"

bool SavedObligationsXmlFile::addObligationToFile(Obligation obligation) {
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(getFileName());

    if(!fileExists) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("OBLIGATIONS");
    }

    xmlFile.FindElem("OBLIGATIONS");
    xmlFile.IntoElem();
    xmlFile.AddElem("OBLIGATION");
    xmlFile.IntoElem();
    xmlFile.AddElem("userId", obligation.userId);
    xmlFile.AddElem("id", obligation.id);
    xmlFile.AddElem("date", DateMethods::convertIntegerDateToStringDateWithDashes(obligation.date));
    xmlFile.AddElem("value", AuxiliaryMethods::convertDoubleToString(obligation.value));
    xmlFile.AddElem("description", obligation.description);

    if (xmlFile.Save(getFileName())) {
        lastId ++;
        return true;
    }
    return false;
}

vector <Obligation> SavedObligationsXmlFile::getObligationsFromFile(int userId) {
    CMarkup xmlFile;
    Obligation temporaryObligation;
    vector <Obligation> obligations;

    bool fileExist = xmlFile.Load(getFileName());

    if(fileExist) {
        xmlFile.FindElem("OBLIGATIONS");
        xmlFile.IntoElem();
        while(xmlFile.FindElem("OBLIGATION")) {
            xmlFile.IntoElem();
            temporaryObligation = getObligationData(xmlFile);
            lastId = temporaryObligation.id;
            if(temporaryObligation.userId == userId) {
                obligations.push_back(temporaryObligation);
            }
            xmlFile.OutOfElem();
        }
    }
    sort(obligations.begin(), obligations.end());
    return obligations;
}

Obligation SavedObligationsXmlFile::getObligationData(CMarkup xmlFile) {
    Obligation temporaryObligation;

    xmlFile.FindElem("userId");
    temporaryObligation.userId = atoi(MCD_2PCSZ(xmlFile.GetData()));

    xmlFile.FindElem("id");
    temporaryObligation.id = atoi(MCD_2PCSZ(xmlFile.GetData()));

    xmlFile.FindElem("date");
    temporaryObligation.date = DateMethods::convertStringDateWithDashesToIntegerDate(xmlFile.GetData());

    xmlFile.FindElem("value");
    temporaryObligation.value = stod(MCD_2PCSZ(xmlFile.GetData()));

    xmlFile.FindElem("description");
    temporaryObligation.description = xmlFile.GetData();

    return temporaryObligation;
}
