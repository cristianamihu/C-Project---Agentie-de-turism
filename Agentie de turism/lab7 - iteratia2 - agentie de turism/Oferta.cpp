#include "Oferta.h"


//getteri
string Oferta::getDenumire() const {
	return denumire;
}

string Oferta::getDestinatie() const {
	return destinatie;
}

string Oferta::getTip() const {
	return tip;
}

//setteri
void Oferta::setDenumire(string denumireNoua) {
	this->denumire = denumireNoua;
}

void Oferta::setDestinatie(string destinatiNoua) {
	this->destinatie = destinatiNoua;
}

void Oferta::setTip(string tipNou) {
	this->tip = tipNou;
}

void Oferta::setPret(double pretNou) {
	this->pret = pretNou;
}


//comparari
bool comparaDenumire(const Oferta& oferta1, const Oferta& oferta2) {
	return oferta1.getDenumire() < oferta2.getDenumire();
}

bool comparaDestinatie(const Oferta& oferta1, const Oferta& oferta2) {
	return oferta1.getDestinatie() < oferta2.getDestinatie();
}

bool comparaTip(const Oferta& oferta1, const Oferta& oferta2) {
	return oferta1.getTip() < oferta2.getTip();
}

bool comparaPret(const Oferta& oferta1, const Oferta& oferta2) {
	return oferta1.getPret() < oferta2.getPret();
}

bool comparaTipPret(const Oferta& oferta1, const Oferta& oferta2) {
	if (oferta1.getTip() == oferta2.getTip())
		return oferta1.getPret() < oferta2.getPret();
	else
		return oferta1.getTip() < oferta2.getTip();
}
