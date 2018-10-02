/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************
* MODIFICATION
* Titre: utilisateur.cpp
* Date: 8 octobre 2018
* Auteur: Paul Clas
* Description: Implémentation de la classe utilisateur
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_("")
{
}

Utilisateur::Utilisateur(const string& nom) : nom_(nom)
{
}

Utilisateur::Utilisateur(const Utilisateur & utilisateur) : nom_(utilisateur.nom_)
{
	for (int i = 0; i < utilisateur.depenses_.size(); i++){
	//depenses_[i] = new Depense(*utilisateur.depenses_[i]);
	depenses_.push_back(new Depense(*utilisateur.depenses_[i]));
	}

}

//Destructeur
Utilisateur::~Utilisateur() {
	for (int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
	depenses_.clear();
	//delete[] depenses_;
	//depenses_ = nullptr;
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return depenses_.size();
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (int i = 0; i < depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}
Utilisateur Utilisateur::operator+=(Depense * uneDepense)
{
	depenses_.push_back(uneDepense);
	return *this;
}
Utilisateur Utilisateur::operator=(const Utilisateur& utilisateur)
{
	if (this != &utilisateur) {
		for (int i = 0; i < depenses_.size(); i++) {
			delete depenses_[i];
			depenses_[i] = nullptr;
			depenses_.pop_back();
		}
		depenses_.clear();
		for (int i = 0; i < depenses_.size(); i++) {
			depenses_.push_back(new Depense(*utilisateur.depenses_[i]));
		}
	}
	return *this;
}
/*
void Utilisateur::ajouterDepense(Depense* depense) {
	if (nombreDepenses_ == tailleTabDepense_) {
		tailleTabDepense_ *= 2;

		Depense** listeTemp = new Depense*[tailleTabDepense_];
		for (unsigned int i = 0; i < nombreDepenses_; i++) {
			listeTemp[i] = depenses_[i];
		}
		delete[] depenses_;

		depenses_ = listeTemp;
	}
	depenses_[nombreDepenses_++] = depense;
}
*/


// Methode d'affichage

/*
void Utilisateur::afficherUtilisateur() const {

	cout << "Utilisateur : " << nom_ << " a depense pour un total de : " << getTotalDepenses() << endl;
	cout << "\t Liste de depenses : " << endl;
	for (int i = 0; i < nombreDepenses_; i++) {
		cout << "\t\t";
		depenses_[i]->afficherDepense();
	}

}
*/

ostream & operator<<(ostream & out, const Utilisateur & utilisateur)
{
	// TODO: insert return statement here
	out << "Utilisateur: " << utilisateur.getNom() << ends << ends << ends
		<< "Total: " << utilisateur.getTotalDepenses() << "$" << endl
		<< ends << ends << ends << "Liste des depenses: " << endl;
	for (int i = 0; i < utilisateur.depenses_.size(); i++) {
		out << ends << ends << ends << ends << *utilisateur.depenses_[i] << endl;
	}
	out << endl;
	return out;
}
