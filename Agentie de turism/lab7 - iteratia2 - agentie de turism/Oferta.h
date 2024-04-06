#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;


class Oferta {
private:
	//atribute/reprezentare
	string denumire;
	string destinatie;
	string tip;
	double pret;

public:
	Oferta() = default;		//constructor default
	//constructorul - numele clasei si parametrii (initializare obiect Oferta) -  se apeleaza cand se creaza o oferta
	Oferta(const string& denumire, const string& destinatie, const string& tip, double pret) :denumire{ denumire }, destinatie{ destinatie }, tip{ tip }, pret{ pret } {}
	//constructor de copiere pentru a vedea cate copieri de obiecte se fac in aplicatie 
	//Oferta(const Oferta& ot) :denumire{ot.denumire}, destinatie{ot.destinatie}, tip{ot.tip}, pret{ot.pret} {
		//cout << "A fost chemat constructorul de copiere!\n";
	//}

	//metodele
	//functii de accesare a atributelor denumire, destinatie, tip si pret
	//getteri
	string getDenumire() const;
	string getDestinatie() const;
	string getTip() const;
	double getPret() const noexcept {
		return pret;
	}

	//setteri
	void setDenumire(string denumireNoua);
	void setDestinatie(string destinatieNoua);
	void setTip(string tipNou);
	void setPret(double pretNou);
};
