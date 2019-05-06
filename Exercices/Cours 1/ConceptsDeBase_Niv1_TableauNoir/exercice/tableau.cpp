#include "tableau.h"

using namespace std;

Tableau::Tableau()
{
	caracteres_ = "";
	salete_ = 0;
	saleteSeuil_ = 30;
}

Tableau::~Tableau()
{
}

string Tableau::getCaracteres() const
{
	return caracteres_;
}

int Tableau::getSalete() const
{
	return salete_;
}

int Tableau::getSaleteSeuil() const
{
	return saleteSeuil_;
}

void Tableau::ajouterCaracteres(string caracteres)
{
	caracteres_ += caracteres;
}

void Tableau::setSaleteSeuil(int seuil)
{
	saleteSeuil_ = seuil;
}

bool Tableau::estSale()
{
	if (salete_ >=saleteSeuil_)
		return true;
}

void Tableau::effacer()
{
	salir(caracteres_.size());
	caracteres_.clear();
}

void Tableau::laver()
{
	salete_ = 0;
	caracteres_.clear();
}

void Tableau::salir(unsigned int nbCaracteres)
{
	salete_ += (nbCaracteres/ 2) + 1;
}
