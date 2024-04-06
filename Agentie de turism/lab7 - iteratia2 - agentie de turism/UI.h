#pragma once
#include "Service.h"


class UI {
private:
	Service& service;

public:
	UI(Service& service) noexcept :service{ service } {}
	//nu permitem copierea obiectelor
	UI(const UI& ot) = delete;
	void afisareMeniu();	//afiseaza meniul aplicatiei

	/*
		Citeste datele de la tastatura si adauga o oferta
	@throw: RepoException daca mai exista o oferta cu denumirea si destinatia data
	*/
	void ui_adauga_oferta();

	/*
		Tipareste o lista de oferte in consola
	@throw: RepoException daca nu exista nicio oferta in agentia de turism
	*/
	void ui_afisare_oferte(const vector<Oferta>& toateOfertele);

	/*
		Modifica o oferta dorita
	@throw: RepoException daca nu exista oferta dorita in agentia de turism
	*/
	void ui_modifica_oferta();

	/*
		Sterge o oferta dorita
	@throw: RepoException daca nu exista oferta dorita in agentia de turism
	*/
	void ui_sterge_oferta();

	/*
		Filtreaza lista cu oferte in functie de un criteriu dorit
	@return: ofertele filtrate dupa un criteriu
	*/
	void ui_filtreaza(); 

	/*
		Sorteaza lista cu oferte in functie de un criteriu dorit
	@return: ofertele sortate dupa un criteriu
	*/
	void ui_sorteaza(); 

	void run();
};
