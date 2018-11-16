/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa 
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur(): interet_(0), nom_(""), type_(Regulier), totalDepense_(0)
{
}

Utilisateur::Utilisateur(const string & nom, TypeUtilisateur type): interet_(0),
	nom_(nom), totalDepense_(0),    type_(type)
{
}

Utilisateur::Utilisateur(const Utilisateur & utilisateur): 
	interet_(utilisateur.interet_), nom_(utilisateur.nom_), type_(utilisateur.type_),totalDepense_(utilisateur.totalDepense_)
{
	for (unsigned int i = 0; i < utilisateur.depenses_.size(); i++){
		depenses_.push_back(new Depense(*utilisateur.depenses_[i]));
	}
}

Utilisateur::~Utilisateur()
{
	for (int i = 0; i < depenses_.size(); i++){
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
}


// Methodes d'acces



string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getTotalDepenses() const {
	return totalDepense_;
}

TypeUtilisateur Utilisateur::getType() const {
	return type_; 
}

double Utilisateur::getInteret() const {
	return interet_; 
}

unsigned int Utilisateur::getNombreDepenses() const {
	
	return depenses_.size();
}

vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_; 
}

//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::calculerTotalDepenses() {
	for (unsigned int i = 0; i < depenses_.size(); i++)
	{
		totalDepense_ += static_cast<DepenseGroupe *>(depenses_[i])->getMontantPersonnel(); // +depenses_[i]->getMontant();
	
	}
	
}

Utilisateur& Utilisateur::operator=(Utilisateur * utilisateur)
{
	if (this != utilisateur)
	{
		interet_ = utilisateur->interet_;
		nom_ = utilisateur->nom_;
		type_ = utilisateur->type_;
		totalDepense_ = utilisateur->totalDepense_;
		if (depenses_.size() == 0)
		{
			for (unsigned int i = 0; i < utilisateur->depenses_.size(); i++)
				depenses_.push_back(new Depense(*(utilisateur->depenses_[i])));
		}
		else
		{
			for (unsigned int i = (unsigned int)(depenses_.size() - 1); i >= 0; i--)
			{
				delete depenses_[i];
				depenses_.pop_back();
			}

			for (unsigned int i = 0; i < utilisateur->depenses_.size(); i++)
				depenses_.push_back(new Depense(*(utilisateur->depenses_[i]))); 
		}
	}
	return *this;
	
}


void Utilisateur::ajouterInteret(double montant) {
	interet_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {
	if (depense->getType() == groupe)
		depenses_.push_back(new DepenseGroupe(*(static_cast<DepenseGroupe *>(depense))));
	else
		depenses_.push_back(new Depense(*depense));
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)

{
	os << "Utilisateur : (";

	if (utilisateur.getType() == Regulier)
		os << "Regulier";
	else
		os << "Premium";

	os <<") "<< utilisateur.nom_<<" a depense un total de: " << utilisateur.getTotalDepenses() << " $ PolyCount prend un interet: " << utilisateur.interet_ << "   Liste depenses : " << endl;

	for (int i = 0; i < utilisateur.depenses_.size(); i++)
	{
		os << ends << ends << ends << ends << ends;
			if (utilisateur.depenses_[i]->getType() == groupe)
				os << *(static_cast<DepenseGroupe *>(utilisateur.depenses_[i])) << endl;
			else
				os << *(utilisateur.depenses_[i]) << endl;
	}
	return os;
}
