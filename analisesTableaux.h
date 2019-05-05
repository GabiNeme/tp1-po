#include "dMatrix.h"
#include <cmath>

//Coloca o número double com 7 casas decimais
double p7(double num);

bool bPositivo(DMatrix & tableaux);

int cnPositivo(DMatrix & tableaux);

int colEhBase(DMatrix & tableaux, int colAnalisar, bool ignorarC);

void imprimeSolucao(DMatrix & tableaux,int n, int m);

void imprimeCertificado(DMatrix &tableaux, int n, int m);