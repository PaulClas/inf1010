/********************************************
* Titre: Travail pratique #4 - TransfertInterac.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modification: Paul Clas 1846912
*******************************************/

#include "transfertInterac.h"

TransfertInterac::TransfertInterac(double montant, Utilisateur* expediteur, Utilisateur* receveur)
	: Transfert(montant, expediteur, receveur)
{
	courriel_ = receveur->getCourriel();
}

string TransfertInterac::getCourriel() const
{
	return courriel_;
}

void TransfertInterac::setcourriel(string courriel)
{
	courriel_ = courriel;
}

double TransfertInterac::getFraisTransfert() const
{
	if (dynamic_cast<UtilisateurPremium*>(getExpediteur()))
		return 0;
	else return (FRAIS_TRANSFERT);
}
