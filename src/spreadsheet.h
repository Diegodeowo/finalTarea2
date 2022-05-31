#ifndef SPREADSHEETS_H
#define SPREADSHEETS_H

#include "employee.h"
#include <map>
#include <iostream>

class Spreadsheet{

    protected: 
        Employee *root;
        map<int, Employee *> data;

    public:
        Spreadsheet();
        ~Spreadsheet();
        void AddNode(int IDEmployee, string employeeName, int IDSupervisor, double grossSalary, double netSalary);

        friend std::ostream& operator << (ostream &o, const Spreadsheet &Spreadsheet);
        friend std::istream& operator >> (istream &i, Spreadsheet &Spreadsheet);
};

#endif