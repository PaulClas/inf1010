/********************************************
* Titre: utilisateurPremium.cpp
* Date : 22 octobre 2018
* Auteur : Paul Clas
* Description : Implémentation de la classe utilisateurPremium
********************************************/
#include "utilisateurPremium.h"

/********************************************************
* Nom de fonction : UtilisateurPremium
* Description : constructeur par default
* Paramètre: void
* Return : void
*********************************************************/
UtilisateurPremium::UtilisateurPremium(const string & nom) : 
	Utilisateur(nom, Premium), joursRestants_(30), taux_(0.5)
{
}

/********************************************************
* Nom de fonction : UtilisateurPremium
* Description : constructeur par copie
* Paramètre: void
* Return : void
*********************************************************/
UtilisateurPremium::UtilisateurPremium(const UtilisateurPremium & utilisateur):
	Utilisateur(utilisateur), joursRestants_(utilisateur.joursRestants_), taux_(utilisateur.taux_)
{
}

/********************************************************
* Nom de fonction : getJoursRestants()
* Description : retourne la valeur joursRestants_
* Paramètre: void
* Return : unsigned int
*********************************************************/
unsigned int UtilisateurPremium::getJoursRestants() const
{
	return joursRestants_;
}

/********************************************************
* Nom de fonction : getTaux()
* Description : retourne la valeur taux_
* Paramètre: void
* Return : double
*********************************************************/
double UtilisateurPremium::getTaux() const
{
	return taux_;
}

/********************************************************
* Nom de fonction : setJoursRestants()
* Description : donne la valeur à joursRestants_
* Paramètre: unisgned in joursRestants
* Return : void
*********************************************************/
void UtilisateurPremium::setJoursRestants(unsigned int joursRestants)
{
	joursRestants_ = joursRestants;
}

/********************************************************
* Nom de fonction : calculterTaux()
* Description : calcul le taux d'interet pour PolyCOunt
* Paramètre: void
* Return : void
*********************************************************/
void UtilisateurPremium::calculerTaux()
{
	//init
	taux_ = 0.5;
	//diminution de 1%
	taux_ -= (double)(0.1 * (getNombreDepenses() / 2));
	if (taux_ < 0.0)
		taux_ = 0.0;
}

/********************************************************
* Nom de fonction : operator=
* Description : surcharge de l'operateur =
* Paramètre: Utilisateur * utilisateur
* Return : Utilisateur* utilisateur
*********************************************************/
UtilisateurPremium & UtilisateurPremium::operator=(Utilisateur * utilisateur)
{
	// TODO: insert return statement here
	(*this).Utilisateur::operator=(*utilisateur);
	//joursRestants_ = utilisateur->joursRestants;
	//taux_= utilisateur->taux;
	return *this;
}

/********************************************************
* Nom de fonction : operator<<
* Description : surcharge de l'operateur <<
* Paramètre: ostream & os, const UtilisateurPremium & utilisateur
* Return : os
*********************************************************/
ostream & operator<<(ostream & os, const UtilisateurPremium & utilisateur)
{
	// TODO: insert return statement here
	os << static_cast<Utilisateur>(utilisateur) << ends << ends << "Abonnement expire dans : " 
		<< utilisateur.joursRestants_ << " jours. " << ends << ends<< "Taux d'interet finale de : " << utilisateur.taux_ << " %"<< endl;
	return os;
}
