#include "Individu.h"
#include <fstream>
	
using namespace std;

// !!ATTENTION!! Ouvrir Visual Studio en administrateur! Sinon, il ne sera pas autorisé à écrire!

////Utilisé pour la taille du fichier binaire
//const int TAILLE = 1000;

int main()
{
	//gère la réponse de l'utilisateur
	char reponse;
	//utilisé dans la boucle plus bas
	bool loop = true;
	//utilisé pour la recherche de ligne dans le getline()
	string line;

	//On déclare le nom de la variable qui va écrire dans le fichier
	ofstream Ecriture;
	//On ouvre le fichier Individu.txt, sans effacer ce qu'il y a dedans | se met à la fin du fichier. Les ios:: sont nommés les flags
	Ecriture.open("Individu.txt", ios::app | ios::ate);
	//J'ai essayé de le mettre dans le if de l'enrgistrement, mais ça casse tout, me disant que cout est ambigu

	//On déclare le nom de la variable qui va écrire en binaire
	ofstream BinEcriture;
	BinEcriture.open("Individu.bin", ios::app | ios::ate);

	//On déclare le nom de la variable qui va lire dans le fichier
	ifstream laLecture;

	//On déclare le nom de la variable qui va lire dans le fichier binaire
	ifstream BinlaLecture;

	Individu unIndividu("270497256789", "WEBER", "Max", 27, 04, 1997, "superDev (sisi)");

	cout << "Developpe par : " << unIndividu.getNom() << " " << unIndividu.getPrenom() << ", un " << unIndividu.getProfession() << endl << endl << endl;
	
	cout << "Bienvenu a l'agence des individus non-anonyme!" << endl << endl;
	cout << "Vous pourrez entrer si dessous vos données personnelles." << endl << endl;
	cout << "Bien evidement, ces données seront securisees, sauvegardees dans l'ordinateur que vous utilisez ici, dans un fichier texte." << endl << endl;
	cout << "En revanche, elle ne resteront pas confidentielles longtemps... le temps que quelqu'un ouvre ce fichier et trouve toutes les donnees en fait..." << endl << endl;
	//SECRET : Entrez 0 pour enregistrer en mode binaire, 1 pour lire le fichier binaire

	while (loop)
	{
		cout << "voulez-vous vous enregistrer ou chercher quelqu'un d'existant dans le fichier? ('s' pour s'enregistrer, 'f' pour chercher, n'importe quoi d'autre pour quitter) : ";
		cin >> reponse;

			
		if (reponse == 's' || reponse == '0')
		{
			cout << endl << "Bien! Enregistrons-vous!" << endl << endl;
			string secu;
			string prenom;
			string nom;
			int jour;
			int mois;
			int annee;
			string profession;
			string infos;

			cout << "Quel est votre nom : ";
			cin >> nom;
			cout << "Quel est votre prenom : ";
			cin >> prenom;
			cout << "Quel est votre jour de naissance : ";
			cin >> jour;
			cout << "Quel est votre mois de naissance (en chiffre) : ";
			cin >> mois;
			cout << "Quel est votre annee de naissance : ";
			cin >> annee;
			cout << "Quel est votre profession : ";
			cin >> profession;
			cout << "Et enfin, quel est votre numero de securite sociale : ";
			cin >> secu;
			cout << endl;

			Individu Vous(secu, nom, prenom, jour, mois, annee, profession);
			
			infos = Vous.getNom() + " " + Vous.getPrenom() + " -> Numero de securite sociale : " + Vous.getNumSecu() + ", Date de naissance : " + Vous.getDateNaissance() + ", Profession : " + Vous.getProfession() + "\n";

			if (reponse == '0')
			{
				//Si on veut écrire en binaire:
				//On écrit (les informations, la taille que doit prendre nos infos)
				BinEcriture.write(infos.c_str(), infos.size());
				cout << "Vous avez été enregistre.e en binaire" << endl << endl;
			}

			else
			{
				if (Ecriture.is_open())
				{
					//cout << Vous.getNom() << " " << Vous.getPrenom() << " -> Numero de securite sociale : " << Vous.getNumSecu() << ", Date de naissance : " << Vous.getDateNaissance() << ", Profession : " << Vous.getProfession() << "\n";
					//Ecriture << Vous.getNom() << " " << Vous.getPrenom() << " -> Numero de securite sociale : " << Vous.getNumSecu() << ", Date de naissance : " << Vous.getDateNaissance() << ", Profession : " << Vous.getProfession() << "\n";
					//Ecriture dans le fichier
					Ecriture << infos;
					cout << "Vous avez ete enregistre.e avec succes!" << endl << endl;
				}
				else 
					cout << "le fichier n'est pas ouvert!";
			}
			
			
		}

		else if (reponse == 'f')
		{
			//Valeur à tester
			string test;
			//S'occupera de la recherche de la valeur dans les lignes
			size_t recherche;
			//Permet de savoir si personne n'a ete trouve;
			bool trouve = false;

			cout << endl << endl << "Entrez un nom a chercher : " << endl;
			cin >> test;
			laLecture.open("Individu.txt");

			if (laLecture.is_open())
			{
				while (getline(laLecture, line))
				{
					//Cherche si il trouve test dans line, la ligne retournée par le getline
					recherche = line.find(test);
					if (!recherche)
					{
						//recherche si le test a bien ete trouve dans la ligne. Il faut lui demande l'inverse avec ! sinon il nous renvois les lignes qui n'ont pas le test à l'interieur.
						cout << line << endl;
						trouve = true;
					}
				}
				if (!trouve)
					cout << endl << endl << "Nous n'avons pas pu trouver d'infromation correspondant. Faites attention a ce qu'il n'y ai pas de fautes";
			}

			else
				cout << "Le fichier n'est pas ouvert!";

			cout << endl << endl << endl;
			laLecture.close();
		}

		else if (reponse == '1')
		{
			//Lecture en mode binaire :
			BinlaLecture.open("Individu.bin");
			cout << "binaire" << endl;
			while (getline(BinlaLecture, line))
			{
				cout << line << endl;
			}
			cout << "fin du fichier binaire" << endl << endl;
		}
			

		else
		{
			cout << endl << endl << "Merci d'avoir utilise nos services!" << endl << endl;
			loop = false;
		}
	}

	Ecriture.close();
	system("pause");


	return 0;
}