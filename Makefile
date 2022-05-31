FLAGS = -g -c --std=c++17

all:
	mkdir -p bin

	g++ $(FLAGS) src/employee.cpp -o bin/employee.o
	g++ $(FLAGS) src/fileReader.cpp -o bin/fileReader.o
	g++ $(FLAGS) src/makeSpreadsheet.cpp -o bin/makeSpreadsheet.o	
	g++ $(FLAGS) src/spreadsheet.cpp -o bin/spreadsheet.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o

	g++ -g -o bin/a bin/employee.o bin/fileReader.o bin/makeSpreadsheet.o bin/spreadsheet.o bin/main.o

# g++ -g -o bin/a bin/archivoHoras.o	bin/archivoNomina.o	bin/archivoPersonas.o bin/employee.o bin/MakeSpreadsheet.o bin/nomina.o bin/spreadsheet.o  bin/main.o

test1:
	mkdir -p bin
	g++ $(FLAGS) src/employee.cpp -o bin/employee.o
	g++ $(FLAGS) src/fileReader.cpp -o bin/fileReader.o
	g++ $(FLAGS) src/makeSpreadsheet.cpp -o bin/makeSpreadsheet.o	
	g++ $(FLAGS) src/spreadsheet.cpp -o bin/spreadsheet.o
	g++ $(FLAGS) src/main.cpp -o bin/main.o

	g++ $(FLAGS) test/testNominaHoras.cpp -o bin/testNominaHoras.o
	g++ -g -o bin/tests1 bin/testNominaHoras.o  bin/employee.o bin/fileReader.o bin/makeSpreadsheet.o bin/spreadsheet.o -lgtest -lgtest_main -lpthread





# test2:
# 	mkdir -p bin
# 	g++ $(FLAGS) src/horasTrabajadas.cpp -o bin/horasTrabajadas.o
# 	g++ $(FLAGS) src/packagePostal.cpp -o bin/packagePostal.o

# 	g++ $(FLAGS) tests/test_shippingPostal.cpp -o bin/test_shippingPostal.o
# 	g++ -g -o bin/tests2 bin/test_shippingPostal.o bin/packagePostal.o bin/package.o -lgtest -lgtest_main -lpthread



# mkdir -p bin
# g++ $(FLAGS) src/employee.cpp -o bin/employee.o
# # g++ $(FLAGS) src/empleadoAsalariado.cpp -o bin/empleadoAsalariado.o
# # g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
# g++ $(FLAGS) src/spreadsheet.cpp -o bin/spreadsheet.o
# g++ $(FLAGS) src/main.cpp -o bin/main.o
# g++ -g -o bin/a bin/employee.o bin/spreadsheet.o bin/main.o
# # bin/empleadoNomina.o  bin/empleadoAsalariado.o

clean:
	rm -Rf bin