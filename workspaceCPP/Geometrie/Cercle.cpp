/*
 * Cercle.cpp
 *
 *  Created on: 17 juil. 2019
 *      Author: AELION
 */
#include <sstream>
#include "Cercle.h"


Cercle::Cercle(Point *centre, double rayon):centre(centre), rayon(rayon) {
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

string Cercle::toString() const{
	ostringstream res;
	res << "Cercle<" << centre << ";" << rayon << ">";
	return res.str();
}

ostream& operator <<(ostream &out, const Cercle &cercle) {
	return out << cercle.toString();
}
