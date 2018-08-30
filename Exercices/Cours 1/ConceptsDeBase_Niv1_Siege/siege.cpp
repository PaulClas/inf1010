#include <iostream>
#include <string>
#include "siege.h"

using namespace std;

Siege::Siege()
{
	nbPersonnes_ = 1;
	nbPattes_ = 4;
	nomCommun_ = "Paul";

}

Siege::Siege(int nbPersonnes, int nbPattes, string nomCommun)
{
	nbPersonnes = 1;
	nbPattes = 4;
	nomCommun = "Paul";
}


Siege::~Siege()
{
}

int Siege::getnbPersonnes() const
{
	return nbPersonnes_;
}

int Siege::getnbPattes() const
{
	return nbPattes_;
}

string Siege::getnomCommun() const
{
	return nomCommun_;
}


void Siege::setnbPersonnes(int nbPersonnes)
{
	nbPersonnes_ = nbPersonnes;
}

void Siege::setnbPattes(int nbPattes)
{
	nbPattes_ = nbPattes;
}

void Siege::setnomCommun(string nomCommun)
{
	nomCommun_ = nomCommun;
}
