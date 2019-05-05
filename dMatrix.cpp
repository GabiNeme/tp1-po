#include "dMatrix.h"

DMatrix::DMatrix(){
    matrix = nullptr;
    lin = 0;
    col = 0;
}


DMatrix::DMatrix(int lin, int col){
    matrix = new double *[lin];
    for(int i = 0; i <lin; i++){
        matrix[i] = new double[col];
    }

    this->lin = lin;
    this->col = col;    

}

DMatrix::~DMatrix(){
    for (int i = 0; i < lin; ++i){
        delete [] matrix[i];
    }
    delete [] matrix;   
}


void DMatrix::pivoteia(int linPiv, int colPiv){
    //divide linha para obter 1
    this->multLinha(linPiv, 1/matrix[linPiv][colPiv]);

    //percorre outras linhas pivoteando
    double f;
    for(int i=0; i < lin; i++){
        if( i != linPiv){
            f = - matrix[i][colPiv];
            //pivoteia cada coluna
            for(int j = 0; j<col; j++){
                matrix[i][j] = matrix[i][j] + f*matrix[linPiv][j];
            }
        }
    }

}

void DMatrix::multLinha(int lin, double fatorMult){
    
    for(int j = 0; j<col; j++){
        matrix[lin][j] = matrix[lin][j] * fatorMult;
    }
}


void DMatrix::print(){
    for(int i = 0; i<lin; i++){
        for(int j = 0; j<col; j++){
            std::cout << round(matrix[i][j]*1000000)/1000000 << "\t";
        }
        std::cout << std::endl;
    }
}