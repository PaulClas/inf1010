#include "..\..\..\..\OneDrive\Documents\Polytechnique\Hiver 2018\INF1010\Exemples\ConceptDeBase_Point\Point3D.h"
#include <iostream>

using namespace std;

Point3D::Point3D()
{
	x_ = 0.0;
	y_ = 0.0;
	z_ = 0.0;
}

Point3D::Point3D(double x, double y, double z)
{
	x_ = x;
	y_ = y;
	z_ = z;
}

Point3D::~Point3D()
{

}

double Point3D::getX()
{
	return x_;
}

double Point3D::getY()
{
	return y_;
}

double Point3D::getZ()
{
	return z_;
}

void Point3D::imprimer(Point3D point3d)
{
	cout << "Les coordonnées du point sont: " << endl;
	cout << "X: " << point3d.x_ << endl;
	cout << "Y: " << point3d.y_ << endl;
	cout << "Z: " << point3d.z_ << endl;
}

void Point3D::setX(double x)
{
	x_ = x;
}

void Point3D::setY(double y)
{
	y_ = y;
}

void Point3D::setZ(double z)
{
	z_ = z;
}

void Point3D::move(Point3D point3d, double x, double y, double z)
{
	point3d.setX(x);
	point3d.setY(y);
	point3d.setZ(z);
}

void Point3D::reset(Point3D point3d)
{
	point3d.setX(0);
	point3d.setY(0);
	point3d.setZ(0);
}
