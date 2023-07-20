#ifndef SAVEDOBLIGATIONSXMLFILE_H
#define SAVEDOBLIGATIONSXMLFILE_H

#include <vector>

#include "XmlFile.h"
#include "Obligation.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"

using namespace std;

class SavedObligationsXmlFile : public XmlFile {
    //int idOfLastObligationInFile;

    Obligation getObligationData(CMarkup xmlFile);

public:
    SavedObligationsXmlFile(string savedObligationsFileName): XmlFile(savedObligationsFileName) {
        //idOfLastObligationInFile = 0;
    }

    bool addObligationToFile(Obligation obligation);
    vector <Obligation> getObligationsFromFile(int userId);
    //int getIdOfLastObligationInFile();
};

#endif // SAVEDOBLIGATIONSXMLFILE_H
