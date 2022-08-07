#ifndef SPREADSHEETS_H
#define SPREADSHEETS_H

#include "employee.h"
#include <map>
#include <iostream>
#include <string>

using namespace std;

class Spreadsheet{

    protected: 
        Employee *root;
        Spreadsheet *tree;
        string fileName;


        map<int, Employee *> data;

    public:
        Spreadsheet();
        Spreadsheet(string fileName, Spreadsheet *tree);

        ~Spreadsheet();
        
        void AddNode(int IDEmployee, string employeeName, int IDSupervisor, double grossSalary, double netSalary);

        void MakeSpreadsheet(string fileName, Spreadsheet *tree);
        int OutputSpreadsheet();

        friend std::ostream& operator << (ostream &o, const Spreadsheet &Spreadsheet);
        friend std::istream& operator >> (istream &i, Spreadsheet &Spreadsheet);
};

#endif