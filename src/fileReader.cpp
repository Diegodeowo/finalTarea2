#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "fileReader.h"
#include "spreadsheet.h"

using namespace std;
// Constructor
FileReader::FileReader(string fileName){

    this->fileName = fileName;
    this->tree = new Spreadsheet();
}

// Efectua: Obtiene el pago por hora de los empleados profesionales
double FileReader::getHourlySalary(int IDEmployee){
    ifstream ifs(fileName, ifstream::in);

    if (!ifs.is_open()){
        cerr << "ERROR: No input File " << fileName << endl;
        return -1;
    }
    
    string line {};
    int _IDEmployee {0};
    double amountHour {0};
    double workingHours {0};

    while (getline(ifs, line)) {
        
        istringstream stream(line);

        _IDEmployee;
        amountHour;
        workingHours;

        stream >> _IDEmployee >> amountHour >> workingHours;

        if(_IDEmployee == IDEmployee){

            return amountHour * workingHours;
        }
    }

    ifs.close();

    return 0;
}

double FileReader::grossSalary(int IDEmployee){
    ifstream ifs(fileName, ifstream::in);

    if (!ifs.is_open())
    {
        cerr << "ERROR: NO INPUT FILE " << fileName << endl;
        return -1;
    }
    
    string line {}; 

    int _IDEmployee {0};
    double grossPay {0};

    while (getline(ifs, line)) {
        
        istringstream stream(line);

        IDEmployee = 0;
        grossPay = 0;

        stream >> IDEmployee >> grossPay;

        if(IDEmployee == IDEmployee){

            return grossPay;
        }
    }

    ifs.close();
    return 0;
}

// Efectua: Leer el archivo persona
Spreadsheet* FileReader::getTree(){
    fileName = "Personas.txt";
    ifstream ifs(fileName, ifstream::in);

    if (!ifs.is_open())
    {
        cerr << "ERROR: No input file " << fileName << endl;
    }
    
    string line {""}; 

    int IDEmployee {0};
    string employeeName {""};
    string employeeLastName {""};
    string employeeEmail {""};
    int employeeType {0};
    int IDSupervisor {0};

    while (getline(ifs, line)) {
        
        istringstream stream(line);

        IDEmployee = 0;
        employeeName = "";
        employeeLastName = ""; 
        employeeEmail = "";
        employeeType = 0; 
        IDSupervisor=0;

        stream >> IDEmployee >> employeeName >> employeeLastName >> employeeEmail >> employeeType >> IDSupervisor;

        string nombreCompleto = employeeName + " " + employeeLastName;
        double grossSalary {0};
        double netSalary {0};

        // Calculos para los dos distintos tipos de empleados
        if(employeeType == 1){
            FileReader *empleadoNomina = new FileReader("Nomina.txt");
            grossSalary = empleadoNomina->grossSalary(IDEmployee);
            netSalary = grossSalary - (grossSalary * 0.07);
        }
        else{
            FileReader *empleadoHoras = new FileReader("HorasTrabajadas.txt");
            grossSalary = empleadoHoras->getHourlySalary(IDEmployee);
            netSalary = grossSalary;
        }
        
        this->tree->AddNode(IDEmployee, nombreCompleto, IDSupervisor, grossSalary, netSalary);
    }

    ifs.close();

    return tree;
}