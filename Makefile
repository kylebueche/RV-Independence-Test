CFLAGS = -g -pedantic-errors -Wall -std=c++23
SRC = src
OBJ = obj

all: main.exe

DEBUG:
	CFLAGS += -g

main.exe : $(OBJ)/main.o $(OBJ)/coefficient-matrix.o
	g++ -o main.exe $(OBJ)/main.o $(OBJ)/coefficient-matrix.o

$(OBJ)/main.o : $(SRC)/main.cpp $(SRC)/coefficient-matrix.cpp
	g++ $(CFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/coefficient-matrix.o : $(SRC)/coefficient-matrix.cpp $(SRC)/coefficient-matrix.h
	g++ $(CFLAGS) -c $(SRC)/coefficient-matrix.cpp -o $(OBJ)/coefficient-matrix.o
