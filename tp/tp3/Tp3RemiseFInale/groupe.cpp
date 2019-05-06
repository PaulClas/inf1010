/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
******************************************
* MODIFICATION
* Titre: groupe.cpp
* Date : 22 octobre 2018
* Auteur : Paul Clas
* Description : Implémentation de la classe groupe.cpp
********************************************/

#include "groupe.h"

// Constructeurs
/********************************************************
* Nom de fonction : Groupe()
* Description : constructeur par default
* Paramètre: void
* Return : void
*********************************************************/
Groupe::Groupe(): nom_(""), totalDepenses_(0.0) {
	//nom_ = ""; 
}
/********************************************************
* Nom de fonction : Groupe()
* Description : constructeur par paramètre
* Paramètre: const string& nom
* Return : void
*********************************************************/
Groupe::Groupe(const string& nom) : nom_(nom), totalDepenses_(0.0){
}

/********************************************************
* Nom de fonction : ~Groupe()
* Description : destructeur
* Paramètre: void
* Return : void
*********************************************************/
Groupe::~Groupe() {
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
		transferts_[i] = nullptr;
	}
	for (int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
}


// Methodes d'acces
/********************************************************
* Nom de fonction : getNom()
* Description : retourne le nom_
* Paramètre: void
* Return : string nom_
*********************************************************/
string Groupe::getNom() const {
	return nom_;
}
/********************************************************
* Nom de fonction : getDepense()
* Description : retourne le depense_
* Paramètre: void
* Return :vector<DepenseGroupe*> depenses_
*********************************************************/
vector<DepenseGroupe*> Groupe::getDepenses() const
{
	return depenses_;
}
/********************************************************
* Nom de fonction : getUtilisateurs()
* Description : retourne utilisateur_
* Paramètre: void
* Return :vector<DepenseGroupe*> depenses_
*********************************************************/
vector<Utilisateur*> Groupe::getUtilisateurs() const
{
	return utilisateurs_;
}
/********************************************************
* Nom de fonction : getTransferts()
* Description : retourne transferts_
* Paramètre: void
* Return :vector<Transfert*>
*********************************************************/
vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

/********************************************************
* Nom de fonction : getTotalDepenses()
* Description : retourne totalDepenses_
* Paramètre: void
* Return :double totalDepenses_
*********************************************************/
double Groupe::getTotalDepenses() const {

	return totalDepenses_;
}

// Methodes de modifications
/********************************************************
* Nom de fonction : setNom()
* Description : met la valeur de nom dans nom_
* Paramètre: const string& nom
* Return : void
*********************************************************/
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
/********************************************************
* Nom de fonction : ajouterDepense()
* Description : ajoute une Depense au groupe
* Paramètre: Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour
* Return : void
*********************************************************/
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour)
{
	int compteur = 0;
	bool faitPartiduGroupe = false;
	
	int nombrePaye = 0;

	for (int i = 0; i < utilisateurs_.size(); i++)
	{
		//faitPartiduGroupe = true;
		//nombrePaye = i;
		if (payePar->getNom() == utilisateurs_[i]->getNom())
		{
			faitPartiduGroupe = true;
			nombrePaye= i;
		}
		for (unsigned int j = 0; j < payePour.size(); j++)
		{
			if (utilisateurs_[i]->getNom() == payePour[j]->getNom())
				compteur++;
		}
	}


	if (faitPartiduGroupe && compteur == payePour.size() && depense->getType() == groupe)
	{
		DepenseGroupe *depenseDuGroupe = static_cast<DepenseGroupe *>(depense);
		depenseDuGroupe->setNombreParticipants((int) payePour.size() + 1);
		//comptes_[nombrePaye] += (depenseDuGroupe->getMontant() - depenseDuGroupe->getMontantPersonnel());

		*utilisateurs_[nombrePaye] += depenseDuGroupe;
		comptes_[nombrePaye] += (depenseDuGroupe->getMontant() - depenseDuGroupe->getMontantPersonnel());

		for (unsigned int i = 0; i < utilisateurs_.size(); i++)
		{
			for (unsigned int j = 0; j < payePour.size(); j++)
			{
				if (utilisateurs_[i]->getNom() == payePour[j]->getNom())
				{
					*utilisateurs_[i] += depenseDuGroupe;
					comptes_[i] -= depenseDuGroupe->getMontantPersonnel();
				}
			}
			if (utilisateurs_[i]->getType() == Premium)
				static_cast<UtilisateurPremium *>(utilisateurs_[i])->calculerTaux();
		}

		/*for (unsigned int i = 0; i < utilisateurs_.size(); i++)
		{
			if (utilisateurs_[i]->getType() == Premium)
				static_cast<UtilisateurPremium *>(utilisateurs_[i])->calculerTaux();
		}
		*/

		depenses_.push_back(new DepenseGroupe(*depenseDuGroupe));
		return *this;
	}
	else
	{
		//A modifier
		cout << "Erreur: Vous tentez d'ajouter une depense individuellle [...]dans le groupe." << endl;
		return *this;
	}
	
}

/********************************************************
* Nom de fonction : operator+=
* Description : surcharge de l'operateur +=
* Paramètre: Utilisatur* utilisateur
* Return : void
*********************************************************/
Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	if (utilisateur->getType() == Regulier)
	{
		if (static_cast<UtilisateurRegulier *>(utilisateur)->estGroupe()){
			cout << "Erreur: l'utilisateur " << utilisateur->getNom() 
				<< " n'est pas souscrit à un abonnement premium, et est deja groupe." << endl;
		}else{
			static_cast<UtilisateurRegulier *>(utilisateur)->setEtatGroupe(true);
			utilisateurs_.push_back(utilisateur);
			comptes_.push_back(0.0);
		}
	}

	else if (static_cast<UtilisateurPremium *>(utilisateur)->getType() == Premium)
	{
		if (static_cast<UtilisateurPremium *>(utilisateur)->getJoursRestants() == 0){
			cout << "Erreur: l'utilisateur " << utilisateur->getNom() 
				<< " doit renouveler son abonenement premium." << endl;
		}else{
			utilisateurs_.push_back(utilisateur);
			comptes_.push_back(0.0);
		}
	}
	return *this;

}
/********************************************************
* Nom de fonction : equilibrerCOmptes()
* Description : equilibre les comptes des utilisateurs du groupe
* Paramètre: void
* Return : void
*********************************************************/
void Groupe::equilibrerComptes() {
	
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
	
		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
			

		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}
	
}
/********************************************************
* Nom de fonction : calculerTotalDepense()
* Description : calcul total des depenses du groupe
* Paramètre: void
* Return : void
*********************************************************/
void Groupe::calculerTotalDepense() {
	for (int i = 0; i < depenses_.size(); i++) {
		totalDepenses_ += depenses_[i]->getMontant();
		//utilisateurs_[i]->calculerTotalDepenses();

	}
	//double moyenne = getTotalDepenses() / utilisateurs_.size();
	for (int i = 0; i < utilisateurs_.size(); i++) {
		utilisateurs_[i]->calculerTotalDepenses();
	}




}

// Methode d'affichage
/********************************************************
* Nom de fonction : operator<<
* Description : surcharge de l'operateur <<
* Paramètre: ostream& os, const Groupe& groupe
* Return : os
*********************************************************/
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "L'evenement : " << groupe.nom_ << " a coute un total de " << groupe.getTotalDepenses() << " $ ." << endl
		<< ends << ends << ends << ends <<"Utilisateurs et toutes leurs depenses: " << endl;
	for (int i = 0; i < groupe.utilisateurs_.size(); i++){
		os << ends << ends << ends << ends << ends << *(groupe.utilisateurs_[i]) << endl;
		if (groupe.utilisateurs_[i]->getType() == Premium)
			os << "( taux final de : " << static_cast<UtilisateurPremium *>(groupe.utilisateurs_[i])->getTaux()*10 << "% )" << endl;
	}
	if (groupe.transferts_.size() != 0){
		os << "Les transferts suivants ont ete realises pour equilibrer  : " << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++){
			os << ends << ends << ends << ends << ends << *groupe.transferts_[i] << endl;
		}
	}
	return os;
	
}
