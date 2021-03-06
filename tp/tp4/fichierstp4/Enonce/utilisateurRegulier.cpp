/********************************************
* Titre: Travail pratique #4 - utilisateurRegulier.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modification: Paul Clas 1846912
*******************************************/

#include "utilisateurRegulier.h"

UtilisateurRegulier::UtilisateurRegulier(const string & nom, MethodePaiement methodePaiement, const string & courriel, const string & idPaypal)
	: Utilisateur(nom, methodePaiement, courriel, idPaypal), possedeGroupe_(false)
{}


bool UtilisateurRegulier::getPossedeGroupe() const {
	return possedeGroupe_;
}

void UtilisateurRegulier::setPossedeGroupe(bool possedeGroupe) {
	possedeGroupe_ = possedeGroupe;
}

void UtilisateurRegulier::print(ostream & os) const
{
	if (getPossedeGroupe() == false)
		os << "Utilisateur Regulier fait partie Groupe" << getNom() << ":" << ends << " Total  a payer:" << getTotalATransferer() << "( Balance " << getBalance() << " des frais)" << endl;
	else
		os << "Utilisateur Regulier ne fait PAS parti Groupe)" << getNom() << ":" << ends << " Total  a payer:" << getTotalATransferer() << "( Balance " << getBalance() << " des frais)" << endl;
	Utilisateur::print(os);
}
