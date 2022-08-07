#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "spreadsheet.h"
#include "employee.h"

using namespace std;

Spreadsheet::Spreadsheet(string fileName, Spreadsheet *tree){
    this->fileName = fileName;
    this->tree = tree;
}
Spreadsheet::Spreadsheet(){
    this->root = nullptr;
}

Spreadsheet::~Spreadsheet(){
    if (this->root != nullptr){
        delete this->root;
    }

}

void Spreadsheet::AddNode(int IDEmployee, string employeeName, int IDSupervisor, double grossSalary, double netSalary){
    
    string supervisorName = "";

    Employee *node = new Employee(IDEmployee, employeeName, IDSupervisor, supervisorName, grossSalary, netSalary);

    if (IDSupervisor == 0){
        this->root = node;   
    }else{
        Employee *parentNode = this->data.at(IDSupervisor);
        node->AddSupervisorName(node, parentNode);
        parentNode->addChild(node);        
    }

    this->data.insert(pair < int,Employee *> (IDEmployee, node));
}

int Spreadsheet::OutputSpreadsheet(){
    ofstream output(fileName);
    output << *tree;
    output.close();

    return 0;
}

ostream& operator << (ostream &o, const Spreadsheet &tree){

    Employee* root = tree.root;
    o << *(root);

    return o;
}


istream& operator >> (istream &i, Spreadsheet &tree){
    string line {""};

    int IDEmployee {0};
    string employeeName {""};
    int IDSupervisor {0};
    string supervisorName {""};
    double grossSalary = 0;
    double netSalary = 0;

    while(getline(i, line)) {
        
        IDEmployee = 0;
        employeeName = "";
        IDSupervisor = 0;
        supervisorName = "";
        grossSalary = 0;
        netSalary = 0;

        std::istringstream stream(line); 
        stream >> IDEmployee >> employeeName >> IDSupervisor >> supervisorName >> grossSalary >> netSalary;

        tree.AddNode(IDEmployee, employeeName, IDSupervisor, grossSalary, netSalary);
    }

    return i;
}