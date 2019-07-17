/*
 * PointPondere.cpp
 *
 *  Created on: 17 juil. 2019
 *      Author: AELION
 */

#include "PointPondere.h"

PointPondere::PointPondere():Point(), poids(1.0) {
	// TODO Auto-generated constructor stub
}

PointPondere::PointPondere(const string &nom, double x, double y,
		double poids):Point(nom,x,y), poids(poids) {
}

PointPondere::~PointPondere() {
	// TODO Auto-generated destructor stub
}

double PointPondere::getPoids() const {
	return poids;
}

void PointPondere::setPoids(double poids) {
	this->poids = poids;
}


