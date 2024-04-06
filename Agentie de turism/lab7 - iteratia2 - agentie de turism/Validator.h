#pragma once
#include "Oferta.h"
#include <string>
using std::string;


class ValidError {
private:
	string mesaj;
public:
	ValidError(string mesaj) : mesaj{ mesaj } {}
	string getMesaj() {
		return mesaj;
	}
};

/*
Clasa pentru validarea ofertelor
O oferta este valida daca:
	-are denumirea formata din cel putin un carcter
	-are destinatia formata din cel putin un carcter
	-are tipul format din cel putin un carcter
	-are pretul format din cel putin o cifra mai mare ca 0
*/
class Validator {
public:
	void valideaza(const Oferta& oferta);
};
