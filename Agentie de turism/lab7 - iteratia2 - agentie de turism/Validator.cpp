#include "Validator.h"
#include <string>
using std::string;


void Validator::valideaza(const Oferta& oferta) {
	string erori = "";
	if (oferta.getDenumire() == "")
		erori += "Denumire invalida!\n";

	if (oferta.getDestinatie() == "")
		erori += "Destinatie invalida!\n";

	if (oferta.getTip() == "")
		erori += "Tip invalid!\n";

	if (oferta.getPret() <= 0)
		erori += "Pret invalid!\n";

	if (erori != "")
		throw ValidError{ erori };
}
