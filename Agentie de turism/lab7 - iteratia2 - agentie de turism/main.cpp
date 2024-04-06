//#define _CRTDBG_MAP_ALLOC

//#include <stdlib.h>
//#include <crtdbg.h>
#include <iostream>
#include "Teste.h"
#include "Oferta.h"
#include "UI.h"

using std::cout;


int main() {
	//testAll
	testeDomain();
	cout << "Teste Domain trecute cu succes!\n";
	testeRepo();
	cout << "Teste Repo trecute cu succes!\n";
	testeService();
	cout << "Teste Service trecute cu succes!\n";
	testeValidator();
	cout << "Teste Validator trecute cu succes!\n";

	//startApp
	Repo repo;
	Validator valid;
	Service service{ repo, valid };
	UI ui{ service };

	ui.run();
	//_CrtDumpMemoryLeaks();
	return 0;
}
