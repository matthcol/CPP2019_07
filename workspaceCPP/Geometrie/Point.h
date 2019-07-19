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

	Point& operator=(const Point &other);
	Point& operator+=(const Point &other);

	bool operator==(const Point &other) const;
	bool operator<(const Point &other) const;

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


// 'bool operator==(const Point*, const Point*)' must have an argument of class or enumerated type	Point.h	/Geometrie	line 43	C/C++ Problem
//bool operator==(const Point *pp1, const Point *pp2);
//bool operator<(const Point *pp1, const Point *pp2);

bool lessXYNomPtr(const Point *pp1, const Point *pp2);

bool lessXYNom(const Point &p1, const Point &p2);


#endif /* POINT_H_ */
