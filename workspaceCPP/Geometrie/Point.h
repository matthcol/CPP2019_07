/*
 * Point.h
 *
 *  Created on: 16 juil. 2019
 *      Author: AELION
 */

#ifndef POINT_H_
#define POINT_H_

using namespace std;
#include <string>
#include "Figure.h"

class Point: public Figure {
public:
	Point();
	Point(const string &nom, double x, double y);
	Point(const Point &other);
	virtual ~Point();

	Point& operator=(const Point & other);
	Point& operator+=(const Point & other);


	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);

	virtual string toString() const;

	double distance(const Point &other) const;
	void translater(double deltaX, double deltaY);

private:
	double x;
	double y;
};

ostream &operator<<(ostream &out, const Point &p);
ostream &operator<<(ostream &out, const Point *p);

#endif /* POINT_H_ */
