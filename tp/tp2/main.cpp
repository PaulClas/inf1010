/********************************************
* Titre: Travail pratique #2 - main.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
*******************************************
* MODIFICATION
* Titre: TP2 - main.cpp
* Date: 2 octobre
* Auteur: Paul Clas (1846912)
*********************************************************/

#include <iostream>
#include "depense.h";
#include "utilisateur.h"
#include  "transfert.h"
#include "groupe.h"

/**
*R�pondez aux questions ici :
* 1/Les op�rateurs d'assignation et le constructeur par copie sont tr�s similaire dans leur fonction d'initialiser
*	des variables � de nouvelle valeur en copiant les attributs et les m�thodes. L'utilit� d'un constructeur par copie
*	est de cr�er un objet comme une copie des attributs et m�thodes d'un objet qui peut ne pas �tre encore initialis�.
*	L'op�rateur = permet une assignation. L'op�rateur = est utile pour assigner � les donn�es d'une variable ou d'un objet
*	� une autre variable ou objet de m�me type deja existant.
*
* 2/Un constructeur par copie est utilis� pour initialiser un objet pr�c�d�ement non-initialis� provenant
*	des donn�es d'un autre objet. Un op�rateur = est utilis� pour copi� la valeur d'une donn�e ou objet pr�c�dement
*	initilis� provenant des donn�es d'une autre variable ou ojet.
**/

using namespace std;

int main() {

	cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************************" << endl;

	// Initialisation des depenses
	Depense* d1 = new Depense("d1", 12, "IGA");
	Depense* d2 = new Depense("d2", 11, "Provigo");
	Depense* d3 = new Depense("d3", 5, "Jean-drapeau");
	Depense* d4 = new Depense("d4", 23, "Vieux port");
	Depense* d5 = new Depense("d5", 17, "Metro");
	Depense* d6 = new Depense("d6", 29, "Desjardins");
	// Exemple d'utilisation du constructeur par copie et de l'operateur d'assignation
	Depense* d7 = new Depense(*d5);
	d7->setNom("d7");
	d7->setLieu("Maisonnee");

	Depense* d8 = new Depense();
	*d8 = *d1;
	d8->setNom("d8");
	d8->setLieu("Banque scotia");

	// Initialisation des utilisateurs
	Utilisateur* u1 = new Utilisateur("Martin");
	Utilisateur* u2 = new Utilisateur("Franklin");
	Utilisateur* u3 = new Utilisateur("Geraldine");
	Utilisateur* u4 = new Utilisateur("Bernard");

	//Exemple d'utilisation de l'operateur d'assignation
	Utilisateur* u5 = new Utilisateur();
	*u5 = *u1;
	u5->setNom("Christian");

	// Initialisation du groupe
	Groupe* groupe = new Groupe("vacances");

	// Ajout des utilisateurs et des depenses au groupe
	((((*groupe += u1) += u2) += u3) += u4) += u5;

	groupe->ajouterDepense(d1, u1).ajouterDepense(d2, u1).ajouterDepense(d3, u2).ajouterDepense(d4, u3).ajouterDepense(d5, u4)
		.ajouterDepense(d6, u5).ajouterDepense(d7, u3).ajouterDepense(d8, u4);
	cout << *groupe;
	// Equilibrage des comptes
	groupe->equilibrerComptes();
	cout << *groupe;

	// TODO: Terminez le programme correctement

	delete groupe;

	delete d1;
	delete d2;
	delete d3;
	delete d4;
	delete d5;
	delete d6;
	delete d7;

	delete u1;
	delete u2;
	delete u3;
	delete u4;
	delete u5;

	return 0;
}
