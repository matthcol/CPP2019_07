/*
 * main.cpp
 *
 *  Created on: 16 juil. 2019
 *      Author: AELION
 */
using namespace std;
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#include "Point.h"
#include "Cercle.h"
#include "PointPondere.h"

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
	cout << "adresse de A : " << pp << endl;

	pp = new Point("B",9.4, 56.4);
	ppoints->push_back(pp);
	cout << "adresse de B : " << pp << endl;

	cout << "adresse du vecteur : " << ppoints << endl;
	return ppoints;
}


void calculerDistance(const vector<Point*> &points) {
	Point pointRef("Ref", 15.6, 67.41);
	// calculer la distance de chaque point du vecteur au pointRef et l'afficher
	for(const auto pp: points) {
		double d1 = pointRef.distance(*pp);
		double d2 = pp->distance(pointRef);
		cout << "distance " << pointRef.toString() << " à "
				<< pp->toString() << " = " << d1 << " = " << d2 << endl;
	}
}

void translaterTous(vector<Point*> &points) {
	double deltaX = 1.11;
	double deltaY = -1.0001;
	for(auto pp: points) {
		pp->translater(deltaX, deltaY);
	}
	// translater tous les points du vecteur de (deltaX, deltaY)
}

void displayData(const vector<Point*> &points) {
	for (const Point *pp : points) {
		cout << pp->toString() << " ";
		//cout << "#" << pp << "# ";
	}
	cout << endl;
}

void clearData(vector<Point*> *ppoints) {
	for (Point* pp : *ppoints) {
		delete pp;  // appel du destructeur de Point + desalloue la memoire
	}
	delete ppoints; // appel du destructeur du vector + desallocation memoire
}

void scenario4() {
	vector<Point*> *ppoints = initData();
	cout << "adresse du vecteur : " << ppoints << endl;
	displayData(*ppoints);
	calculerDistance(*ppoints);
	translaterTous(*ppoints);
	displayData(*ppoints);

	Point &p1 = *((*ppoints)[0]);
	Point &p2 = *((*ppoints)[1]);

	p1 += p2;
	displayData(*ppoints);

	cout << "P1 par ref : " << p1 << endl;
	clog << "P1 par ref : " << p1 << endl;
	cout << "P1 par pointeur : " << (*ppoints)[0] << endl;

	clearData(ppoints);
}

void scenario5() {
	Point pA("A", 3.0, 4.0);
	Point pB("B", 1.0, 2.0);
	Point pE("E", -0.1, 0.0);
	Cercle c(&pA, 5.0);
	cout << "point : " << pA << endl;
	cout << "cercle : " << c << endl;
	cout << pB << " dans " << c << " : " << boolalpha << c.contient(pB) << endl;
	cout << pE << " dans " << c << " : " << boolalpha << c.contient(pE) << endl;
	cout << pA << " dans " << c << " : " << boolalpha << c.contient(pA) << endl;
}

void scenarioGdeDistance() {
	Point p1;
	Point p2("A", 1E308, 0.0);
	double d = p1.distance(p2);
	cout << "grande distance : " << d << endl;
}

void scenarioHeritage() {
	PointPondere pH("H", 5.6, 6.5, 12.45);
	cout << pH.toString() << endl;
	cout << pH << endl;  // appelle le toString de la classe P
	cout << "X = " << pH.getX() << endl;
	cout << "Poids = " << pH.getPoids() << endl;

	Point pA("A", 3.0, 4.0);
	double d1 = pA.distance(pH); // principe de substitutionde Liskov (LSP)
	double d2 = pH.distance(pA); // on peut appeler sur un PP une méthode d'un P
	cout << "distances : " << d1 << " ; " << d2 << endl;

	Cercle c(&pH, 5.0);
	cout << c << endl;

	pA = pH; // copie du PP pH en tant que P
	cout << pA << endl;
	cout << "pA est-il un Point ? " << boolalpha <<
			(typeid(pA) == typeid(Point)) << endl;
	cout << "pA est-il un PointPondéré ? " << boolalpha <<
			(typeid(pA) == typeid(PointPondere)) << endl;

	PointPondere &rpH = pH;
	PointPondere *ppH = &pH;

	Point &rp = pH;
	Point *pp = &pH;

	cout << "rp est-il un Point ? " << boolalpha <<
				(typeid(rp) == typeid(Point)) << endl;
	cout << "rp est-il un PointPondéré ? " << boolalpha <<
				(typeid(rp) == typeid(PointPondere)) << endl;
	cout << "pp pointe-t-il un Point ? " << boolalpha <<
					(typeid(*pp) == typeid(Point)) << endl;
	cout << "pp pointe-t-il un PointPondéré ? " << boolalpha <<
					(typeid(*pp) == typeid(PointPondere)) << endl;

//	rp.getPoids();
//	pp->getPoids();

	pp = new PointPondere("Z", 4.5, 5.4, 6.3);
	delete pp;
}

int main () {
	scenarioHeritage();
	// scenarioGdeDistance();
	// cout << Cercle::PI << endl;
	return 0;
}
