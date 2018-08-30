#include <iostream>
#include <string>

#include "siege.h"

using namespace std;

int main() {
	int i = 1, nbPattes, nbPersonnes;
	string nomCommun;

	Siege siege1(1,2,"Paul");
	cout << "Halo" << endl;
	siege1.getnbPattes();
	siege1.getnbPersonnes();
	siege1.getnomCommun();
	cout << "__________" << endl;
	cout << "Inventaire de siege" << endl << "Entrer le nombre de pattes pour la chaise n" << i << " : " << endl;
	cin >> nbPattes;
	siege1.setnbPattes(nbPattes);
	cout << "Le nombre de pattes pour le siege est de " << siege1.getnbPattes() << " ." << endl;
	system("Pause");
	return 0;
	
}
