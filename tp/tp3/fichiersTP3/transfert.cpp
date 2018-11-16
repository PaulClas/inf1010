/********************************************
* Titre: Travail pratique #2 - transfert.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene 
*******************************************
MODIFICATION
* Titre: transfert.cpp
* Date : 22 octobre 2018
* Auteur : Paul Clas
* Description : Implémentation de la classe transfert.cpp
********************************************/

#include "transfert.h"

// Constructeurs
/********************************************************
* Nom de fonction : Transfert()
* Description : constructeur par default
* Paramètre: void
* Return : void
*********************************************************/
Transfert::Transfert() : montant_(0), expediteur_(nullptr), receveur_(nullptr) {
}

/********************************************************
* Nom de fonction : Transfert()
* Description : constructeur par paramètre
* Paramètre: void
* Return : void
*********************************************************/
Transfert::Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur) : 
	montant_(montant), expediteur_(expediteur), receveur_(receveur) {
}

// Methodes d'acces
/********************************************************
* Nom de fonction : getMontant()
* Description : retourne la valeur de montant
* Paramètre:void 
* Return : double montant_
*********************************************************/
double Transfert::getMontant() const {
	return montant_;
}

/********************************************************
* Nom de fonction : getExpediteur()
* Description : retourne la valeur de expediteur
* Paramètre:void
* Return : Utilisateur* expediteur_
*********************************************************/
Utilisateur* Transfert::getExpediteur() const {
	return expediteur_;
}

/********************************************************
* Nom de fonction : getReceveur()
* Description : retourne la valeur de receveur
* Paramètre:void
* Return : Utilisateur* receveur_
*********************************************************/
Utilisateur* Transfert::getReceveur() const {
	return receveur_;
}

// Methodes de modifications
/********************************************************
* Nom de fonction : setMontant()
* Description : place la valeur de montant dans montant_
* Paramètre: double montant
* Return : void
*********************************************************/
void Transfert::setMontant(double montant) {
	montant_ = montant;
}

/********************************************************
* Nom de fonction : setExpediteur()
* Description : place la valeur de expediteur dans expediteur_
* Paramètre: Utilisateur *donneur
* Return : void
*********************************************************/
void Transfert::setExpediteur(Utilisateur *donneur) {
	expediteur_ = donneur;
}

/********************************************************
* Nom de fonction : setReceveur()
* Description : place la valeur de receveur dans receveur_
* Paramètre : Utilisateur *receveur
* Return : void
*********************************************************/
void Transfert::setReceveur(Utilisateur *receveur) {
	receveur_ = receveur;
}

//Methode affichage
/********************************************************
* Nom de fonction : ostream& operator<<
* Description : Sucharge de l'opérateur <<
* Paramètre : ostream& os, const Transfert& transfert
* Return : os
*********************************************************/
ostream& operator<<(ostream& os, const Transfert& transfert) {
	return os << "Transfert fait par " << transfert.getExpediteur()->getNom() << " vers " << transfert.getReceveur()->getNom() << " d'un montant de " << transfert.getMontant() << endl;
}
