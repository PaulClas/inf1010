#include "depenseGroupe.h"

DepenseGroupe::DepenseGroupe(const string & nom, double montant, const string & lieu): Depense(nom, montant, lieu, groupe), nombreParticipants_(0)
{
}

DepenseGroupe::DepenseGroupe(const DepenseGroupe & depense): Depense(depense), nombreParticipants_(depense.nombreParticipants_)
{
}

unsigned int DepenseGroupe::getNombreParticipants() const
{
	return nombreParticipants_;
}

double DepenseGroupe::getMontantPersonnel() const
{
	if (nombreParticipants_ == 0) {
		//cout << "Erreur, il n'y a pas de participants" << endl;
		return 0;
	}
	else{
		double totalParPersonne;
		totalParPersonne = (getMontant() / getNombreParticipants());
		return totalParPersonne;
	}
}

void DepenseGroupe::setNombreParticipants(unsigned int nombre)
{
	nombreParticipants_ = nombre;
}

ostream & operator<<(ostream & os, const DepenseGroupe & depense)
{
	// TODO: insert return statement here<
	os << "Depense du groupe est :" << static_cast<Depense>(depense) << "fait par : " << depense.getNombreParticipants()
		<< " personnes est de : " << depense.getMontantPersonnel() << " par personne." << endl;
	return os;
}
