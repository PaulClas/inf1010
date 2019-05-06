/********************************************
* Titre: transfert.cpp
* Date: 23 septembre 2018
* Auteur: Paul Clas
* Description: Implémentation de la classe trasnfert
********************************************/
#include "transfert.h"
#include <iostream>

using namespace std;

/********************************************************
* Nom de fonction : Consctructeur par defaut
* Description : Consruit transfert
* Paramètre : void
* Return : void
*********************************************************/
Transfert::Transfert()
{
	montant_ = 0;
	donneur_ = nullptr;
	receveur_ = nullptr;
}

/********************************************************
* Nom de fonction : Consctructeur par parametre
* Description : Consruit transfert avec parametre
* Paramètre : montant_, donneur_, receveur_
* Return : void
*********************************************************/
Transfert::Transfert(double montant, Utilisateur * de, Utilisateur * pour)
{
	montant_ = montant;
	donneur_ = de;
	receveur_ = pour;

}

/********************************************************
* Nom de fonction : getDonneur()
* Description : retourne donneur_
* Paramètre : void
* Return : donneur_
*********************************************************/
Utilisateur * Transfert::getDonneur() const
{
	return donneur_;
}

/********************************************************
* Nom de fonction : getReceveur()
* Description : retourne receveur_
* Paramètre : void
* Return : receveur_
*********************************************************/
Utilisateur * Transfert::getReceveur() const
{
	return receveur_;
}
/********************************************************
* Nom de fonction : getMontant()
* Description : retourne montant_
* Paramètre : void
* Return : montant_
*********************************************************/
double Transfert::getMontant() const
{
	return montant_;
}
/********************************************************
* Nom de fonction : setDonneur()
* Description : prends le donneur en param et le mets dans 
donneur_
* Paramètre : Utilisateur* donneur
* Return : void
*********************************************************/
void Transfert::setDonneur(Utilisateur * donneur)
{
	donneur_ = donneur;
}

/********************************************************
* Nom de fonction : setMontant()
* Description : prends le montant en param et le mets dans
montant_
* Paramètre : double montant
* Return : void
*********************************************************/
void Transfert::setMontant(double montant)
{
	montant_ = montant;
}

/********************************************************
* Nom de fonction : setReceveur()
* Description : prends le receveur en param et le mets dans
receveur_
* Paramètre : Utilisateur* receveur
* Return : void
*********************************************************/
void Transfert::setReceveur(Utilisateur * receveur)
{
	receveur_ = receveur;
}

/********************************************************
* Nom de fonction : afficherTransfert()
* Description : affiche le transfert
* Paramètre : void
* Return : void
*********************************************************/
void Transfert::afficherTransfert() const
{
	cout << "Transfert:" << ends
		<< " Montant: " << montant_ << ends
		<< " Donneur: " << donneur_->getNom() << ends
		<< " Receveur: " << receveur_ ->getNom() << endl;
}
