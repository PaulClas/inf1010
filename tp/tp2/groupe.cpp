/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************
* Titre: groupe.cpp
* Date: 2 octobre 2018
* Auteur: Paul Clas
* Description: Implémentation de la classe groupe
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() :
	nom_("")
	//nombreDepenses_(0),
	//nombreUtilisateurs_(0),
	//tailleTabUtilisateurs_(5),
	//tailleTabDepenses_(10),
	//depenses_(new Depense*[tailleTabDepenses_]),
	//utilisateurs_(new Utilisateur*[tailleTabUtilisateurs_]),
	//comptes_(new double[nombreUtilisateurs_]),
	//transferts_(new Transfert*[nombreUtilisateurs_]),
	//nombreTransferts_(0)
{
}

Groupe::Groupe(const string& nom) :
	nom_(nom)
	//nombreDepenses_(0),
	//nombreUtilisateurs_(0),
	//tailleTabUtilisateurs_(tailleTabUtilisateurs),
	//tailleTabDepenses_(tailleTabDepenses),
	//depenses_(new Depense*[tailleTabDepenses]),
	//utilisateurs_(new Utilisateur*[tailleTabUtilisateurs]),
	//comptes_(new double[nombreUtilisateurs_]),
	//transferts_(new Transfert*[nombreUtilisateurs_]),
	//nombreTransferts_(0)
{
}


Groupe::~Groupe() {
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
		transferts_[i] = nullptr;
	}
	transferts_.clear();
	//delete[] transferts_;
	//transferts_ = nullptr;
	for (int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
	depenses_.clear();

	for (int i = 0; i < utilisateurs_.size(); i++) {
		delete utilisateurs_[i];
		utilisateurs_[i] = nullptr;
	}
	utilisateurs_.clear();

	//puisque vecteur compte ?
	comptes_.clear();
	//delete[] utilisateurs_;
	//utilisateurs_ = nullptr;

}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const {
	return depenses_.size();
}

double Groupe::getTotalDepenses() const {
	double total = 0;
	for (int i = 0; i < depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

Groupe & Groupe::operator+=(Utilisateur * utilisateur)
{
	// TODO: insert return statement here
	utilisateurs_.push_back(utilisateur);
	return *this;

}

Groupe & Groupe::ajouterDepense(Depense * depense, Utilisateur * utilisateur)
{
	// TODO: insert return statement here
	depenses_.push_back(depense);
	*utilisateur += depense;
	return *this;
}

// Methodes d'ajout
/*
void Groupe::ajouterDepense(Depense* depense, Utilisateur* utilisateur) {
	if (nombreDepenses_ >= tailleTabDepenses_) {

		tailleTabDepenses_ *= 2;

		Depense** listeTemp = new Depense*[tailleTabDepenses_];

		for (unsigned int i = 0; i < nombreDepenses_; i++) {
			listeTemp[i] = depenses_[i];
		}
		delete[] depenses_;

		depenses_ = listeTemp;
	}

	depenses_[nombreDepenses_++] = depense;
	utilisateur->ajouterDepense(depense);

}
*/

/*
void Groupe::ajouterUtilisateur(Utilisateur* unUtilisateur) {
	if (nombreUtilisateurs_ >= tailleTabUtilisateurs_) {
		tailleTabUtilisateurs_ *= 2;

		Utilisateur** listeTemp = new Utilisateur*[tailleTabUtilisateurs_];

		for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
			listeTemp[i] = utilisateurs_[i];
		}
		delete[] utilisateurs_;

		utilisateurs_ = listeTemp;
	}
	utilisateurs_[nombreUtilisateurs_++] = unUtilisateur;
}
*/

void Groupe::calculerComptes()
{
	double moyenne = getTotalDepenses() / utilisateurs_.size();
	for (int i = 0; i < utilisateurs_.size(); i++) {
		comptes_.push_back((utilisateurs_[i]->getTotalDepenses()) - moyenne);
	}
}

void Groupe::equilibrerComptes() {
	calculerComptes();
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max) {
			//transferts_[nombreTransferts_++] = new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]);
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else {
			//transferts_[nombreTransferts_++] = new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]);
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}
}


// Methode d'affichage
/*
void Groupe::afficherGroupe() const {
	cout << "L'evenement " << nom_ << " a coute un total de " << getTotalDepenses() << " :  \n\n";
	for (int i = 0; i < nombreUtilisateurs_; i++) {
		utilisateurs_[i]->afficherUtilisateur();
	}
	cout << endl;

	if (nombreTransferts_ != 0) {
		cout << "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
		for (int i = 0; i < nombreTransferts_; i++) {
			cout << "\t";
			transferts_[i]->afficherTransfert();
		}
	}
	else {
		cout << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	cout << endl;
}
*/

ostream& operator<<(ostream &out, const Groupe& groupe)
{
	out << "L'evenement " << groupe.nom_ << " a coute un total de " << groupe.getTotalDepenses() << " :  \n\n";
	for (int i = 0; i < groupe.utilisateurs_.size(); i++) {
		out << *groupe.utilisateurs_[i] << endl;
	}
	out << endl;

	if (groupe.transferts_.size() != 0) {
		out << "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++) {
			out << "\t" << *groupe.transferts_[i];
		}
	}
	else {
		out << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	out << endl;
	return out;
}
