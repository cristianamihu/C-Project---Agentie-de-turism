#include "Repository.h"
#include "VectorDinamic.h"


void Repo::storeLista(const Oferta& oferta) {
	/*
		Adauga o oferta in lista/Salvare oferta
	@param oferta: oferta care se adauga (Oferta)
	@return -
	post: oferta va fi adaugata in lista
	@throws: RepoException daca o oferta cu aceeasi denumire si aceeasi destinatie exista deja
	*/
	if (exista(oferta)) {
		throw RepoException("Oferta deja existenta!");
	}
	this->toateOfertele.push_back(oferta);	 //adaugam oferta la sfarsit in lista
}

const Oferta& Repo::cauta(string denumire, string destinatie) const {
	/*
		Cauta o oferta cu denumirea si destinatia data
	@param denumire: denumirea dupa care se cauta
	@param destinatie: destinatia dupa care se cauta
	@returns: entitatea Oferta cu denumirea si destinatia data (daca aceasta exista)
	@throws: RepoException daca nu exista oferta cu denumirea si destinatia data
	*/
	for (const Oferta& oferta : this->toateOfertele) {
		if (oferta.getDenumire() == denumire && oferta.getDestinatie() == destinatie) {
			return oferta;
		}
	}
	throw RepoException("Oferta nu exista in lista!");
}

bool Repo::exista(const Oferta& oferta) const {
	/*
		Verifica daca o oferta data exista in lista
	@param oferta: oferta care se cauta in lista
	@return: true - daca oferta exista
			 false - altfel
	*/
	try {
		cauta(oferta.getDenumire(), oferta.getDestinatie());
		return true;
	}
	catch (RepoException&) {
		return false;
	}
}

const VectorDinamic<Oferta>& Repo::getAll() const noexcept{
	/*
	Returneaza o lista cu toate ofertele
	@return: lista cu ofertele (vector of Oferts objects)
	*/
	/*	vector<Oferta> ofertele;
	for (auto oferta : this->toateOfertele) {
		ofertele.push_back(oferta);
	}
	return ofertele;
	*/
	return toateOfertele;
}

void Repo::sterge(string denumire) {
	/*
		Sterge o oferta din lista
	@param oferta: oferta care se sterge (Oferta)
	@return: -
	post: oferta va fi stearsa din lista
	@throws: RepoException daca nu exista oferta cu denumirea si destinatia data
	*/
	int poz = -1;
	int ok = 0;
	for (const Oferta& oferta : toateOfertele) {
		poz++;

		if ( denumire == oferta.getDenumire()) {
			ok = 1;
			toateOfertele.erase(toateOfertele.begin() + poz);
			break;
		}
	}
	if (ok == 0) {
		throw RepoException("Oferta inexistenta!");
	}
}

void Repo::modifica(const Oferta& oferta) {
	/*
		Modifica o oferta cu denumirea data
	@param denumire: denumirea ofertei care urmeaza sa fie modificata
	@param destinatie: destinatia ofertei care urmeaza sa fie modificata
	@return: -
	@throws: RepoException daca nu exista oferta cu denumrea si destinatia data
	*/
	int poz = -1;
	int ok = 0;
	for (const Oferta& o : toateOfertele) {
		poz++;
		if (o.getDenumire() == oferta.getDenumire()) {
			ok = 1;
			toateOfertele[poz] = oferta;
			break;
		}
	}
	if (ok == 0) {
		throw RepoException("Oferta inexistenta!");
	}
}
