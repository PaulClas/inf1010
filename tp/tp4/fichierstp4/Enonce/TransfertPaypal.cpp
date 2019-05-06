/********************************************
* Titre: Travail pratique #4 - TransfertPaypal.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modification: Paul Clas 1846912
*******************************************/

#include "transfertPaypal.h"

TransfertPaypal::TransfertPaypal(double montant, Utilisateur * expediteur, Utilisateur * receveur)
	: Transfert(montant, expediteur, receveur)
{
	id_ = expediteur->getIdPaypal();
}

string TransfertPaypal::getId() const
{
	return id_;
}

void TransfertPaypal::setId(string id)
{
	id_ = id;
}

double TransfertPaypal::getFraisTransfert() const
{
	if (dynamic_cast<UtilisateurPremium*>(getExpediteur()))
		return 0;
	else return (getMontant()*COMMISSION+FRAIS);
	
}

