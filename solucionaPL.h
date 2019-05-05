#include "dMatrix.h"
#include "analisesTableaux.h"

void solucionaPLMetodoPrimal(DMatrix & tableauxPrincipal, bool ehPrincipal, int n, int m);

int encontraLinhaAPivotear(DMatrix & tableaux, int colunaAPivotear);

void imprimeIlimitada(DMatrix &tableaux, int colIlimitada);

void imprimeOtima(DMatrix &tableaux, int n, int m);

void imprimeInviavel(DMatrix &tableaux, int n, int m);