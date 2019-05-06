/********************************************
* Titre: Travail pratique #2 - depense.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************
* MODIFICATION
* Titre: depense.h
* Date: 8 octobre 2018
* Mofication: Paul Clas, 1846912
*******************************************/
#ifndef DEPENSE_H
#define DEPENSE_H

#include <string>
#include <iostream>

using namespace std;

class Depense {
public:
	// Constructeurs
	// TODO: Ajouter le attribut objet dans les constructeurs
	Depense();
	Depense(const string& nom, double montant, const string& lieu);

	// TODO: Ajouter un constructeur par copie
	Depense(const Depense& depense);

	// Methodes d'acces
	string getNom() const;
	double getMontant() const;
	string getLieu() const;

	// Methodes de modifications
	void setNom(const string& nom);
	void setMontant(double montant);
	//Ajout de setLieu(const string& lieu);
	void setLieu(const string& lieu);

	// TODO: Ajouter une surcharge de l'operateur =
	Depense operator=(const Depense& depense);

	// TODO: Remplacer par une surcharge de l'operateur <<
	//void afficherDepense() const;
	friend ostream& operator <<(ostream& out, const Depense& depense);

private:
	string nom_;
	double montant_;
	// TODO: Ajouter l'attribut lieu
	string lieu_;
};
#endif