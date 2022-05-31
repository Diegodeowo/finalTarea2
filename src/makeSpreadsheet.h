#ifndef MAKESPREADSHEET_H
#define MAKESPREADSHEET_H

#include <iostream>
#include "spreadsheet.h"

using namespace std;

class MakeSpreadsheet {

    protected:
        Spreadsheet *tree;
        string fileName;

    public:
        MakeSpreadsheet(string fileName, Spreadsheet *tree);
        int OutputSpreadsheet();
};

#endif