/********************************************************
* Titre: TP1
* Date: 23 septembre 2018
* Auteur: Paul Clas (1846912)
*********************************************************/

/*******************************************************
Reponses aux questions:

1. Quel est le lien (agrégation ou composition) entre les classes Groupe et Transfert ? 
Dans ce cas, l’objet Transfert est une agregation de l’objet Groupe. Cette relation s’agit
de agregation puisque l’objet Transfert peut continuer d’exister même si l’objet Groupe est détruit. 
Un autre indice qui nous indique que cette relation est de l’agrégation est l’utilisation de pointeur.


2. Quel effet aura une méthode si elle a un const ?
Une méthode const indique au compilateur qu'à l'intérieur de cette méthode 
on ne doit pas modifier l'état de l'objet.

********************************************************/
#include <iostream>
#include "groupe.h"
#include "depense.h"
#include "transfert.h"
#include "utilisateur.h"

using namespace std; 

int main(int argc, const char * argv[]) {
    cout << "\t \tBienvenue sur PolyCount " << endl << " *****************************************" << endl;
	
    // Creer un evenement pour  6 depenses et 4 utilisateurs.
	string nomEvemenent = "Evenement 1";
	Groupe groupe(nomEvemenent, 6, 4);
	groupe.afficherGroupe();


	// Creer 5 utlisateurs.
	const int NBUTILISATEURS = 5;
	string nom1, nom2, nom3, nom4, nom5;
	nom1 = "Mario";
	nom2 = "Luigi";
	nom3 = "Bowser";
	nom4 = "Peach";
	nom5 = "Toad";
	Utilisateur** utilisateur;
	utilisateur = new Utilisateur*[NBUTILISATEURS];
	utilisateur[0] = new Utilisateur(nom1);
	utilisateur[1] = new Utilisateur(nom2);
	utilisateur[2] = new Utilisateur(nom3);
	utilisateur[3] = new Utilisateur(nom4);
	utilisateur[4] = new Utilisateur(nom5);


    //Creer 7 dépenses.
	const int NBDEPENSES = 7;
	Depense** depense;
	depense = new Depense*[NBDEPENSES];
	depense[0] = new Depense("Champignons", 5);
	depense[1] = new Depense("Chateau", 30);
	depense[2] = new Depense("Moto", 3);
	depense[3] = new Depense("uniforme de plombier", 10);
	depense[4] = new Depense("robe de princesse 1", 10);
	depense[5] = new Depense("Chapeau de Toad", 4);
	depense[6] = new Depense("Outil de plombier", 6);

	utilisateur[0]->ajouterDepense(depense[0]);
	utilisateur[2]->ajouterDepense(depense[1]);
	utilisateur[1]->ajouterDepense(depense[2]);
	utilisateur[0]->ajouterDepense(depense[3]);
	utilisateur[3]->ajouterDepense(depense[4]);
	utilisateur[4]->ajouterDepense(depense[5]);
	utilisateur[0]->ajouterDepense(depense[6]);
    
    //ajouter les utilisateurs a l'evenement
	
	for (int i = 0; i < 5; i++) {
		groupe.ajouterUtilisateur(utilisateur[i]);
	}
	
    //ajouter les depenses a l'evenement
	groupe.ajouterDepense(depense[0], utilisateur[0]);
	groupe.ajouterDepense(depense[1], utilisateur[2]);
	groupe.ajouterDepense(depense[2], utilisateur[1]);
	groupe.ajouterDepense(depense[3], utilisateur[0]);
	groupe.ajouterDepense(depense[4], utilisateur[3]);
	groupe.ajouterDepense(depense[5], utilisateur[4]);
	groupe.ajouterDepense(depense[6], utilisateur[0]);
	
    
    //calculer le total de l'evenement et de chaque utilisateur
	groupe.calculerTotalDepenses();
	for (int i = 0; i < 4; i++) {
		utilisateur[i]->calculerTotal();
	}
    //Afficher event
	groupe.afficherGroupe();
    
    //Equilibrer les comptes
	groupe.equilibrerComptes();

    //Afficher l'évenement
	groupe.afficherGroupe();

   
    //terminer le programme correctement
	delete[] utilisateur;
	delete[] depense;
	


}
