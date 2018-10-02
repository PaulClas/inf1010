/********************************************
* Titre: depense.cpp
* Date: 23 septembre 2018
* Auteur: Paul Clas
* Description: Implémentation de la classe depense
*******************************************/
#include "depense.h"
#include <iostream>

using namespace std;

/********************************************************
* Nom de fonction : Consctructeur par defaut
* Description : Consruit depense
* Paramètre : void
* Return : void
*********************************************************/
Depense::Depense()
{
	titre_ = "unknown";
	montant_ = 0;

}

/********************************************************
* Nom de fonction : Consctructeur par paramètre
* Description : Consruit depense
* Paramètre : titre_, mntant_
* Return : void
*********************************************************/
Depense::Depense(string titre, double montant)
{
	titre_ = titre;
	montant_ = montant;
}

/********************************************************
* Nom de fonction : getTitre()
* Description : donne le titre de la depense
* Paramètre : void
* Return : titre_
*********************************************************/
string Depense::getTitre() const
{
	return titre_;
}

/********************************************************
* Nom de fonction : getMontant()
* Description : donne le montant de la depense
* Paramètre : void
* Return : montant_
*********************************************************/
double Depense::getMontant() const
{
	return montant_;
}

/********************************************************
* Nom de fonction : setTitre()
* Description : donne la valeur en param de la fonction 
a titre_
* Paramètre : string& titre
* Return : void
*********************************************************/
void Depense::setTitre(string & titre)
{
	titre_ = titre;
}

/********************************************************
* Nom de fonction : setMontant()
* Description : donne la valeur en param de la fonction
a montant_
* Paramètre : double montant
* Return : void
*********************************************************/
void Depense::setMontant(double montant)
{
	montant_ = montant;
}

/********************************************************
* Nom de fonction : afficherDepense()
* Description : affiche la depense
* Paramètre : void
* Return : void
*********************************************************/
void Depense::afficherDepense() const
{
	cout << "Depense: "<< titre_ << ends<< "de montant: " << montant_ << "$." << endl;
}
