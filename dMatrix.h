#ifndef DOUBLE_MATRIX_H
#define DOUBLE_MATRIX_H

#include <iostream>
#include <cmath>


class DMatrix {
public:

    int lin;
    int col;
    double **matrix;

    DMatrix();
    DMatrix(int lin, int col);
    ~DMatrix();

    void pivoteia(int linPiv, int colPiv);
    void multLinha (int lin, double fatorMult);

    void print();

};

#endif/* DOUBLE_MATRIX_H */