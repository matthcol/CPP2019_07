/*
 * Figure.h
 *
 *  Created on: 17 juil. 2019
 *      Author: AELION
 */

#ifndef FIGURE_H_
#define FIGURE_H_

#include <string>
using namespace std;

class Figure {
public:
	Figure();
	Figure(const string &nom);
	virtual ~Figure();

	const string& getNom() const;
	void setNom(const string &nom);

	virtual void translater(double deltaX, double deltaY)=0; // virtuelle pure
private:
	string nom;
};

#endif /* FIGURE_H_ */
