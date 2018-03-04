#include "Individu.h"

//retourne le jour, le mois et l'année de naissance en une ligne. Les dates sont separees de / (ce qui donnera 27/04/1997, voir 27/4/97)
string Individu::getDateNaissance() const
{
	return to_string(jourNaissance) + "/" + to_string(moisNaissance) + "/" + to_string(anneeNaissance);
}

