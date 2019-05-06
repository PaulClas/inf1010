/********************************************
* Titre: Travail pratique #4 - depense.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modification: Paul Clas 1846912
*******************************************/

#include "depense.h"

// Constucteurs

Depense::Depense(const string& nom, double montant, const string& lieu): nom_(nom), montant_(montant), lieu_(new string(lieu)) {
}

Depense::Depense(const Depense & depense): nom_(depense.nom_), montant_(depense.montant_), lieu_(new string(*depense.lieu_))
{
}

Depense::~Depense()
{
	delete lieu_;
}


// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string* Depense::getLieu() const
{
	return lieu_;
}

// Methodes de modifications
void Depense::setNom(const string& nom) {
	nom_ = nom;
}

void Depense::setMontant(double montant) {
	montant_ = montant;
}

void Depense::setLieu(const string& nom)
{
	*lieu_ = nom;
}

Depense & Depense::operator=(const Depense & depense)
{
	// TODO: insert return statement here
	if (this != &depense){
		nom_ = depense.getNom();
		montant_ = depense.getMontant();
		
		delete lieu_;
		lieu_ = new string(*depense.lieu_);
	}

	return *this;
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Depense& depense)
{
	 os <<ends << ends <<"-Depense (a " << *depense.lieu_ << ") : "  << depense.nom_ << ". Prix : " << depense.montant_ << "$" << endl;
	 return os;
}
