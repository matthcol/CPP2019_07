/*
 * Point.cpp
 *
 *  Created on: 16 juil. 2019
 *      Author: AELION
 */

#include "Point.h"
#include <iostream>
#include <sstream>
#include <cmath>

Point::Point() {
	clog << "Point créé avec 0 paramètre" << endl;

}

Point::Point(const string &nom, double x, double y):nom(nom), x(x), y(y)
{
	// ICI : tout sauf initialisation attributs
	clog << "Point créé avec 3 paramètres" << endl;
}


Point::~Point() {
	// TODO Auto-generated destructor stub
	clog << "destruction Point" << endl;
}

const string& Point::getNom() const {
	return nom;
}

void Point::setNom(const string &nom) {
	this->nom = nom;
}

double Point::getX() const {
	return x;
}

void Point::setX(double x) {
	this->x = x;
}

double Point::getY() const {
	return y;
}

void Point::setY(double y) {
	this->y = y;
}

string Point::toString() const {
	ostringstream res;
	res << nom << "(" << x << "," << y << ")";
	return res.str();
}

double Point::distance(const Point &other) const {
	return sqrt(pow(x - other.x, 2.0) + pow(y -other.y, 2.0));
}

Point::Point(const Point &other):nom(other.nom), x(other.x), y(other.y) {
	clog << "Point créé par copie" << endl;
}

Point& Point::operator=(const Point &other) {
	nom = other.nom;
	x = other.x;
	y = other.y;
	clog << "copie de Point" << endl;
	return *this;
}

void Point::translater(double deltaX, double deltaY) {
	x += deltaX;
	y += deltaY;
}
