/*
 * Cercle.h
 *
 *  Created on: 17 juil. 2019
 *      Author: AELION
 */

#ifndef CERCLE_H_
#define CERCLE_H_

#include "Point.h"
#include "Mesurable2D.h"

class Cercle: public Figure, public Mesurable2D {
public:
	Cercle(const string &nom,Point *centre, double rayon);
	virtual ~Cercle();

	Point* getCentre() const;
	void setCentre(Point *centre);

	double getRayon() const;
	void setRayon(double rayon);

	double perimetre() const override;
	double aire() const override;

	bool contient(const Point &p) const;

	string toString() const;

	static const double PI;  // membre de classe (static)

	void translater(double deltaX, double deltaY) override;

private:
	Point *centre;
	double rayon;
};

#endif /* CERCLE_H_ */
