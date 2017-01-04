SRC = src
INC = include
OBJ = obj
BIN = bin
LIB =

$(BIN)/principal: $(OBJ)/principal.o $(OBJ)/mutacion.o $(OBJ)/enfermedad.o $(OBJ)/clinvar.o
	g++ -o $(BIN)/principal $(OBJ)/principal.o $(OBJ)/mutacion.o $(OBJ)/enfermedad.o $(OBJ)/clinvar.o -I$(INC)

$(OBJ)/principal.o: $(SRC)/principal.cpp $(INC)/clinvar.h $(INC)/mutacion.h $(INC)/enfermedad.h
	g++ -c $(SRC)/principal.cpp -std=c++11 -o $(OBJ)/principal.o -I$(INC)

$(OBJ)/clinvar.o: $(SRC)/clinvar.cpp $(INC)/clinvar.h $(INC)/mutacion.h $(INC)/enfermedad.h
	g++ -c $(SRC)/clinvar.cpp -std=c++11 -o $(OBJ)/clinvar.o -I$(INC)

$(OBJ)/mutacion.o: $(SRC)/mutacion.cpp $(INC)/mutacion.h
	g++ -c $(SRC)/mutacion.cpp -o $(OBJ)/mutacion.o -I$(INC)

$(OBJ)/enfermedad.o: $(SRC)/enfermedad.cpp $(INC)/enfermedad.h
	g++ -c $(SRC)/enfermedad.cpp -o $(OBJ)/enfermedad.o -I$(INC)

clear:
	rm bin/* obj/*
