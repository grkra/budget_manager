#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class XmlFile {
    const string FILE_NAME;

protected:
    int lastId;

    string getFileName();

public:
    XmlFile(string fileName): FILE_NAME(fileName) {
        lastId = 0;
    };

    int getLastId();
};

#endif // XMLFILE_H
