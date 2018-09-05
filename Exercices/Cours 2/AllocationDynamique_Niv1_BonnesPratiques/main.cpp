/****************************************************************************
 * Fichier: main.cpp
 * Auteur: William Bussiere
 * Date: 2 juin 2011
 * Description: Exercice facile d'allocation dynamique 
 *				sur le theme des bonnes pratiques vis-a-vis des pointeurs.
 ****************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int* nbTerrains;
	int* nbCommerces;
	int* nbEspaces;

	nbTerrains = new int(24);
	nbCommerces = new int(31);
	nbEspaces = new int(NULL);

	*nbEspaces = *nbTerrains + *nbCommerces;
	cout << "Nombre d'espaces a vendre : " << *nbEspaces << endl;

	int* nbMaisons = new int(16);
	int* nbParcs = new int(28);
	*nbTerrains = *nbMaisons + *nbParcs;
	//nbTerrains = new int(*nbMaisons +* nbParcs) meme ligne que celle de dessus, fait
	// la meme chose
	cout << "Nombre de terrains a vendre : " << *nbTerrains << endl;

	*nbParcs -= 7;
	*nbTerrains = *nbMaisons + *nbParcs);
	cout << "Nombre de terrains a vendre : " << *nbTerrains << " dont " 
		 << *nbMaisons << " mainsons et " 
		 << *nbParcs << " parcs." <<endl;
	

	*nbEspaces = *nbTerrains + *nbCommerces;
	cout << "Nouveau nombre d'expaces : " << *nbEspaces << endl;;
	cout << endl;

	delete nbEspaces;
	delete nbMaisons;
	delete nbTerrains;
	delete nbParcs;
	delete nbCommerces;
	
	
	system("PAUSE");

	return 0;
}