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

Point::Point():x(0.0), y(0.0) {
	clog << "Point créé avec 0 paramètre : " << *this << endl;
}

Point::Point(const string &nom, double x, double y):Figure(nom), x(x), y(y)
{
	// ICI : tout sauf initialisation attributs
	clog << "Point créé avec 3 paramètres : " << *this << endl;
}

Point::Point(const Point &other):Figure(other), x(other.x), y(other.y) {
	clog << "Point créé par copie : " << *this << endl;
}

Point::~Point() {
	// TODO Auto-generated destructor stub
	clog << "destruction Point : " << *this << endl;
}

Point& Point::operator=(const Point &other) {
	setNom(other.getNom());
	x = other.x;
	y = other.y;
	clog << "copie de Point : " << other << endl;
	return *this;
}

Point& Point::operator+=(const Point &other) {
	x += other.x;
	y += other.y;
	return *this;
}

ostream& operator <<(ostream &out, const Point &p) {
	return out << p.toString();
}

ostream& operator <<(ostream &out, const Point *p) {
	return out << *p;
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
	res << getNom() << "(" << x << "," << y << ")";
	return res.str();
}

double Point::distance(const Point &other) const {
	//return sqrt(pow(x - other.x, 2.0) + pow(y -other.y, 2.0));
	return hypot(x - other.x, y -other.y);
}


void Point::translater(double deltaX, double deltaY) {
	x += deltaX;
	y += deltaY;
}
