/*
 * main.cpp
 *
 *  Created on: 16 juil. 2019
 *      Author: AELION
 */
using namespace std;
#include <iostream>
#include <vector>

#include "Point.h"

void scenario1() {
	Point p;
	p.setNom("A");
	p.setX(5.5);
	p.setY(63.25);
	//cout << p.getNom() << "(" << p.getX() << "," << p.getY() << ")" << endl;
	cout << p.toString() << endl;

	const Point p2("B", 9.5, 60.25);
	//cout << p2.getNom() << "(" << p2.getX() << "," << p2.getY() << ")" << endl;
	cout << p2.toString() << endl;

	double d = p.distance(p2);
	cout << "distance : " << d << endl;

	double d2 = p2.distance(p);
	cout << "distance : " << d2 << endl;

	p.translater(-1.5, 5.3);
	cout << "Après translation : " << p.toString() << endl;

	// p2.translater(-1.5, 5.3);  // pas possible car p2 est const
	p.setNom("A2");
	p.setNom("A3");
}	// destruction de p et p2

void scenario2() {
	string ville1 = "Toulouse";
	string ville2 = "Nice";
	string ville3 = ville1;  // initialisation (constructeur par copie)
	string ville4; // declaration (constructeur par défaut)
	ville4 = ville2; // affectation
	cout << ville1 << ", " << ville2 << ", " << ville3 << ", " << ville4 << endl;
	cout << &ville1 << ", " << &ville2 << ", " << &ville3 << ", " << &ville4 << endl;
}

void scenario3(){
	Point p1("A", 3.0, 4.5);  // constructeur à 3 paramètres (complet)
	Point p2 = p1; // constructeur par copie implicite (1 level)
	Point p3;  // constructeur par défaut
	p3 = p1;
	cout << p1.toString() << ", " << p3.toString() << ", " << p2.toString() << endl;
	//p5 = p4 = p3 = p2;
}

vector<Point*>* initData() {
	Point *pp;
	vector<Point*> *ppoints = new vector<Point*>();

	pp = new Point("A",3.4, 5.7);
	ppoints->push_back(pp);

	pp = new Point("B",9.4, 56.4);
	ppoints->push_back(pp);
	return ppoints;
}

void displayData(const vector<Point*> &points) {
	for (const Point *p : points) {
		cout << p->toString() << " ";
	}
	cout << endl;
}

void clearData(vector<Point*> *ppoints) {
	// TODO
}

void scenario4() {
	vector<Point*> *ppoints = initData();
	displayData(*ppoints);
	clearData(ppoints);
}


int main () {
	scenario4();
	return 0;
}
