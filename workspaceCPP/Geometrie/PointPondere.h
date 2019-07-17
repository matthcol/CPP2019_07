/*
 * PointPondere.h
 *
 *  Created on: 17 juil. 2019
 *      Author: AELION
 */

#ifndef POINTPONDERE_H_
#define POINTPONDERE_H_

#include "Point.h"

class PointPondere: public Point  {
public:
	PointPondere();
	PointPondere(const string &nom, double x, double y, double poids);
	virtual ~PointPondere();

	double getPoids() const;
	void setPoids(double poids);

	virtual string toString() const override; // redéfinition (override)

private:
	double poids;
};

#endif /* POINTPONDERE_H_ */
