/*
 * PointPondere.cpp
 *
 *  Created on: 17 juil. 2019
 *      Author: AELION
 */

#include <sstream>
#include <iostream>
#include "PointPondere.h"

PointPondere::PointPondere():Point(), poids(1.0) {
	clog << "PointPondéré créé avec 0 paramètre : " << *this << endl;
}

PointPondere::PointPondere(const string &nom, double x, double y,
		double poids):Point(nom,x,y), poids(poids) {
	clog << "PointPondéré créé avec 4 paramètres : " << *this << endl;
}

PointPondere::~PointPondere() {
	clog << "détruction PointPondéré : " << *this << endl;
}

double PointPondere::getPoids() const {
	return poids;
}

void PointPondere::setPoids(double poids) {
	this->poids = poids;
}

string PointPondere::toString() const {
	ostringstream res;
	res << Point::toString() << "#" << poids;
	return res.str();
}
