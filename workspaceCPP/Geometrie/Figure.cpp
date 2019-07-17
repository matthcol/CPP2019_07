/*
 * Figure.cpp
 *
 *  Created on: 17 juil. 2019
 *      Author: AELION
 */

#include "Figure.h"

Figure::Figure() {
}

Figure::Figure(const string &nom):nom(nom) {
}

Figure::~Figure() {
	// TODO Auto-generated destructor stub
}

const string& Figure::getNom() const {
	return nom;
}

void Figure::setNom(const string &nom) {
	this->nom = nom;
}

