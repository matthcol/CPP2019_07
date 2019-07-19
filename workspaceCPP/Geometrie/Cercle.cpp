/*
 * Cercle.cpp
 *
 *  Created on: 17 juil. 2019
 *      Author: AELION
 */
#include <sstream>
#include <cmath>
#include "Cercle.h"

const double Cercle::PI = 4*atan(1);

Cercle::Cercle(const string &nom,Point *centre, double rayon):
		Figure(nom), centre(centre), rayon(rayon) {
}

Cercle::~Cercle() {
	// TODO Auto-generated destructor stub
}

Point* Cercle::getCentre() const {
	return centre;
}

void Cercle::setCentre(Point *centre) {
	this->centre = centre;
}

double Cercle::getRayon() const {
	return rayon;
}

void Cercle::setRayon(double rayon) {
	this->rayon = rayon;
}

bool Cercle::contient(const Point &p) const  {
	return centre->distance(p) <= rayon;
	//return p.distance(*centre) <= rayon;
}

string Cercle::toString() const{
	ostringstream res;
	res << getNom() << "<" << centre << ";" << rayon << ">";
	return res.str();
}


double Cercle::perimetre() const {
	return 2*PI*rayon;
}

double Cercle::aire() const {
	return PI*pow(rayon,2);
}

void Cercle::translater(double deltaX, double deltaY) {
	centre->translater(deltaX, deltaY);
}

