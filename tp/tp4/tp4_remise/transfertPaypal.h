/********************************************
* Titre: Travail pratique #4 - transfertPaypal.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
* Modification: Paul Clas 1846912
*******************************************/

#pragma once

const double COMMISSION = 0.026;
const double FRAIS = 0.30;

#include "transfert.h"
#include "utilisateurPremium.h"


class TransfertPaypal : public Transfert {
public:
	// Constructeur
	// TODO: a modifier ? pour le type id?
	TransfertPaypal(double montant, Utilisateur* expediteur, Utilisateur* receveur);

	string getId() const;
	void setId(string id);

	// TODO
	virtual double getFraisTransfert() const ;

private:
	string id_;
};