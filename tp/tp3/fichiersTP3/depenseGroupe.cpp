/********************************************
* Titre: depenseGroupe.cpp
* Date : 22 octobre 2018
* Auteur : Paul Clas
* Description : Impl�mentation de la classe depenseGroupe
********************************************/
#include "depenseGroupe.h"

// Constructeur par param
/********************************************************
* Nom de fonction : DepenseGroupe()
* Description : constructeur par param�tre
* Param�tre: void
* Return : void
*********************************************************/
DepenseGroupe::DepenseGroupe(const string & nom, double montant, const string & lieu): Depense(nom, montant, lieu, groupe), nombreParticipants_(0)
{
}

// Constructeur par Copie
/********************************************************
* Nom de fonction : DepenseGroupe()
* Description : constructeur par copie
* Param�tre: void
* Return : void
*********************************************************/
DepenseGroupe::DepenseGroupe(const DepenseGroupe & depense): Depense(depense), nombreParticipants_(depense.nombreParticipants_)
{
}

//Methode d'acces
/********************************************************
* Nom de fonction :getNombreParticipants)
* Description : retourne la veleur de nombreParticipants_
* Param�tre: void
* Return : unsigned int nombreParticipants
*********************************************************/
unsigned int DepenseGroupe::getNombreParticipants() const
{
	return nombreParticipants_;
}
/********************************************************
* Nom de fonction :getMontantPersonnel()
* Description : retourne la veleur de totalParPersonne
* Param�tre: void
* Return : double totalParPersonne
*********************************************************/
double DepenseGroupe::getMontantPersonnel() const
{
	if (nombreParticipants_ == 0) {
		//cout << "Erreur, il n'y a pas de participants" << endl;
		return 0;
	}
	else{
		double totalParPersonne;
		totalParPersonne = (getMontant() / getNombreParticipants());
		return totalParPersonne;
	}
}
/********************************************************
* Nom de fonction :setNombreParticipants()
* Description : donne la valeur � nombreParticipants_
* Param�tre: unsigned int nombre
* Return : void
*********************************************************/
void DepenseGroupe::setNombreParticipants(unsigned int nombre)
{
	nombreParticipants_ = nombre;
}

//Methode d'affichage
/********************************************************
* Nom de fonction :operator<<
* Description : surcharge de l'op�rateur <<
* Param�tre: ostream & os, const DepenseGroupe & depense
* Return : os
*********************************************************/
ostream & operator<<(ostream & os, const DepenseGroupe & depense)
{
	// TODO: insert return statement here<
	os << "Depense du groupe est :" << static_cast<Depense>(depense) << "fait par : " << depense.getNombreParticipants()
		<< " personnes est de : " << depense.getMontantPersonnel() << " par personne." << endl;
	return os;
}
