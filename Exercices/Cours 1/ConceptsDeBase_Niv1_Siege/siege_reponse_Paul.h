#ifndef SIEGE_H
#define SIEGE_H

#include <iostream>
#include <string>

using namespace std;

class Siege {
public:
	Siege(); //constructeur par défaut
	Siege(int nbPersonnes, int nbPattes, string nomCommun);
	~Siege(); //destructeur

	//accesors
	int getnbPersonnes() const;
	int getnbPattes() const;
	string getnomCommun() const;


	//mutators
	void setnbPersonnes(int);
	void setnbPattes(int);
	void setnomCommun(string);

private:
	int nbPersonnes_;
	int nbPattes_;
	string nomCommun_;
};
#endif
