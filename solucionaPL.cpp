#include "solucionaPL.h"


void solucionaPLMetodoPrimal(DMatrix & tableauxPrincipal, bool ehPrincipal, int n, int m){
    
    //verifica se c é todo positivo no tableaux. Se não for, retorna a coluna do primeiro número negativo
    int colAPivotear = cnPositivo(tableauxPrincipal);
    int linAPivotear = -1;

    while(colAPivotear != -1){
        linAPivotear = encontraLinhaAPivotear(tableauxPrincipal, colAPivotear);
        if(linAPivotear == -1){
            return;
        }

        //pivoteia
        tableauxPrincipal.pivoteia(linAPivotear, colAPivotear);

        //std::cout << "Pivotar " << linAPivotear << ", " << colAPivotear << std::endl;
        //tableauxPrincipal.print();

        colAPivotear = cnPositivo(tableauxPrincipal);
    }

    if (ehPrincipal){
        imprimeOtima(tableauxPrincipal, n, m);
    }
}

int encontraLinhaAPivotear(DMatrix & tableaux, int colunaAPivotear){
    int lin = tableaux.lin;
    int col = tableaux.col;
    double min = -1;
    int linMin = 0;

    for(int i=1; i < lin; i++){
        if(p7(tableaux.matrix[i][colunaAPivotear]) > 0){
            double val = tableaux.matrix[i][col-1]/tableaux.matrix[i][colunaAPivotear];
            if(min == -1 || val < min){
                min = val;
                linMin = i;
            }
        }
    }

    if (min == -1){
        imprimeIlimitada(tableaux, colunaAPivotear);
        return -1;
    }else{ //retorna coluna
        return linMin;
    }
}

void imprimeIlimitada(DMatrix &tableaux, int colIlimitada){
    std::cout << "ilimitada" << std::endl;

    int lin = tableaux.lin;
    int col = tableaux.col;

    //imprime solucao viável
    imprimeSolucao(tableaux, lin -1, col-lin);

    //obtém certificado
    double d[col-lin];
    d[colIlimitada] = 1;
    for(int j = 0; j < col-lin; j++){
        if(j != colIlimitada){ //exclui coluna que permite o certificado
            
            int lin = colEhBase(tableaux, j, false);
            if (!lin){
                d[j] = 0;
            }else{
                d[j] = -p7(tableaux.matrix[lin][colIlimitada]);
            }
        }
    }

    for(int i = 0; i < col-lin; i++){
        std::cout << d[i] << " ";
    }
    std::cout << std::endl;
}

void imprimeOtima(DMatrix &tableaux, int n, int m){
    
    int col = tableaux.col;
    std::cout << "otima" << std::endl;
    std::cout << tableaux.matrix[0][col-1] << std::endl;

    imprimeSolucao(tableaux, n, m);

    imprimeCertificado(tableaux, n, m);

}


void imprimeInviavel(DMatrix &tableaux, int n, int m){

    std::cout << "inviavel" << std::endl;

    imprimeCertificado(tableaux, n, m);
}