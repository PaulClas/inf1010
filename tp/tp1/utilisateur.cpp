/********************************************
* Titre: utilisateur.cpp
* Date: 23 septembre 2018
* Auteur: Paul Clas
* Description: Implémentation de la classe utilisateur
*******************************************/
#include "utilisateur.h"

/********************************************************
* Nom de fonction : Consctructeur par defaut
* Description : Consruit groupe
* Paramètre : void
* Return : void
*********************************************************/
Utilisateur::Utilisateur()
{
	nom_= "unknown";
	tailleTabDepense_ = 0;
	nombreDepenses_ = 0;
	totalDepense_=0.0;
	listeDepenses_=nullptr;
}

/********************************************************
* Nom de fonction : Consctructeur par param
* Description : Consruit Utilisateur
* Paramètre : string& nom
* Return : void
*********************************************************/
Utilisateur::Utilisateur(string & nom)
{
	nom_ = nom;
}

/********************************************************
* Nom de fonction : Destructeur
* Description : Detruit Utilisateur
* Paramètre : void
* Return : void
*********************************************************/
Utilisateur::~Utilisateur()
{
}

/********************************************************
* Nom de fonction : getNom()
* Description : retourne nom_
* Paramètre : void
* Return : nom_
*********************************************************/
string Utilisateur::getNom() const
{
	return nom_;
}

/********************************************************
* Nom de fonction : getNombreDepense()
* Description : retourne nombreDepenses_
* Paramètre : void
* Return : nombreDepenses_
*********************************************************/
unsigned int Utilisateur::getNombreDepense() const
{
	return nombreDepenses_;
}

/********************************************************
* Nom de fonction : getTotal()
* Description : retourne totalDepense_
* Paramètre : void
* Return : totalDepenses_
*********************************************************/
double Utilisateur::getTotal() const
{
	return totalDepense_;
}

/********************************************************
* Nom de fonction : setNom()
* Description : met la valeur en param de nom dans nom_
* Paramètre : string& nom
* Return : void
*********************************************************/
void Utilisateur::setNom(string & nom)
{
	nom_ = nom;
}

/********************************************************
* Nom de fonction : ajouterDepense()
* Description : ajoute une depense a un utilisateur
* Paramètre : Depense* uneDepense
* Return : void
*********************************************************/
void Utilisateur::ajouterDepense(Depense * uneDepense)
{
	if (listeDepenses_ == nullptr) {
		tailleTabDepense_ = 5;
		listeDepenses_ = new Depense*[tailleTabDepense_];
		nombreDepenses_ = 0;
	}
	if (tailleTabDepense_ <= nombreDepenses_) {
		Depense** temporaire = new Depense*[tailleTabDepense_++];
		for (int i = 0; i < tailleTabDepense_; i++) {
			temporaire[i] = listeDepenses_[i];
		}
		delete[] listeDepenses_;
		listeDepenses_ = temporaire;
		delete[] temporaire;
	}
	listeDepenses_[nombreDepenses_] = new Depense;
	listeDepenses_[nombreDepenses_]->setTitre(uneDepense->getTitre());
	listeDepenses_[nombreDepenses_]->setMontant(uneDepense->getMontant());
	nombreDepenses_++;
	

}
/********************************************************
* Nom de fonction : calculerTotal()
* Description : calcul le total des depenses par utilisateurs
* Paramètre : void
* Return : void
*********************************************************/
void Utilisateur::calculerTotal()
{
	totalDepense_ = 0;
	for (int i = 0; i < nombreDepenses_; i++) {
		totalDepense_ += listeDepenses_[i]->getMontant();
	}
}

/********************************************************
* Nom de fonction : afficherUtilisateur()
* Description : affiche l'utilisateur
* Paramètre : void
* Return : void
*********************************************************/
void Utilisateur::afficherUtilisateur() const
{
	cout << "Utilisateur: " << nom_ << ends << " Nombre de depenses: "<< nombreDepenses_ << ends << " Nombre total de depenses : " 
		<< totalDepense_ << "$" << endl;
}
