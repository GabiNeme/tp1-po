
#include "leituraDadosEntrada.h"
#include <iostream>

void leNumeroDeRestricoesEVariaveis(int & numRestricoes, int & numVariaveis){

    std::cin >> numRestricoes;
    std::cin >> numVariaveis;
}

void preencheTableauxEntrada(DMatrix & tableauxPrincipal, int n, int m){
    //preenche c negativo
    for(int i = 0; i < m; i++){
        std::cin >> tableauxPrincipal.matrix[0][i];
        tableauxPrincipal.matrix[0][i] = -tableauxPrincipal.matrix[0][i];
    }

    //preenche A
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j< m; j++){
            std::cin >> tableauxPrincipal.matrix[i][j];
        }
         std::cin >> tableauxPrincipal.matrix[i][n+m];
    }

    //preenche diagonal
    for(int i = 1; i < n+1; i++){
        tableauxPrincipal.matrix[i][i+m-1] = 1;
    }
}
