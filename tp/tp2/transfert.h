/********************************************
* Titre: Travail pratique #2 - transfert.h
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************
* MODIFICATION
* Titre: transfert.h
* Date : 8 octobre 2018
* Mofication : Paul Clas, 1846912
* ******************************************/

#ifndef TRANSFERT_H
#define TRANSFERT_H
#include "utilisateur.h"
#include <iostream>
#include <stdio.h>

class Transfert {
public:

	// Constructeurs
	Transfert();
	Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur_);

	// M�thodes d'acc�s
	Utilisateur* getExpediteur() const;
	Utilisateur* getReceveur() const;
	double getMontant() const;


	// M�thodes d'affichage
	void setMontant(double montant);
	void setExpediteur(Utilisateur* expediteur);
	void setReceveur(Utilisateur* receveur);

	// TODO: Remplacer par une surcharge de l'operateur <<
	//void afficherTransfert() const;
	friend ostream& operator<<(ostream &out, const Transfert& transfert);

private:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;


};

#endif