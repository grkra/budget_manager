#ifndef SAVEDINCOMESXMLFILE_H
#define SAVEDINCOMESXMLFILE_H

#include <XmlFile.h>
#include "Obligation.h"

using namespace std;

class SavedIncomesXmlFile : public XmlFile {

public:
    SavedIncomesXmlFile(string savedIncomesFileName): XmlFile(savedIncomesFileName) {
    }
};

#endif // SAVEDINCOMESXMLFILE_H
