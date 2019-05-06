#include "Train.h"
#include "..\..\..\..\OneDrive\Documents\Polytechnique\Hiver 2018\INF1010\Exercices\Cours 1\ConceptsDeBase_Niv1_Train\Train.h"

Train::Train()
{
	vitesse_ = 0.0;
	nbPersonnesABord_ = 0;
	chauffeur_ = nullptr;
	etat_ = 0.0;
}

Train::~Train()
{
}

void Train::avancer(double vitesse)
{
	vitesse_ = vitesse;
}

void Train::arreter()
{
	vitesse_ = 0;
}

void Train::prendreTrain(Personne * personne)
{
	if (vitesse_ == 0) {
		nbPersonnesABord_ += 1;
	}

}

void Train::entretenir()
{
	if (vitesse_ != 0)
		freiner();
	etat_ = 0;

}

void Train::assignerChauffeur(Personne * chauffeur)
{
	chauffeur_ = chauffeur;
}

double Train::getVitesse() const
{
	return vitesse_;
}

int Train::getNbPersonnesABord() const
{
	return nbPersonnesABord_;
}

Personne * Train::getChauffeur() const
{
	return chauffeur_;
}

double Train::getEtat() const
{
	return etat_;
}

void Train::accelerer()
{
	vitesse_ += 10;
}

void Train::freiner()
{
	while (vitesse_ > 0) {
		vitesse_ -= 5;
	}
	vitesse_ = 0;
}
