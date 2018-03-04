#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

class Individu
{
private:

	string numeroSecuriteSociale;
	string nom;
	string prenom;
	int jourNaissance;
	int moisNaissance;
	int anneeNaissance;
	string profession;

public:

	Individu(string monNumSecu, string monNom, string monPremon, int monJourNaissance, int monMoisNaissance, int monAnneeNaissance, string maProfession) : numeroSecuriteSociale(monNumSecu), nom(monNom), prenom(monPremon), jourNaissance(monJourNaissance), moisNaissance(monMoisNaissance), anneeNaissance(monAnneeNaissance), profession(maProfession) {};

	string getNom() const { return nom; };
	string getPrenom() const { return prenom; };
	string getNumSecu() const { return numeroSecuriteSociale; };
	string getProfession() const { return profession; };

	string getDateNaissance() const;

	void setProfession(string const maProfession) { profession = maProfession; };



};