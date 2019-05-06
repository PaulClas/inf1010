/****************************************************************************
 * Fichier: Point.h
 * Auteur: Georges Abou-Khalil
 * Date: 2 sept 2008
 * Mise a jour : 11 mai 2011
 * Description: Définition de la classe Point
 ****************************************************************************/

#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
using namespace std;

class Point3D
{
public:
	Point3D();
	Point3D(double x, double y, double z);

	//Destructeur
	~Point3D();

	// Methodes d'acces
	double getX();
	double getY();
	double getZ();
	void imprimer(Point3D point3d);

	// Methodes de modification
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	void move(Point3D point3d, double x, double y, double z);
	void reset(Point3D point3d);

private:
	double x_;
	double y_;
	double z_;
};

#endif // _POINT_H_
