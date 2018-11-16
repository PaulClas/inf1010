/********************************************
* Titre: utilisateurRegulier.cpp
* Date : 22 octobre 2018
* Auteur : Paul Clas
* Description : Impl�mentation de la classe utilisateurRegulier
********************************************/

#include "utilisateurRegulier.h"
/********************************************************
* Nom de fonction : UtilisateurRegulier
* Description : constructeur par param
* Param�tre: void
* Return : void
*********************************************************/
UtilisateurRegulier::UtilisateurRegulier(const string & nom): Utilisateur(nom), estGroupe_(false)
{
}

/********************************************************
* Nom de fonction : UtilisateurRegulier
* Description : constructeur par copie
* Param�tre: void
* Return : void
*********************************************************/
UtilisateurRegulier::UtilisateurRegulier(const UtilisateurRegulier & utilisateur): Utilisateur(utilisateur), estGroupe_(utilisateur.estGroupe_)
{
}

/********************************************************
* Nom de fonction : estGroupe()
* Description : retourne estGroupe-
* Param�tre: void
* Return : bool est GRoupe_
*********************************************************/
bool UtilisateurRegulier::estGroupe() const
{
	return estGroupe_;
}

/********************************************************
* Nom de fonction : setEtatGroupe()
* Description : met l'etat dans estGroupe
* Param�tre: bool etat
* Return : void
*********************************************************/
void UtilisateurRegulier::setEtatGroupe(bool etat)
{
	estGroupe_ = etat;
}

/********************************************************
* Nom de fonction : operator=
* Description : surcharge de l'operateur =
* Param�tre: Utilisateur* utilisateur
* Return : UtilisateurRegulier
*********************************************************/
UtilisateurRegulier & UtilisateurRegulier::operator=(Utilisateur * utilisateur)
{
	// TODO: insert return statement here
	(*this).Utilisateur::operator=(*utilisateur);
	return *this;
}

/********************************************************
* Nom de fonction : operator<<
* Description : surcharge de l'operateur <<
* Param�tre: ostream & os, const UtilisateurRegulier & utilisateur
* Return : os
*********************************************************/
ostream & operator<<(ostream & os, const UtilisateurRegulier & utilisateur)
{
	os << static_cast<Utilisateur> (utilisateur);
	os << "Utilisateur est dans le groupe ?: " << ends;
	if (utilisateur.estGroupe_) {
		os << " Oui, il esgt dans le groupe ";
	}
	else {
		os << "Non, il n'est pas dans le groupe ";
	}
	return os;
}
