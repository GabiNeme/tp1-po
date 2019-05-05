#!/bin/bash
g++  -g -Wall -std=c++11 -O3  -c -o leituraDadosEntrada.o leituraDadosEntrada.cpp
g++  -g -Wall -std=c++11 -O3  -c -o dMatrix.o dMatrix.cpp
g++  -g -Wall -std=c++11 -O3  -c -o analisesTableaux.o analisesTableaux.cpp
g++  -g -Wall -std=c++11 -O3  -c -o solucionaPL.o solucionaPL.cpp
g++  -g -Wall -std=c++11 -O3  -c -o main.o main.cpp
g++  -g -Wall -std=c++11 -O3  -c -o plAuxiliar.o plAuxiliar.cpp
g++ -g -Wall -std=c++11 -O3 -c leituraDadosEntrada.cpp dMatrix.cpp analisesTableaux.cpp solucionaPL.cpp main.cpp plAuxiliar.cpp
g++ -g -Wall -std=c++11 -O3  leituraDadosEntrada.o  dMatrix.o  analisesTableaux.o  solucionaPL.o  main.o  plAuxiliar.o -o tp1
