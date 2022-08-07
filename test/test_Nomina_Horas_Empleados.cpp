#include <gtest/gtest.h>

#include "../src/employee.h"
#include "../src/fileReader.h"
#include "../src/spreadsheet.h"

using namespace std;

namespace 
{    
    TEST(TEST_NOMINAHORAS, TEST_NOMINA) {

        FileReader *e1N = new FileReader("Nomina.txt");
        double current = e1N->grossSalary(20);
        double expected = 4600.9799999999996;

        EXPECT_DOUBLE_EQ(expected, current);
    }
        
    TEST(TEST_NOMINAHORAS, TEST_HORAS) {

        FileReader *e2H = new FileReader("HorasTrabajadas.txt");
        double current = e2H->getHourlySalary(469);
        double expected = 3359.58;

        EXPECT_DOUBLE_EQ(expected, current);
    }

    TEST(TEST_EMPLOYEE, TEST_GET_EMPLOYEE_NAME) {

        string name = "Diego Soto";
        string name2 = "Armando Soto";

        Employee *e1Name = new Employee(111, name, 1, name2, 1, 1);
        string current = e1Name->getEmployeeName(e1Name);
        string expected = "Diego Soto";

        EXPECT_EQ(expected, current);
    }

    TEST(TEST_EMPLOYEE, TEST_GET_SUPERVISOR_NAME){

    string name = "Diego Soto";
    string name2 = "Armando Soto";

    Employee *e1Name = new Employee(111, name, 1, name2, 1, 1);
    string current = e1Name->getSupervisorName(e1Name);
    string expected = "Armando Soto";

    EXPECT_EQ(expected, current);

    }
}  