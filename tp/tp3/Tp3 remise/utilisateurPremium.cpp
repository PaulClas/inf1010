#include "utilisateurPremium.h"

UtilisateurPremium::UtilisateurPremium(const string & nom) : 
	Utilisateur(nom, Premium), joursRestants_(30), taux_(0.5)
{
}

UtilisateurPremium::UtilisateurPremium(const UtilisateurPremium & utilisateur):
	Utilisateur(utilisateur), joursRestants_(utilisateur.joursRestants_), taux_(utilisateur.taux_)
{
}

unsigned int UtilisateurPremium::getJoursRestants() const
{
	return joursRestants_;
}

double UtilisateurPremium::getTaux() const
{
	return taux_;
}

void UtilisateurPremium::setJoursRestants(unsigned int joursRestants)
{
	joursRestants_ = joursRestants;
}

void UtilisateurPremium::calculerTaux()
{
	//init
	taux_ = 0.5;
	//diminution de 1%
	taux_ -= (double)(0.1 * (getNombreDepenses() / 2));
	if (taux_ < 0.0)
		taux_ = 0.0;
}

UtilisateurPremium & UtilisateurPremium::operator=(Utilisateur * utilisateur)
{
	// TODO: insert return statement here
	(*this).Utilisateur::operator=(*utilisateur);
	//joursRestants_ = utilisateur->joursRestants;
	//taux_= utilisateur->taux;
	return *this;
}

ostream & operator<<(ostream & os, const UtilisateurPremium & utilisateur)
{
	// TODO: insert return statement here
	os << static_cast<Utilisateur>(utilisateur) << ends << ends << "Abonnement expire dans : " 
		<< utilisateur.joursRestants_ << " jours. " << ends << ends<< "Taux d'interet finale de : " << utilisateur.taux_ << " %"<< endl;
	return os;
}
