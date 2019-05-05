#include "plAuxiliar.h"


void montaPLAuxiliar(DMatrix & tableauxPrincipal, DMatrix & tableauxAuxiliar, int n, int m){
    int colB = m + n;
    //na primeira linha, preenche com uns o final (parte auxiliar)
    for(int j = colB; j < tableauxAuxiliar.col-1; j++){
        tableauxAuxiliar.matrix[0][j] = 1;
    }

    //copia pl atual e conserta sinais
    //para cada linha
    for(int i = 1; i <= n; i++){
        int f = 1;
        if(tableauxPrincipal.matrix[i][colB] < 0){
            f = -1;
        }
        //copia tableaux original alterando sinal
        for(int j = 0; j < colB; j++){
            tableauxAuxiliar.matrix[i][j] = f* tableauxPrincipal.matrix[i][j];
        }
        //escreve B no final
        tableauxAuxiliar.matrix[i][tableauxAuxiliar.col-1] = f* tableauxPrincipal.matrix[i][colB];
        
        //escreve identidade no final
        tableauxAuxiliar.matrix[i][colB+i-1] = 1;
    }
}

void fazSomaParaIniciarSolucao(DMatrix & tableauxAux){
    //para cada coluna
    for(int j = 0; j < tableauxAux.col; j++){
        int somaN = 0;
        for(int i = 1; i < tableauxAux.lin; i++){
            somaN += -tableauxAux.matrix[i][j];
        }
        tableauxAux.matrix[0][j] += somaN;
    }
}


void analisaPLAuxiliarEResolvePrincipal(DMatrix & tableauxPrincipal, DMatrix & tableauxAuxiliar, int n, int m){
    //verifica se é ótima ou inviável
    double resultAux = p7(tableauxAuxiliar.matrix[0][tableauxAuxiliar.col-1]);
    if (resultAux == 0){
        obtemSolucaoPLOriginal(tableauxPrincipal,tableauxAuxiliar,n, m);
    }else if(resultAux < 0){
        imprimeInviavel(tableauxAuxiliar, n, m);
    }
}

void obtemSolucaoPLOriginal(DMatrix & tableauxPrincipal, DMatrix & tableauxAuxiliar, int n, int m){
    //copia valores de volta para PL Original
    int colB = n+m;
    for(int i = 1; i< n+1; i++){
        for(int j = 0; j < colB; j++){
            tableauxPrincipal.matrix[i][j] = tableauxAuxiliar.matrix[i][j];
        }
        tableauxPrincipal.matrix[i][colB] = tableauxAuxiliar.matrix[i][tableauxAuxiliar.col - 1];
    }

    //reestabelece as bases
    for(int j = 0; j < colB; j++){
        int linUm = colEhBase(tableauxPrincipal, j, true);
        if (linUm){
            double f = - tableauxPrincipal.matrix[0][j];
            for(int c = 0; c <= colB; c++){
                tableauxPrincipal.matrix[0][c] = tableauxPrincipal.matrix[0][c] + f * tableauxPrincipal.matrix[linUm][c];
            }
        }
    }
    solucionaPLMetodoPrimal(tableauxPrincipal, true, n, m);
}
