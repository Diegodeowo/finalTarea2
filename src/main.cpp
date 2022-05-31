/*
 ***********************************************
 * 
 * College: Universidad de Costa Rica
 * 
 * Student: Juan Diego Soto Castro - C07722
 * 
 * E-Mail: juan.sotocastro@ucr.ac.cr
 * 
 * Github: Diegodeowo
 * 
 ***********************************************
*/

#include <iostream>
#include <fstream>

#include "../src/fileReader.h"
#include "../src/spreadsheet.h"
#include "../src/makeSpreadsheet.h"

using namespace std;

int main() {   

    FileReader *file1 = new FileReader("Personas.txt");

    Spreadsheet *tree = new Spreadsheet();
    tree = file1->getTree();

    MakeSpreadsheet output("Reporte.csv", tree);
    output.OutputSpreadsheet();

    return 0;
}