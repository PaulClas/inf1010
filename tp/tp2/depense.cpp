/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************/

#include "depense.h"

// Constucteurs
Depense::Depense() : nom_(""), montant_(0) {
}

Depense::Depense(const string& nom, double montant, const string& lieu) : nom_(nom), montant_(montant), lieu_(lieu) {
}

Depense::Depense(const Depense & depense): nom_(depense.nom_), montant_(depense.montant_), lieu_(depense.lieu_)
{
}

// Methodes d'acces
string Depense::getNom() const {
	return nom_;
}

double Depense::getMontant() const {
	return montant_;
}

string Depense::getLieu() const
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

void Depense::setLieu(const string & lieu)
{
	lieu_ = lieu;
}

Depense Depense::operator=(const Depense & depense)
{
	nom_ = depense.nom_;
	montant_ = depense.montant_;
	lieu_ = depense.lieu_;

	return *this;
}

// Methode d'affichage
/*
void Depense::afficherDepense() const {
	cout << "Achat : " << nom_ << " Prix : " << montant_ << "; " << endl;
}
*/

ostream& operator<<(ostream &out, const Depense &depense) {
	out << ends << ends << ends << "Depense Nom: " << depense.getNom() << " Montant: "
		<< depense.getMontant() << " Lieu: " << depense.getLieu();
	return out;
}
