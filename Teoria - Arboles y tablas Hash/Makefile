INC = include
SRC = src
OBJ = obj
BIN = bin

all: $(BIN)/ejercicio1 $(BIN)/ejercicio2 $(BIN)/ejercicio3 $(BIN)/ejercicio4 $(BIN)/ejercicio5

$(BIN)/ejercicio1: $(OBJ)/ejercicio1.o
	${CXX} -o $(BIN)/ejercicio1 $(OBJ)/ejercicio1.o

$(OBJ)/ejercicio1.o: $(SRC)/ejercicio1.cpp $(INC)/bintree.h
	${CXX} -c $(SRC)/ejercicio1.cpp -o $(OBJ)/ejercicio1.o -I$(INC)

$(BIN)/ejercicio2: $(OBJ)/ejercicio2.o
	${CXX} -o $(BIN)/ejercicio2 $(OBJ)/ejercicio2.o

$(OBJ)/ejercicio2.o: $(SRC)/ejercicio2.cpp $(INC)/bintree.h
	${CXX} -c $(SRC)/ejercicio2.cpp -o $(OBJ)/ejercicio2.o -I$(INC)

$(BIN)/ejercicio3: $(OBJ)/ejercicio3.o
	${CXX} -o $(BIN)/ejercicio3 $(OBJ)/ejercicio3.o

$(OBJ)/ejercicio3.o: $(SRC)/ejercicio3.cpp $(INC)/bintree.h
	${CXX} -c $(SRC)/ejercicio3.cpp -o $(OBJ)/ejercicio3.o -I$(INC)

$(BIN)/ejercicio4: $(OBJ)/ejercicio4.o
	${CXX} -o $(BIN)/ejercicio4 $(OBJ)/ejercicio4.o

$(OBJ)/ejercicio4.o: $(SRC)/ejercicio4.cpp $(INC)/bintree.h
	${CXX} -c $(SRC)/ejercicio4.cpp -o $(OBJ)/ejercicio4.o -I$(INC)

$(BIN)/ejercicio5: $(OBJ)/ejercicio5.o
	${CXX} -o $(BIN)/ejercicio5 $(OBJ)/ejercicio5.o

$(OBJ)/ejercicio5.o: $(SRC)/ejercicio5.cpp $(INC)/bintree.h
	${CXX} -c $(SRC)/ejercicio5.cpp -o $(OBJ)/ejercicio5.o -I$(INC)

clean:
	rm $(OBJ)/*.o $(BIN)/*
