/********************************************
* Titre: groupe.cpp
* Date: 23 septembre 2018
* Auteur: Paul Clas
* Description: Implémentation de la classe groupe
*******************************************/
#include "groupe.h"
#include <iostream>

using namespace std;

/********************************************************
* Nom de fonction : Consctructeur par defaut
* Description : Consruit groupe
* Paramètre : void
* Return : void
*********************************************************/
Groupe::Groupe()
{
	nom_= "unknown";
	totalDepenses_ = 0;
	listeUtilisateurs_ = nullptr;
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	tailleTabUtilisateurs_=0;
	tailleTabDepenses_=0;
	listeDepenses_ = nullptr;
	comptes_ = nullptr;
	listeTransferts_=nullptr;
	nombreTransferts_ = 0;
}
/********************************************************
* Nom de fonction : Consctructeur par parametre
* Description : Consruit groupe
* Paramètre : nom_,tailleTabUtilisateur_, tailleTabDepenses_
* Return : void
*********************************************************/
Groupe::Groupe(string & nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs)
{
	nom_ = nom;
	tailleTabDepenses_ = tailleTabDepenses;
	tailleTabUtilisateurs_ = tailleTabUtilisateurs;
}
/********************************************************
* Nom de fonction : Destructeur
* Description : Destructeur groupe
* Paramètre : void
* Return : void
*********************************************************/
Groupe::~Groupe()
{
}

/********************************************************
* Nom de fonction : getNom()
* Description : donne le nom du groupe
* Paramètre : void
* Return : nom_
*********************************************************/
string Groupe::getNom() const
{
	return nom_;
}

/********************************************************
* Nom de fonction : getNombreDepenses()
* Description : donne le nombre de depenses total du 
groupe
* Paramètre : void
* Return : nombreDepenses_
*********************************************************/
unsigned int Groupe::getNombreDepenses() const
{
	return nombreDepenses_;
}

/********************************************************
* Nom de fonction : getTotal()
* Description : donne le nombre total des depenses du
groupe
* Paramètre : void
* Return : totalDepenses_
*********************************************************/
double Groupe::getTotal() const
{
	return totalDepenses_;
}

/********************************************************
* Nom de fonction : setNom()
* Description : met le nom en parametre a nom_ du groupe
* Paramètre : string& nom
* Return : void
*********************************************************/
void Groupe::setNom(string & nom)
{
	nom_ = nom;
}

/********************************************************
* Nom de fonction : ajouterDepense()
* Description : ajoute une depense avec un utilisateur associe
a la liste de depenses du groupe.
* Paramètre : Depense * uneDepense, Utilisateur * payePar
* Return : void
*********************************************************/
void Groupe::ajouterDepense(Depense * uneDepense, Utilisateur * payePar)
{
	//On initialise la listeDepense si elle ne l'ai deja pas fait
	if (listeDepenses_ == nullptr) {
		listeDepenses_ = new Depense*[tailleTabDepenses_];
		nombreDepenses_ = 0;
	}
	//on s'assure que l'utilisateur fait partie du groupe
	bool faitPartieGroupe = false;
	for (int i = 0; i < tailleTabUtilisateurs_; i++) {
		if (payePar->getNom() == listeUtilisateurs_[i]->getNom())
			faitPartieGroupe = true;
	}
	//le nombre de depenses depasse la taille du tab de depenses et on rejette donc la depense
	if(nombreDepenses_>= tailleTabDepenses_) {
		Depense** temporaire = new Depense*[tailleTabDepenses_++];
		for (int i = 0; i < nombreDepenses_; i++) {
			temporaire[i] = listeDepenses_[i];
		} 
		delete[] listeDepenses_;
		listeDepenses_ = temporaire;
	}
	//on accepte la depense
	if (nombreDepenses_ < tailleTabDepenses_ && faitPartieGroupe ==true) {
		listeDepenses_[nombreDepenses_] = new Depense(payePar->getNom(), uneDepense->getMontant());
		nombreDepenses_++;
	}
	// on rejete la depense
	if (faitPartieGroupe == false) {
		cout << "La depense ne peut etre ajouter car l'utilisateur " << payePar->getNom() << " ne fait pas partie du groupe" << endl;
	}
	
	
}
/********************************************************
* Nom de fonction : ajouterUtilisateur()
* Description : ajoute un utilisateur a la listeUtilisateurs du groupe
* Paramètre : Utilisateur * unUtilisateur
* Return : void
*********************************************************/
void Groupe::ajouterUtilisateur(Utilisateur * unUtilisateur)
{
	//On initialise la listeUtilisateurs si elle ne l'ai deja pas fait
	if (listeUtilisateurs_ == nullptr) {
		listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
		nombreUtilisateurs_ = 0;
	}
	
	// Le nombre d'utilisateur ajouter est superieur a nombre de la tailleTabUtilisateurs. On rejette l'utilisateur
	if (nombreUtilisateurs_ >= tailleTabUtilisateurs_) {
		Utilisateur** temporaire = new Utilisateur*[tailleTabUtilisateurs_++];
		for (int i = 0; i < tailleTabUtilisateurs_; i++) {
			temporaire[i] = listeUtilisateurs_[i];
		}
		delete[] listeUtilisateurs_;
		listeUtilisateurs_ = temporaire;
	}
	//On accepte l'utilisateur dans le groupe
	if (nombreUtilisateurs_ < tailleTabUtilisateurs_) {
		listeUtilisateurs_[nombreUtilisateurs_] = new Utilisateur(unUtilisateur[0]);
		nombreUtilisateurs_++;
	}
}
/********************************************************
* Nom de fonction : calculerTotalDepenses()
* Description : calcul le total de depenses du groupe
* Paramètre : void
* Return : void
*********************************************************/
void Groupe::calculerTotalDepenses()
{
	totalDepenses_ = 0;
	for (int i = 0; i < tailleTabDepenses_; i++) {
		//listeUtilisateurs_[i]->calculerTotal();
		//totalDepenses_ += listeUtilisateurs_[i]->getTotal();
		totalDepenses_ +=listeDepenses_[i]->getMontant();
	}
}
/********************************************************
* Nom de fonction : equilibrerComptes()
* Description : equilibre les depenses du groupe. La fonction procede en 3 etapes:
1. Créer une listeEquilibrer qui va comprendre les comptes de chaques utilisateur
2. Ordonne les comptes pour mettre celui qui doit le plus en bas du tableau et celui
qui a depenser le plus en haut du tableau. 
3. Prends l'utilisateur qui a le moins depenser (montant le plus petit) et verse le montant a celui 
qui a depenser le plus (montant le plus grand). Procède ainsi jusqu'à ce que le compte de l'utilisateur qui
a le moins depenser et vide ou si celui qui a depenser le plus a été remboursé. Va ensuite faire un cycle
pour chercher le prochain utilisateur qui a le moins depenser et va chercher celui a qui a le plus 
depenser pour continuer les transferts
* Paramètre : void
* Return : void
*********************************************************/
void Groupe::equilibrerComptes()
{
//On initialise les listes 
	double montantequilibre = totalDepenses_ / tailleTabUtilisateurs_;
	cout << "Le montant équilibré est de " << montantequilibre << endl;
	comptes_ = new double[tailleTabUtilisateurs_];
	Depense** listeEquilibrer;
	listeEquilibrer = new Depense*[tailleTabUtilisateurs_];
	const int MAXTRANSFERT = 20;
	

	for (int i = 0; i < tailleTabUtilisateurs_; i++) {
		listeUtilisateurs_[i]->calculerTotal();
		comptes_[i] = (listeUtilisateurs_[i]->getTotal() - montantequilibre);
		//double temp = (listeUtilisateurs_[i]->getTotal() - montantequilibre);
		//listeEquilibrer[i] = new Depense(listeUtilisateurs_[i]->getNom(), temp);
		listeEquilibrer[i] = new Depense(listeUtilisateurs_[i]->getNom(), comptes_[i]);
		}
//On Ordonne le tableau de listeEquilibrer et le tableau de listeUtilisateur
	Depense *temp = nullptr;
	Utilisateur *utilisateurTemporaire = nullptr;
	for (int i = 0; i < tailleTabUtilisateurs_; i++) {
		for (int j = 0; j < tailleTabUtilisateurs_; j++) {
			if (listeEquilibrer[i]->getMontant() >= listeEquilibrer[j]->getMontant()) {
				temp = listeEquilibrer[i];
				listeEquilibrer[i] = listeEquilibrer[j];
				listeEquilibrer[j] = temp;
			}
			if (listeUtilisateurs_[i]->getTotal() >= listeUtilisateurs_[j]->getTotal()) {
				utilisateurTemporaire = listeUtilisateurs_[i];
				listeUtilisateurs_[i] = listeUtilisateurs_[j];
				listeUtilisateurs_[j] = utilisateurTemporaire;
			}
		}
	}
	cout << "Comptes des Utilisateurs avant transfert de fonds" << endl;
	for(int i = 0; i<tailleTabUtilisateurs_;i++){
		comptes_[i] = (listeUtilisateurs_[i]->getTotal() - montantequilibre);
		cout << "Comptes: " << i << " soit " << listeUtilisateurs_[i]->getNom() << " est de " << comptes_[i] << "$" << endl;
	}
	cout << endl << endl;
	//On equilibre les comptes ici en utilisant le transfert.
	listeTransferts_ = new Transfert*[MAXTRANSFERT];
	double temporaire;
	nombreTransferts_ = 0;
	int tailleMax = tailleTabUtilisateurs_-1;
	//Faire une boucle for, puis while et for pour reduire a 0 le premier rank du tableau, puis seulement apres passer au deuxieme,
	// puis au troisieme en utilisant les rank du tableau les plus bas. Algorithme le plus rapide trouver au 23 septembre 2018
	for (int i = 0; i < tailleTabUtilisateurs_; i++) {
		int j = tailleMax;
		while (listeEquilibrer[i]->getMontant() != 0) {
			temporaire = listeEquilibrer[i]->getMontant() + listeEquilibrer[j]->getMontant();
			if (temporaire == 0 && listeEquilibrer[j]->getMontant() != 0) {
				listeTransferts_[nombreTransferts_] = new Transfert((-1)*listeEquilibrer[j]->getMontant(), listeUtilisateurs_[j], listeUtilisateurs_[i]);
				listeEquilibrer[i]->setMontant(0);
				listeEquilibrer[j]->setMontant(0);
				comptes_[i] = listeEquilibrer[i]->getMontant();
				comptes_[j] = listeEquilibrer[j]->getMontant();
				nombreTransferts_++;
			}
			if (temporaire > 0 && listeEquilibrer[j]->getMontant() != 0) {
				listeTransferts_[nombreTransferts_] = new Transfert((-1)*listeEquilibrer[j]->getMontant(), listeUtilisateurs_[j], listeUtilisateurs_[i]);
				listeEquilibrer[j]->setMontant(0);
				comptes_[j] = listeEquilibrer[j]->getMontant();
				listeEquilibrer[i]->setMontant(temporaire);
				comptes_[i] = listeEquilibrer[i]->getMontant();
				nombreTransferts_++;
			}
			if (temporaire < 0 && listeEquilibrer[j]->getMontant() != 0) {
				listeTransferts_[nombreTransferts_] = new Transfert((-1)*(listeEquilibrer[j]->getMontant() - temporaire), listeUtilisateurs_[j], listeUtilisateurs_[i]);
				listeEquilibrer[j]->setMontant(temporaire);
				listeEquilibrer[i]->setMontant(0);
				comptes_[i] = listeEquilibrer[i]->getMontant();
				comptes_[j] = listeEquilibrer[j]->getMontant();
				nombreTransferts_++;
			}
			j--;
		}
	}
}
/********************************************************
* Nom de fonction : afficherGroupe()
* Description : on affiche le Groupe
* Paramètre : void
* Return : void
*********************************************************/
void Groupe::afficherGroupe() const
{
	cout << endl << "Groupe: " << nom_ << endl
		<< "Nombre de Dépenses ajouter: " << nombreDepenses_ << ends
		<< "Total des Depenses du groupe: " << totalDepenses_ << ends
		<< "Total d'utilisateur: " << tailleTabUtilisateurs_ << endl << endl;
	if (nombreUtilisateurs_ == 0) {
		cout << "Aucun utilisateur ajouté pour l'instant" << endl;
	}
	else for (int i = 0; i < tailleTabUtilisateurs_; i++) {
		cout << "Utilisateur n*" << i << " :" << endl;
		listeUtilisateurs_[i]->calculerTotal();
		listeUtilisateurs_[i]->afficherUtilisateur();
		cout<< endl;
	}
	cout << endl << endl;
	if (nombreDepenses_ == 0) {
		cout << "Aucune depense ajouté pour l'instant" << endl;
	}
	else for (int i = 0; i < tailleTabDepenses_; i++) {
		listeDepenses_[i]->afficherDepense();
	}
	cout << endl << endl;
	cout << "Nombre de Transferts " << nombreTransferts_ << endl;
	if (listeTransferts_ != nullptr) {
		for (int i = 0; i < nombreTransferts_; i++) {
			listeTransferts_[i]->afficherTransfert();
		}
	}
	cout << endl << endl;
	if (comptes_ != nullptr) {
		cout << "Les comptes" << endl;
		for (int i=0; i < tailleTabUtilisateurs_; i++) {
			cout << "Comptes: " << i << " soit " << listeUtilisateurs_[i]->getNom() << " est de " << comptes_[i] << "$" << endl;
		}
	}
	cout << endl << endl;
}


