#include <iostream>
#include "employee.h"

using namespace std;

Employee::Employee(int IDEmployee, string& employeeName, int IDSupervisor, string& supervisorName, double grossSalary, double netSalary){

    this->IDEmployee = IDEmployee;
    this->employeeName = employeeName;
    this->IDSupervisor = IDSupervisor;
    this->supervisorName = supervisorName;
    this->grossSalary = grossSalary;
    this->netSalary = netSalary;

}


Employee::~Employee(){

    for (Employee* child : this->children)
    {
        delete child;
    }

}

void Employee::addChild(Employee *child){

    this->children.push_back(child);

}

string Employee::getEmployeeName(Employee *node){

    return Employee::employeeName;

}

string Employee::getSupervisorName(Employee *node){

    return Employee::supervisorName;

}

void Employee::AddSupervisorName(Employee *node, Employee *parentNode){

    string supervisorName = parentNode->employeeName;
    node->supervisorName = supervisorName;

}

// Prints the spreadsheets information
ostream& operator << (std::ostream &o, const Employee &node){

    o << node.IDEmployee << ","
      << node.employeeName << ","
      << node.supervisorName << ","
      << node.netSalary << endl
    ;

    for (Employee *childNode : node.children)
    {
        o << *childNode;
    }

    return o;
}