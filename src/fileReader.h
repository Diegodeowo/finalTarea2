#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include "spreadsheet.h"

using namespace std;

class FileReader{

    string fileName = "";
    
    Spreadsheet *tree = new Spreadsheet();

    public:
        FileReader(string fileName);
        
        // Funcion para: Horas.txt
        virtual double getHourlySalary(int IDEmployee);
        // Funcion para: Nomina.txt
        virtual double grossSalary(int IDEmployee);
        // Funcion para: Personas
        virtual Spreadsheet* getTree();
};

#endif
