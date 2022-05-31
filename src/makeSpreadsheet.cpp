#include <iostream>
#include <fstream>
#include "spreadsheet.h"
#include "makeSpreadsheet.h"

MakeSpreadsheet::MakeSpreadsheet(string fileName, Spreadsheet *tree){
    this->fileName = fileName;
    this->tree = tree;
}

int MakeSpreadsheet::OutputSpreadsheet(){
    ofstream output(fileName);
    output << *tree;
    output.close();

    return 0;
}