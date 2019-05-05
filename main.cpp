#include <iostream>
#include <string>


#include "leituraDadosEntrada.h"
#include "analisesTableaux.h"
#include "solucionaPL.h"
#include "plAuxiliar.h"

int main(){

	int n, m;
	leNumeroDeRestricoesEVariaveis(n, m);

	DMatrix tableauxPrincipal(n+1, n+m+1);
	preencheTableauxEntrada(tableauxPrincipal, n, m);

	bool FPI = bPositivo(tableauxPrincipal);
	
	if(FPI){
		solucionaPLMetodoPrimal(tableauxPrincipal, true, n, m);
		
	}else{
		//PL auxiliar
		DMatrix tableauxAux(n+1, m + 2*n + 1);
		montaPLAuxiliar(tableauxPrincipal, tableauxAux, n, m);
		//tableauxAux.print();
		fazSomaParaIniciarSolucao(tableauxAux);
		//std::cout << std::endl;
		//tableauxAux.print();
		solucionaPLMetodoPrimal(tableauxAux, false, n, m);
		//std::cout << std::endl;
		//tableauxAux.print();
		analisaPLAuxiliarEResolvePrincipal(tableauxPrincipal, tableauxAux, n, m);
		
	}


	//tableauxPrincipal.print();

/**
	std::cout << x[0][0] << std::endl;



    for (std::string line; std::getline(std::cin, line);) {
        std::cout << line << std::endl;
    }
	std::cout << 
	"otima" << std::endl << 
	"14" << std::endl << 
	"1 1 1" << std::endl <<
	"2 4 8" << std::endl;**/
	return 0;
}
