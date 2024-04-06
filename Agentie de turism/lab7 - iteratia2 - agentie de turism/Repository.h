#pragma once
#include <vector>
#include "Oferta.h"

using std::vector;


//clasa de exceptii specifice Repo, folosit pentru a semnala situatii exceptionale care pot aparea in repo
class RepoException {
private:
	string mesaj;

public:
	RepoException(string mesaj) : mesaj{ mesaj } {}
	string getMesaj() {
		return this->mesaj;
	}
};


class Repo {
private:
	VectorDinamic<Oferta> toateOfertele;

public:
	Repo() = default; //constructor fara parametru
	//constructorul de copiere
	//nu permitem copierea de obiecte
	//punem delete fiindca nu vrem sa se faca nicio copie la Repository (in aplicatie avem un singur Repo)
	Repo(const Repo& ot) = delete;

	/*
		Adauga o oferta in lista/Salvare oferta
	@param oferta: oferta care se adauga (Oferta)
	@return -
	post: oferta va fi adaugata in lista
	@throws: RepoException daca o oferta cu aceeasi denumire si aceeasi destinatie exista deja
	*/
	void storeLista(const Oferta& oferta);

	/*
		Cauta o oferta cu denumirea si destinatia data
	@param denumire: denumirea dupa care se cauta
	@param destinatie: destinatia dupa care se cauta
	@returns: entitatea Oferta cu denumirea si destinatia data (daca aceasta exista)
	@throws: RepoException daca nu exista oferta cu denumirea si destinatia data
	*/
	const Oferta& cauta(string denumire, string destinatie) const;

	/*
		Verifica daca o oferta data exista in lista
	@param oferta: oferta care se cauta in lista
	@return: true - daca oferta exista
			 false - altfel
	*/
	bool exista(const Oferta& oferta) const;

	/*
		Returneaza o lista cu toate ofertele
	@return: lista cu ofertele (vector of Oferts objects)
	*/
	const vector<Oferta>& getAll() const noexcept;

	/*
		Sterge o oferta cu denumirea si destinatia data
	@param denumire: denumirea ofertei care urmeaza sa fie stearsa
	@param destinatie: destinatia ofertei care urmeaza sa fie stearsa
	@return: -
	@throws: RepoException daca nu exista oferta cu denumirea si destinatia data
	*/
	void sterge(string denumire);

	/*
		Modifica o oferta cu denumirea si destinatia data
	@param denumire: denumirea ofertei care urmeaza sa fie modificata
	@param destinatie: destinatia ofertei care urmeaza sa fie modificata
	@return: -
	@throws: RepoException daca nu exista oferta cu denumrea si destinatia data
	*/
	void modifica(const Oferta& oferta);
};
