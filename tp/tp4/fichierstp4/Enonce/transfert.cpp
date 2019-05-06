/********************************************
* Titre: Travail pratique #4 - transfert.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modification: Paul Clas 1846912
*******************************************/
#include "transfert.h"

// Constructeurs
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {
}

// Methodes d'acces
double Transfert::getMontant() const {
	return montant_;
}

double Transfert::getFraisTransfert() const
{
	//Demander à Akim ???
	return 0.0;
}

Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

// Methodes de modifications
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

void Transfert::setExpediteur(Utilisateur *donneur) {
	expediteur_ = donneur;
}

void Transfert::setReceveur(Utilisateur *receveur) {
	receveur_ = receveur;
}

void Transfert::effectuerTransfert()
{
	expediteur_->modifierBalanceTranferts(getMontant());
	receveur_->modifierBalanceTranferts(-getMontant());
	//if(dynamic_cast<UtilisteurRegulier*>(expediteur_)) ?? Bon ben ca marche, demander a Akim
	if (typeid(*expediteur_) == typeid(UtilisateurPremium))
	{
		expediteur_->modifierBalanceFrais(-getMontant() *TAUX_EPARGNE);
	}
	else
	{
		expediteur_->modifierBalanceFrais(getFraisTransfert());
	}
}

//Methode affichage
ostream& operator<<(ostream& os, const Transfert& transfert) {
	os <<"Transfert"<< transfert.getExpediteur()->getNom() << "vers " << transfert.getReceveur()->getNom()
		<< "  de " << transfert.getMontant() << "  $" << endl;
	return os;
}
