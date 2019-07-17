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
	Cercle(Point *centre, double rayon);
	virtual ~Cercle();

	Point* getCentre() const;
	void setCentre(Point *centre);

	double getRayon() const;
	void setRayon(double rayon);

	double perimetre() const;

	bool contient(const Point &p) const;

	string toString() const;

	static const double PI;  // membre de classe (static)

private:
	Point *centre;
	double rayon;
};

ostream& operator<<(ostream &out, const Cercle& cercle);

#endif /* CERCLE_H_ */
