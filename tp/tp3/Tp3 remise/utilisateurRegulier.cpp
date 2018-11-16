#include "utilisateurRegulier.h"

UtilisateurRegulier::UtilisateurRegulier(const string & nom): Utilisateur(nom), estGroupe_(false)
{
}

UtilisateurRegulier::UtilisateurRegulier(const UtilisateurRegulier & utilisateur): Utilisateur(utilisateur), estGroupe_(utilisateur.estGroupe_)
{
}

bool UtilisateurRegulier::estGroupe() const
{
	return estGroupe_;
}

void UtilisateurRegulier::setEtatGroupe(bool etat)
{
	estGroupe_ = etat;
}

UtilisateurRegulier & UtilisateurRegulier::operator=(Utilisateur * utilisateur)
{
	// TODO: insert return statement here
	(*this).Utilisateur::operator=(*utilisateur);
	return *this;
}

ostream & operator<<(ostream & os, const UtilisateurRegulier & utilisateur)
{
	os << static_cast<Utilisateur> (utilisateur);
	os << "Utilisateur est dans le groupe ?: " << ends;
	if (utilisateur.estGroupe_) {
		os << " Oui, il esgt dans le groupe ";
	}
	else {
		os << "Non, il n'est pas dans le groupe ";
	}
	return os;
}
