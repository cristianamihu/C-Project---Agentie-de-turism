#pragma once
#include "Oferta.h"
#include "Repository.h"
#include "Validator.h"
#include "VectorDinamic.h"
#include <string>
#include <functional>

using std::function;
using std::string;


class Service {
private:
	Repo& repo;
	Validator& valid;

public:
	//constructorul
	Service(Repo& repo, Validator& valid) noexcept : repo{ repo }, valid{ valid } {}	//nu putem pune const pentru ca o sa vrem sa modificam obiectul repository

	//constructor de copiere
	//punem delete fiindca nu vrem sa se faca nicio copie la Service (in aplicatie avem un singur Service)
	Service(const Service& ot) = delete;
	//Service() = default;

	/*
		Adauga o oferta cu denumirea denumire, destinatia destinatie, tipul tip si pretul pret
	*@param denumire: denumrea ofertei care se adauga (string)
	*@param destinatie: destinatia ofertei care se adauga (string)
	*@param tip: tipul ofertei care se adauga (string)
	*@param pret: pretul ofertei care se adauga (double)
	*@throw:	RepoException daca mai exista o oferta cu denumirea si destinatia data
	*/
	void adauga_oferta(const string& denumire, const string& destinatie, const string& tip, double pret);

	/*
		Returneaza un vector cu toate ofertele
	@return: lista cu toate ofertele (vector cu obiecte de tip Oferta)
	*/
	const VectorDinamic<Oferta>& getAll() {
		return this->repo.getAll();
	}

	/*
		Modifica o oferta
	*@param denumire: denumrea ofertei care se modifica (string)
	*@param destinatie: destinatia ofertei care se modifica (string)
	*@param tip: tipul ofertei care se modifica (string)
	*@param pret: pretul ofertei care se modifica (double)
	*@throw:	RepoException daca nu exista o oferta cu denumirea si destinatia data
	*/
	void modifica_oferta(string denumire, string destinatie, string tip, double pret);

	/*
		Sterge o oferta
	*@param denumire: denumrea ofertei care se sterge (string)
	*@param destinatie: destinatia ofertei care se sterge (string)
	*@param tip: tipul ofertei care se sterge (string)
	*@param pret: pretul ofertei care se sterge (double)
	*@throw:	RepoException daca nu exista o oferta cu denumirea si destinatia data
	*/
	void sterge_oferta(string denumire);

	/*
		Functie de sortare proprie
	@param Compara: functia de comparare folosita pentru sortare
	@return: lista de oferte sortata dupa criteriul dat (vector cu elemente de tip Oferta)
	*/
	VectorDinamic<Oferta> sorteaza(std::function<bool(Oferta a, Oferta b)>Compara);

	/*
		Filtreaza lista de oferte pe baza unui criteriu
	@param fct: functia dupa care se filtreaza lista de oferte
	@return: lista cu ofertele care indeplinesc criteriul dat
	*/
	VectorDinamic<Oferta> filtreaza(function<bool(const Oferta&)>fct);

	/*
		Returneaza o lista de oferte cu destinatia data
	* @param destinatie: destinatia dupa care se filtreaza
	* @return: lista cu ofertele care au destinatia data (vector cu elemente de tip Oferta)
	*/
	VectorDinamic<Oferta> filtrareDestinatie(string destinatie);

	/*
		Returneaza o lista de oferte cu pretul dat
	* @param pret: pretul dupa care se filtreaza
	* @return: lista cu ofertele care au pretul dat (vector cu elemente de tip Oferta)
	*/
	VectorDinamic<Oferta> filtrarePret(string pret);

	/*
		 Sorteaza ofertele dupa denumirea ofertei
	@return: lista cu oferte sortate dupa denumire
	*/
	VectorDinamic<Oferta> sorteazaDenumire();

	/*
		 Sorteaza ofertele dupa destinatia ofertei
	@return: lista cu oferte sortate dupa destinatie
	*/
	VectoDinamic<Oferta> sorteazaDestinatie();

	/*
		 Sorteaza ofertele dupa tipul si pretul ofertei
	@return: lista cu oferte sortate dupa tip si pret
	*/
	VectorDinamic<Oferta> sorteazaTipPret();
};
