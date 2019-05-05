#include "analisesTableaux.h"

double p7(double num){
    return round(num*10000000)/10000000;
}


bool bPositivo(DMatrix & tableaux){
    int lin = tableaux.lin;
    int col = tableaux.col;
    
    for(int i=1; i < lin; i++){
        if(p7(tableaux.matrix[i][col-1]) < 0){
            return false;
        }
    }
    return true;
}

//verifica se o c negativo, no tableaux, está todo positivo (ou seja, verifica se o c original está todo negativo)
int cnPositivo(DMatrix & tableaux){
    int col = tableaux.col;
    
    for(int i=0; i < col-1; i++){
        if(p7(tableaux.matrix[0][i]) < 0){            
            return i;   //retorna posição do primeiro negativo
        }
    }
    return -1; //todo positivo
}

void imprimeSolucao(DMatrix & tableaux,int n, int m){
    int col = tableaux.col;

    double solucao[m]; //cria vetor solução e zera
    int baseAdicionada[n];
    for(int i = 0; i<n;i++){
        baseAdicionada[i]=0;
    }


    for(int j=0; j< m; j++){
        //primeiro, verifica se a coluna é uma base
        int linUm = colEhBase(tableaux, j, false);

        if (linUm && baseAdicionada[linUm-1] == 0){
            solucao[j] = p7(tableaux.matrix[linUm][col-1]);
            baseAdicionada[linUm-1]=1;
        }else{
            solucao[j] = 0;
        }
    }

    for(int i = 0; i<m; i++){
        std::cout << solucao[i];
        if(i != m-1){
            std::cout << " ";
        }
    }
    std::cout << std::endl;

}


void imprimeCertificado(DMatrix &tableaux, int n, int m){
    //imprime certificado
    for(int i = m; i < m+n; i++){
        std::cout << p7(tableaux.matrix[0][i]);
        if(i != m+n-1){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

//retorna a linha onde está o "1" se for viável, e se não for base, retorna 0
int colEhBase(DMatrix & tableaux, int colAnalisar, bool ignorarC){
    int lin = tableaux.lin;
    if(!ignorarC && p7(tableaux.matrix[0][colAnalisar]) != 0){ //se a primemira linha não é 0, então não é base
        return 0;
    }
    int linUm = 0;
    for(int i = 1; i<lin;i++){
        int vArred = p7(tableaux.matrix[i][colAnalisar]); //valor arredondado com 7 casas decimais
        if(vArred == 1){
            if(linUm){ //garante que só tem um número 1 na base
                return 0;
            }else{
                linUm = i;
            }
        }else if (vArred == 0){
            
        }else{
            return 0;
        }
    } 
    return linUm;

}