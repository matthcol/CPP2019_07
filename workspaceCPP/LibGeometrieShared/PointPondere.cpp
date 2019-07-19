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
	clog << "PointPond�r� cr�� avec 0 param�tre : " << *this << endl;
}

PointPondere::PointPondere(const string &nom, double x, double y,
		double poids):Point(nom,x,y), poids(poids) {
	clog << "PointPond�r� cr�� avec 4 param�tres : " << *this << endl;
}

PointPondere::~PointPondere() {
	clog << "d�truction PointPond�r� : " << *this << endl;
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
