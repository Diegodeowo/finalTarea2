FLAGS = -g -c --std=c++17

all:
	mkdir -p bin

	g++ $(FLAGS) src/employee.cpp -o bin/employee.o
	g++ $(FLAGS) src/fileReader.cpp -o bin/fileReader.o
	g++ $(FLAGS) src/makeSpreadsheet.cpp -o bin/makeSpreadsheet.o	
	g++ $(FLAGS) src/spreadsheet.cpp -o bin/spreadsheet.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o

	g++ -g -o bin/a bin/employee.o bin/fileReader.o bin/makeSpreadsheet.o bin/spreadsheet.o bin/main.o

test1:
	mkdir -p bin
	g++ $(FLAGS) src/employee.cpp -o bin/employee.o
	g++ $(FLAGS) src/fileReader.cpp -o bin/fileReader.o
	g++ $(FLAGS) src/makeSpreadsheet.cpp -o bin/makeSpreadsheet.o	
	g++ $(FLAGS) src/spreadsheet.cpp -o bin/spreadsheet.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o

	g++ $(FLAGS) test/test_Nomina_Horas_Empleados.cpp -o bin/test_Nomina_Horas_Empleados.o
	g++ -g -o bin/tests1 bin/test_Nomina_Horas_Empleados.o  bin/employee.o bin/fileReader.o bin/makeSpreadsheet.o bin/spreadsheet.o -lgtest -lgtest_main -lpthread


clean:
	rm -Rf bin