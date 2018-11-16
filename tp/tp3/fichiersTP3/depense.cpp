/********************************************
* Titre: Travail pratique #2 - depense.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************
* MODIFICATION
* Titre: depense.cpp
* Date : 22 octobre 2018
* Auteur : Paul Clas
* Description : Impl�mentation de la classe depense
********************************************/

#include "depense.h"

// Constucteurs

/********************************************************
* Nom de fonction : Depense()
* Description : constructeur par default
* Param�tre: void
* Return : void
*********************************************************/
Depense::Depense(const string & nom, double montant, const string & lieu, TypeDepense type): nom_(nom), montant_(montant),
	lieu_(new string(lieu)), type_(type)
{

}
/********************************************************
* Nom de fonction : Depense()
* Description : constructeur par copie
* Param�tre: void
* Return : void
*********************************************************/
Depense::Depense(const Depense & depense): nom_(depense.nom_), montant_(depense.montant_),
	lieu_(new string(*depense.lieu_)), type_(depense.type_)
{
}
/********************************************************
* Nom de fonction : ~Depense()
* Description : destructeur
* Param�tre: void
* Return : void
*********************************************************/
Depense::~Depense()
{	
	if (lieu_ != nullptr)
		delete lieu_;
}

// Methodes d'acces
/********************************************************
* Nom de fonction :getNom()
* Description : retourne la veleur de nom_
* Param�tre: void
* Return : string nom_
*********************************************************/
string Depense::getNom() const {
	return nom_;
}
/********************************************************
* Nom de fonction :getMontant()
* Description : retourne la veleur de montant_
* Param�tre: void
* Return : double montant_
*********************************************************/
double Depense::getMontant() const {
	return montant_;
}
/********************************************************
* Nom de fonction :getLieu()
* Description : retourne la veleur de lieu_
* Param�tre: void
* Return : string* lieu_
*********************************************************/
string* Depense::getLieu() const
{
	return lieu_;
}
/********************************************************
* Nom de fonction :getType()
* Description : retourne la veleur de type_
* Param�tre: void
* Return : TypeDepense type_
*********************************************************/
TypeDepense Depense::getType() const
{
	return type_;
}



// Methodes de modifications
/********************************************************
* Nom de fonction :setNom()
* Description : donne la valeur � nom_
* Param�tre: string& nom
* Return : void
*********************************************************/
void Depense::setNom(const string& nom) {
	nom_ = nom;
}
/********************************************************
* Nom de fonction :setMontant()
* Description : donne la valeur � montant_
* Param�tre: double
* Return : void
*********************************************************/
void Depense::setMontant(double montant) {
	montant_ = montant;
}
/********************************************************
* Nom de fonction :setLieu()
* Description : donne la valeur � lieu_
* Param�tre: string&
* Return : void
*********************************************************/
void Depense::setLieu(const string& nom)
{
	delete lieu_;
	lieu_ = new string(nom);
}

/********************************************************
* Nom de fonction :setType()
* Description : donne la valeur � type_
* Param�tre: TypeDepense
* Return : void
*********************************************************/
void Depense::setType(TypeDepense type) {
	type_ = type; 
}

/********************************************************
* Nom de fonction :operator=
* Description : Surcharge de l'op�rateur =
* Param�tre: Depense & depense
* Return : Depense&
*********************************************************/
Depense& Depense::operator=(const Depense & depense)
{
	if (this != &depense) {
		nom_ = depense.nom_;
		montant_ = depense.montant_;
		type_ = depense.type_;
		lieu_ = new string(*depense.lieu_);
		}
	return *this;
}

/********************************************************
* Nom de fonction :operator<<
* Description : Surcharge de l'op�rateur <<
* Param�tre: ostream & os, const Depense & depense
* Return : os
*********************************************************/
ostream & operator<<(ostream & os, const Depense & depense)
{
	// TODO: insert return statement here
	os << "Achat fait (a " << *depense.lieu_ << ") : " << depense.nom_ << " prix : " << depense.montant_;
	return os;
}
