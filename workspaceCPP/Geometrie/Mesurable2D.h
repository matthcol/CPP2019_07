/*
 * Mesurable2D.h
 *
 *  Created on: 18 juil. 2019
 *      Author: AELION
 */

#ifndef MESURABLE2D_H_
#define MESURABLE2D_H_

class Mesurable2D {
public:
	Mesurable2D();
	virtual ~Mesurable2D();

	virtual double perimetre() const=0;
	virtual double aire() const=0;
};

#endif /* MESURABLE2D_H_ */
