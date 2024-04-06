#include "UI.h"
#include <iostream>
#include <string>
#include "Oferta.h"

using std::cin;
using std::cout;


void UI::afisareMeniu() {
	cout << "--------------------------------------------------------------------\n";
	cout << "Comenzi disponibile:\n";
	cout << "\n";
	cout << "	1 - Adauga oferta\n";
	cout << "	2 - Afiseaza toate ofertele din agentia de turism\n";
	cout << "	3 - Modifica o oferta\n";
	cout << "	4 - Sterge o oferta\n";
	cout << "	5 - Filtrare oferte (criterii: destinatie/pret)\n";
	cout << "	6 - Sorteaza ofertele (dupa denumire/destinatie/tip+pret)\n";
	cout << "	0 - Exit\n";
	cout << "\n";
	cout << "--------------------------------------------------------------------\n";
	cout << "Introduceti comanda dorita: ";
}

void UI::ui_adauga_oferta() {
	string denumire, destinatie, tip;
	double pret;
	cout << "Denumire: ";
	cin >> denumire;
	cout << "Destinatie: ";
	cin >> destinatie;
	cout << "Tip: ";
	cin >> tip;
	cout << "Pret:";
	cin >> pret;
	try {
		service.adauga_oferta(denumire, destinatie, tip, pret);
		cout << "Oferta adaugata cu succes!";
	}
	catch (RepoException& exception) {
		cout << exception.getMesaj();
	}
}

void UI::ui_afisare_oferte(const VectorDinamic<Oferta>& toateOfertele) {
	if (toateOfertele.size() == 0)
		cout << "Nu exista oferte in agentia de turism!\n";
	else {
		cout << "Ofertele sunt: \n";
		for (const auto& oferta : toateOfertele) {
			cout << "Denumire: " << oferta.getDenumire() << " | Destinatie: " << oferta.getDestinatie() << " | Tip: " << oferta.getTip() << " | Pret: " << oferta.getPret() << '\n';
		}
		cout << "\nSfarsit lista oferte.\n";
	}
}

void UI::ui_modifica_oferta() {
	string denumire, destinatie_noua, tip_nou;
	int pret_nou;
	cout << "Alegeti oferta: ";
	cin >> denumire;
	cout << "\n";
	cout << "Destinatie noua: ";
	cin >> destinatie_noua;
	cout << "Tip nou: ";
	cin >> tip_nou;
	cout << "Pret nou: ";
	cin >> pret_nou;
	service.modifica_oferta(denumire, destinatie_noua, tip_nou, pret_nou);
	cout << "Oferta modificata cu succes!\n";
}

void UI::ui_sterge_oferta() {
	cout << "Oferta dorita: ";
	string denumire;
	cin >> denumire;
	service.sterge_oferta(denumire);
	cout << "Oferta stearsa cu succes!\n";
}

void UI::ui_sorteaza() {
	cout << "Criteriul de sortare dorit (denumire/destinatie/tip+pret): ";
	string criteriu;
	cin >> criteriu;
	if (criteriu == "denumire")
		ui_afisare_oferte(service.sorteazaDenumire());
	else if (criteriu == "tip+pret")
		ui_afisare_oferte(service.sorteazaTipPret());
	else if (criteriu == "destinatie")
		ui_afisare_oferte(service.sorteazaDestinatie());
	else
		cout << "Nu se poate sorta dupa criteriul dat!\n";
}

void UI::ui_filtreaza() {
	cout << "Criteriul de filtrare dorit (destinatie/pret): ";
	string criteriu;
	cin >> criteriu;
	if (criteriu == "destinatie") {
		cout << "Destinatia pentru care se afiseaza ofertele: \n";
		string oferta_dupa_destinatie;
		cin >> oferta_dupa_destinatie;
		ui_afisare_oferte(service.filtrareDestinatie(oferta_dupa_destinatie));
	}
	else if (criteriu == "pret") {
		string oferta_dupa_pret;
		cin >> oferta_dupa_pret;
		ui_afisare_oferte(service.filtrarePret(oferta_dupa_pret));
	}
	else
		cout << "Nu se poate sorta dupa criteriul dat!\n";
}

void UI::run() {
	while (true) {
		int comanda = 0;
		afisareMeniu();
		cin >> comanda;
		if (comanda == 1)
			ui_adauga_oferta();
		else if (comanda == 2)
			ui_afisare_oferte(service.getAll());
		else if (comanda == 3)
			ui_modifica_oferta();
		else if (comanda == 4)
			ui_sterge_oferta();
		else if (comanda == 5)
			ui_filtreaza();
		else if (comanda == 6)
			ui_sorteaza();
		else if (comanda == 0)
			break;
		else
			cout << "Comanda invalida!";
	}
}
