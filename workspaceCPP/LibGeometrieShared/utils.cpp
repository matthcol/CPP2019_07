/*
 * main.cpp
 *
 *  Created on: 16 juil. 2019
 *      Author: AELION
 */
using namespace std;
#include "utils.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <regex>

#include "Point.h"
#include "Cercle.h"
#include "PointPondere.h"
#include "Polygone.h"
#include "Mesurable2D.h"

void clearData(vector<Point*> *ppoints) {
	for (Point* pp : *ppoints) {
		delete pp;  // appel du destructeur de Point + desalloue la memoire
	}
	delete ppoints; // appel du destructeur du vector + desallocation memoire
}



Point *lirePoint(string pointStr) {
	regex r("[a-z][a-z\\d]*\\(-?[\\d]+\\.[\\d]+,-?[\\d]+\\.[\\d]+\\)", regex_constants::icase);
	if (regex_match(pointStr,r)) {
		// cout << "c'est 1 point" << endl;
		int p1 = pointStr.find("(");
		int p2 = pointStr.find(",", p1+1);
		int p3 = pointStr.find(")", p2+1);
		string nom = pointStr.substr(0, p1);
		string xStr = pointStr.substr(p1+1, p2-p1-1);
		string yStr = pointStr.substr(p2+1, p3-p2-1);
		//cout << "#" << nom << "#" << xStr << "#" << yStr << "#" << endl;
		double x = stod(xStr);
		double y = stod(yStr);
		Point *pp = new Point(nom, x, y);
		return pp;
	} else {
		return nullptr;
	}
}

vector<Point*> *lirePoints(string filename) {
	vector<Point*> *res = new vector<Point*>;
	ifstream file;
	string line;
	file.open(filename, ifstream::in);
	while(getline(file, line)) {
		Point *pp = lirePoint(line);
		if (pp) {
			res->push_back(pp);
		}
	}
	return res;
}
