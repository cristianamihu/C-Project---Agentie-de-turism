#pragma once
#include "Service.h"
#include <functional>
#include <algorithm>

using std::sort;


void Service::adauga_oferta(const string& denumire, const string& destinatie, const string& tip, double pret) {
	/*
		Adauga o oferta cu denumirea denumire, destinatia destinatie, tipul tip si pretul pret
	*@param denumire: denumrea ofertei care se adauga (string)
	*@param destinatie: destinatia ofertei care se adauga (string)
	*@param tip: tipul ofertei care se adauga (string)
	*@param pret: pretul ofertei care se adauga (double)
	*@throws:	RepoException daca mai exista o oferta cu denumirea si destinatia data
	*/
	Oferta oferta{ denumire, destinatie, tip, pret };
	valid.valideaza(oferta);
	repo.storeLista(oferta);
}

void Service::sterge_oferta(string denumire) {
	/*
		Sterge o oferta
	*@param denumire: denumrea ofertei care se sterge (string)
	*@param destinatie: destinatia ofertei care se sterge (string)
	*@param tip: tipul ofertei care se sterge (string)
	*@param pret: pretul ofertei care se sterge (double)
	*@throw:	RepoException daca nu exista o oferta cu denumirea si destinatia data
	*/
	repo.sterge(denumire);
}

void Service::modifica_oferta(string denumire, string destinatie_noua, string tip_nou, double pret_nou) {
	/*
		Modifica o oferta
	*@param denumire: denumrea ofertei care se modifica (string)
	*@param destinatie: destinatia ofertei care se modifica (string)
	*@param tip: tipul ofertei care se modifica (string)
	*@param pret: pretul ofertei care se modifica (double)
	*@throw:	RepoException daca nu exista o oferta cu denumirea si destinatia data
	*/
	Oferta oferta_noua{ denumire, destinatie_noua, tip_nou, pret_nou };
	repo.modifica(oferta_noua);
}

VectorDinamic<Oferta> Service::sorteaza(std::function<bool(Oferta oferta1,Oferta oferta2)>Compara) {
	VectorDinamic<Oferta> v = repo.getAll();
	v.sort(Compara);
	//for (size_t i = 0; i < v.size(); i++) {
//	for (size_t j = i + 1; j < v.size(); j++) {
//		if (!maiMicF(v[i], v[j])) {
//			//interschimbam
//			Song aux = v[i];
//			v[i] = v[j];
//			v[j] = aux;
//		}
//	}
//}
	return v;
}

VectorDinamic<Oferta> Service::sorteazaDenumire() {
	//vector<Oferta> sortedCopy{ repo.getAll() };
	//sorteaza(sortedCopy.begin(), sortedCopy.end(), comparaDenumire);
	//return sortedCopy;
	////return sorteaza(ComparaDenumire);

	auto ComparaDenumire = [](Oferta oferta1, Oferta oferta2) {return oferta1.getDenumire() < oferta2.getDenumire(); };
	VectorDinamic<Oferta> v = sorteaza(ComparaDenumire);
	//for (int i = 0; i < v.size(); i++)
		//cout << v[i].get() << "\n";
}

VectorDinamic<Oferta> Service::sorteazaDestinatie() {
	//vector<Oferta> sortedCopy{ repo.getAll() };
	//sorteaza(sortedCopy.begin(), sortedCopy.end(), comparaDestinatie);
	//return sortedCopy;
	////return sorteaza(ComparaDestinatie);
	auto ComparaDestinatie = [](Oferta oferta1, Oferta oferta2) {return oferta1.getDestinatie() < oferta2.getDestinatie(); };
	VectorDinamic<Oferta> v = sorteaza(ComparaDestinatie);
	//for (int i = 0; i < v.size(); i++)
		//cout << v[i].get() << "\n";
}

VectorDinamic<Oferta> Service::sorteazaTipPret() {
	auto ComparaTipPret = [](Oferta oferta1, Oferta oferta2) {if (oferta1.getTip() == oferta2.getTip()) return oferta1.getPret() < ofert2.getPret() else return oferta1.getTip() < oferta2.getTip();}
	VectorDinamic<Oferta> v = sorteaza(ComparaTipPret);
	//for (int i = 0; i < v.size(); i++)
		//cout << v[i].get() << "\n";
}

VectorDinamic<Oferta> Service::filtreaza(function<bool(const Oferta&)>fct) {
	VectorDinamic<Oferta> oferteFiltrate;
	for (const auto& oferta : repo.getAll()) {
		if (fct(oferta)) {
			oferteFiltrate.push_back(oferta);
		}
	}
	return oferteFiltrate;
}

VectorDinamic<Oferta> Service::filtrareDestinatie(string destinatie) {
	//const VectorDinamic<Oferta>& toateOfertele = getAll();
	//VectorDinamic<Oferta> oferteFiltrate;
	//std::copy_if(toateOfertele.begin(), toateOfertele.end(), back_inserter(oferteFiltrate),[destinatie](const Oferta& oferta) {return oferta.getDestinatie() == destinatie;});
	//return oferteFiltrate;
	return filtreaza([destinatie](const Oferta& oferta) {return oferta.getDestinatie() == destinatie;});
}

VectorDinamic<Oferta> Service::filtrarePret(double pret) {
	//const vector<Oferta>& toateOfertele = getAll();
	//vector<Oferta> oferteFiltrate;
	//std::copy_if(toateOfertele.begin(), toateOfertele.end(), back_inserter(oferteFiltrate),[pret](const Oferta& oferta) {return oferta.getPret() == pret;});
	//return oferteFiltrate;
	return filtreaza([pret](const Oferta& oferta) {return oferta.getPret() == pret;});
}
