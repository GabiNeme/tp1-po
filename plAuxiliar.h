#include "dMatrix.h"
#include "analisesTableaux.h"
#include "solucionaPL.h"

void montaPLAuxiliar(DMatrix & tableauxPrincipal, DMatrix & tableauxAuxiliar, int n, int m);

void fazSomaParaIniciarSolucao(DMatrix & tableauxAux);

void analisaPLAuxiliarEResolvePrincipal(DMatrix & tableauxPrincipal, DMatrix & tableauxAuxiliar, int n, int m);

void obtemSolucaoPLOriginal(DMatrix & tableauxPrincipal, DMatrix & tableauxAuxiliar, int n, int m);