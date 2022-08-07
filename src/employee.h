#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include <iostream>

using namespace std;

class Employee{
    
    vector<Employee*> children;

    protected:
        int IDEmployee = 0, IDSupervisor = 0;
        string employeeName = "", supervisorName = "";
        double grossSalary = 0, netSalary = 0;
        
    public:
        Employee(int IDEmployee, string& employeeName, int IDSupervisor, string& supervisorName, double grossSalary, double netSalary);
        ~Employee();

        void addChild(Employee *child);

        void AddSupervisorName(Employee *employee, Employee *employeeParent);

        string getEmployeeName(Employee *employee);
        string getSupervisorName(Employee *employee);

        friend ostream& operator << (ostream &o, const Employee &Employee);
};

#endif