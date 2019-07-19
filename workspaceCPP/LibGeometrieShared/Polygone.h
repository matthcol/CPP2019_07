/*
 * Polygone.h
 *
 *  Created on: 18 juil. 2019
 *      Author: AELION
 */

#ifndef POLYGONE_H_
#define POLYGONE_H_

using namespace std;

#include "Figure.h"
#include "Mesurable2D.h"
#include <string>

class Polygone: public Figure, public Mesurable2D {
public:
	Polygone();
	virtual ~Polygone();

	virtual double aire() const;
	virtual double perimetre() const;
	virtual string toString() const;
	virtual void translater(double deltaX, double deltaY);
};

#endif /* POLYGONE_H_ */
