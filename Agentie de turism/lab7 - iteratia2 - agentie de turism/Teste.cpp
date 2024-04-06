#include <assert.h>
#include "Oferta.h"
#include "Repository.h"
#include "Teste.h"
#include "Service.h"
#include "Validator.h"
#include <iostream>

using std::cout;


void testeDomain() {
	Oferta oferta1{ "abc", "Italia", "aaa", 125.22 };
	assert(oferta1.getDenumire() == "abc");
	assert(oferta1.getDestinatie() == "Italia");
	assert(oferta1.getTip() == "aaa");
	assert(oferta1.getPret() == 125.22);

	Oferta oferta2{ "def", "Turcia", "aaa", 380.44 };
	assert(oferta2.getDenumire() == "def");
	assert(oferta2.getDestinatie() == "Turcia");
	assert(oferta2.getTip() == "aaa");
	assert(oferta2.getPret() == 380.44);

	oferta2.setDenumire("abcdef");
	oferta2.setDestinatie("Grecia");
	oferta2.setTip("bbb");
	oferta2.setPret(500.22);

	assert(oferta2.getDenumire() == "abcdef");
	assert(oferta2.getDestinatie() == "Grecia");
	assert(oferta2.getTip() == "bbb");
	assert(oferta2.getPret() == 500.22);
}

void testeRepo() {
	//adaugare
	Repo testRepo;
	Oferta oferta{ "aaa", "Grecia", "ccc", 500 };
	Oferta oferta_gresita{ "aaa", "Germania", "ccc", 500 };
	testRepo.storeLista(oferta);
	VectorDinamic<Oferta> oferte = testRepo.getAll();
	//assert(oferte.size() == 1);
	assert(testRepo.getAll().size() == 1);
	try {
		testRepo.storeLista(oferta);
	}
	catch (RepoException& exception) {
		assert(true);
		assert(exception.getMesaj() == "Oferta deja existenta!");
	}

	//cautare
	Oferta oferta_de_modificat{ "bbb", "Anfsjk", "fushd", 300 };
	testRepo.storeLista(oferta_de_modificat);

	Oferta oferta1({ "abc", "Bulgaria", "ghi", 355 });
	Oferta oferta2({ "abb", "Danemarca", "goi", 145 });
	Oferta oferta3({ "abd", "Norvegia", "gh", 400 });
	testRepo.storeLista(oferta1);
	testRepo.storeLista(oferta2);

	assert(testRepo.exista(oferta1));
	assert(!testRepo.exista(oferta3));

	auto cautareOferta = testRepo.cauta("abc", "Bulgaria");
	assert(cautareOferta.getDenumire() == "abc");
	assert(cautareOferta.getDestinatie() == "Bulgaria");
	assert(cautareOferta.getTip() == "ghi");
	assert(cautareOferta.getPret() == 355);
	//cautam ceva inexistent
	try {
		testRepo.cauta("bbbb", "Croatia");
		assert(false);
	}
	catch (RepoException& exception) {
		assert(exception.getMesaj() == "Oferta nu exista in lista!");
	}

	//modificare
	Oferta oferta_noua{ "bbb", "Romania", "yui", 600 };

	testRepo.modifica(oferta_noua);
	auto ofertaModificata = testRepo.cauta("bbb", "Romania");
	assert(ofertaModificata.getPret() == 600);
	testRepo.sterge("bbb");
	Oferta oferta_gresita1{ "bbb", "Germania", "ccc", 500 };
	try {
		testRepo.modifica(oferta_gresita1);
		assert(false);
	}
	catch (RepoException& exception) {
		assert(true);
		assert(exception.getMesaj() == "Oferta inexistenta!");
	}

	//stergere
	Oferta oferta_gresita2{ "ion", "Germania", "ccc", 500 };
	try {
		testRepo.sterge(oferta_gresita2.getDenumire());
		assert(false);
	}
	catch (RepoException& exception) {
		assert(true);
		assert(exception.getMesaj() == "Oferta inexistenta!");
	}
	//testRepo.sterge(oferta_noua.getDenumire());
	testRepo.sterge("abc");
	testRepo.sterge("abb");
	//const auto& allOferte = testRepo.getAll();
	assert(testRepo.getAll().size() == 1);

}
void testeService() {
	//adaugare
	Repo testRepo;
	//Oferta oferta{ "aaa", "Grecia", "ccc", 500 };
	Service testService{ testRepo };
	testService.adauga_oferta("aa", "Italia", "bb", 200);
	/*
	const auto& oferte = service.getAll();	  //auto e in loc la vector<Oferta>
	assert(oferte.size() == 1);
	*/
	assert(testService.getAll().size() == 1);		////////////////////////////////////
	try {
		testService.adauga_oferta("aa", "Italia", "bb", 200);
		assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}

	//testService.adauga_oferta("aa", "Italia", "bb", 200);
	//assert(oferte.size() == 1);
	testService.sterge_oferta("aa");
	assert(testService.getAll().size() == 0);
	testService.adauga_oferta("aa", "Italia", "bb", 200);
	testService.modifica_oferta("aa", "Londra", "abcdf", 102);
	VectorDinamic<Oferta> oferte = testService.getAll();

	//auto Compare_Titlu = [](Film a, Film b) {return a.get_titlu() > b.get_titlu(); };
	//VectorDinamic<Film> v = film.sorteaza(Compare_Titlu);
	//assert(v[0].get_titlu() == "asd");
}

void testeValidator() {
	Oferta oferta1{ "Scufita Rosie","Frati Grimm","Basm",1950 };
	Oferta oferta_noua{ "Scufita bRosie","Frati bGrimm","bBasm",1920 };
	Oferta oferta_gresita{ "Scufita Rosie","Frati Grimm","Basm",1950 };
	Oferta oferta_gresita1{ "","Frati Grimm","Basm",1950 };
	Oferta oferta_gresita2{ "a","","Basm",1950 };
	Oferta oferta_gresita3{ "v","Frati Grimm","",1950 };

	Validator testValidator;
	try {
		testValidator.valideaza(oferta_gresita);
	}
	catch (ValidError& error) {
		assert(error.getMesaj() == "Denumire invalida!\n");
	}
	try {
		testValidator.valideaza(oferta_gresita1);
	}
	catch (ValidError& error) {
		assert(error.getMesaj() == "Destinatie invalida!\n");
	}
	try {
		testValidator.valideaza(oferta_gresita2);
	}
	catch (ValidError& error) {
		assert(error.getMesaj() == "Tip invalid!\n");
	}
	try {
		testValidator.valideaza(oferta_gresita3);
	}
	catch (ValidError& error) {
		assert(error.getMesaj() == "Pret invalid!\n");
	}
}
