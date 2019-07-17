/*
 * Cercle.h
 *
 *  Created on: 17 juil. 2019
 *      Author: AELION
 */

#ifndef CERCLE_H_
#define CERCLE_H_

#include "Point.h"

class Cercle {
public:
	Cercle();
	Cercle(Point *centre, double rayon);
	virtual ~Cercle();

	Point* getCentre() const;
	void setCentre(Point *centre);

	double getRayon() const;
	void setRayon(double rayon);

	string toString() const;

private:
	Point *centre;
	double rayon;
};

ostream& operator<<(ostream &out, const Cercle& cercle);

#endif /* CERCLE_H_ */
