#include <gtest/gtest.h>

#include "../src/employee.h"
#include "../src/fileReader.h"
#include "../src/makeSpreadsheet.h"
#include "../src/spreadsheet.h"

namespace {
    
    TEST(TEST_NOMINAHORAS, TEST_NOMINA) {

        FileReader *empleadoNomina = new FileReader("Nomina.txt");
        double current = empleadoNomina->grossSalary(20);
        double expected = 4600.9799999999996;

        EXPECT_DOUBLE_EQ(expected, current);
    }
        
    TEST(TEST_NOMINAHORAS, TEST_HORAS) {

        FileReader *empleadoHoras = new FileReader("HorasTrabajadas.txt");
        double current = empleadoHoras->getHourlySalary(469);
        double expected = 3359.58;

        EXPECT_DOUBLE_EQ(expected, current);
    }
}