/*
 * main.cpp
 *
 *  Created on: 19 juil. 2019
 *      Author: AELION
 */
#include "utils.h"
#include "Point.h"

#include <vector>

int main() {
	string filename = "pointsIn.txt";
	vector<Point*> *ppoints = lirePoints(filename);
	displayVector(*ppoints);
	clearData(ppoints);

	filename = "figures.txt";
	ppoints = lirePoints(filename);
	displayVector(*ppoints);
	clearData(ppoints);
}



