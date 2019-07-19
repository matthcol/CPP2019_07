/*
 * main.cpp
 *
 *  Created on: 16 juil. 2019
 *      Author: AELION
 */
using namespace std;
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
	Cercle c("C", &pA, 5.0);
	cout << "point : " << pA << endl;
	cout << "cercle : " << c << endl;
	cout << pB << " dans " << c << " : " << boolalpha << c.contient(pB) << endl;
	cout << pE << " dans " << c << " : " << boolalpha << c.contient(pE) << endl;
	cout << pA << " dans " << c << " : " << boolalpha << c.contient(pA) << endl;
	Cercle * pc;
	//pc = new Cercle(&pA, 5.0);
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

	Cercle c("C", &pH, 5.0);
	cout << c << endl;

	pA = pH; // copie du PP pH en tant que P
	cout << "copie : " << pA << endl;
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

template<class T>
void displayVector(const vector<T> &aVector) {
	for (const auto &t : aVector) {
		cout << t << " ";
	}
	cout << endl;
}

template<class InputIterator>
void enregistrerData(InputIterator first, InputIterator last, const string &filename) {
	ofstream file;
	file.open(filename, ofstream::out); //  | ofstream::app);
	for ( ; first != last; ++first) {
		const auto &v = *first;
		file << v << endl;
	}
	file.close();
}

template<class Conteneur>
void enregistrerData(const Conteneur &conteneur, const string &filename) {
	enregistrerData(begin(conteneur), end(conteneur), filename);
}

void scenarioFigures() {
	Point pA("A", 1.25, 5.25);
	Point pB("B", 5.5, -4.75);
	Point pC("C", 4.125, 7.75);
	Point pAA("AA", 4.125, 7.75);
	PointPondere pE("E", 1.25, -0.5, 45.3);
	Cercle c1("C1", &pA, 10.0);
	Cercle c2("C2", &pE, 5.0);
	Polygone py;
	vector<Figure*> figures = { &pA, &pB, &pC, &pE, &c1, &c2, &py, &pAA };
	displayVector(figures);  // appel du template avec T=Figure*
	// translater toutes les figures
	for (auto &f: figures){
		f->translater(1.0, -1.0);
	}
	displayVector(figures);

	double aireTotale;
	for (auto &f: figures){
		Mesurable2D *c = dynamic_cast<Mesurable2D*>(f); // nullptr si f n'est pas un cercle
		if (c != nullptr) {
			aireTotale += c->aire();
		}
	}
	cout << "aire totale : " << aireTotale << endl;
	// i.e. : displayVector<Figure*>(figures);

	vector<Point*> points;
	// reverser les points du vecteur de figures dans le vecteur de points
	for (auto &f: figures) {
		if (Point *p = dynamic_cast<Point *>(f)) {
			points.push_back(p);
		}
	}

	displayVector(points);   // appel du template avec T=Point*
	sort(points.begin(), points.end(),
			[](Point *p1, Point *p2){return p1->getX() < p2->getX();});
	displayVector(points);
	sort(points.begin(), points.end(), lessXYNomPtr);
	displayVector(points);
	sort(points.begin(), points.end(),
				[](auto p1, auto p2){return p1->getNom() < p2->getNom();});
	displayVector(points);
	sort(points.begin(), points.end());  // compare les @
	displayVector(points);
	sort(points.begin(), points.end(),
			[](auto pp1, auto pp2){return *pp1 < *pp2;});  // compare les points avec <
	displayVector(points);

	vector<Point> v = {pA, pB, pAA};
	sort(v.begin(), v.end());  // compare les points avec le < de la classe Point
	for (auto &e : v) {
		cout << e << " ";
	}
	cout << endl;

	// pA > pB;  // pas offert :(
	map<string, Figure*> indexNomFigure;
	for (auto pf: figures) {
		indexNomFigure[pf->getNom()] = pf;
	}
	for (auto &paireNomFigure: indexNomFigure) {
		cout << "- " << paireNomFigure.first
				<< " : "<< paireNomFigure.second << endl;
	}

	Figure *f = indexNomFigure["C1"];
	cout << "figure C1 : " << f << endl;

	Point fauxC1("C1",0.0,0.0);
	indexNomFigure["C1"] = &fauxC1;
	cout << "figure C1 : " << indexNomFigure["C1"] << endl;

//	map<string, vector<Figure*>> indexAvecDoublons;
//	map<string, vector<Film*>> indexTitreFilm;

	enregistrerData(figures, "figures.txt");
	enregistrerData(points, "points.txt");

	// Citation : "la mort de l'homme que j'ai désiré(e)"
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

void scenarioLecture() {
	string filename = "pointsIn.txt";
	vector<Point*> *ppoints = lirePoints(filename);
	displayVector(*ppoints);
	clearData(ppoints);

	filename = "figures.txt";
	ppoints = lirePoints(filename);
	displayVector(*ppoints);
	clearData(ppoints);
}

void scenarioAnalysePointTexte(){
	string line="E(3.25,-2.5)";
	// Regex
	// + : 1 à n fois
	// * : 0 à n fois
	// ? : 0 ou 1 fois
	// ( ) : isoler 1 expression
	// . : n'importe quel caractère
	// regex r("[A-Za-z][A-Za-z0-9]*\\(-?[0-9]+\\.[0-9]+,-?[0-9]+\\.[0-9]+\\)");
	regex r("[a-z][a-z\\d]*\\(-?[\\d]+\\.[\\d]+,-?[\\d]+\\.[\\d]+\\)", regex_constants::icase);
	if (regex_match(line,r)) {
		cout << "c'est 1 point" << endl;
		int p1 = line.find("(");
		int p2 = line.find(",", p1+1);
		int p3 = line.find(")", p2+1);
		string nom = line.substr(0, p1);
		string xStr = line.substr(p1+1, p2-p1-1);
		string yStr = line.substr(p2+1, p3-p2-1);
		cout << "#" << nom << "#" << xStr << "#" << yStr << "#" << endl;
		double x = stod(xStr);
		double y = stod(yStr);
		Point p(nom, x, y);
		cout << "objet point : " << p << endl;


	} else {
		cout << "ce n'est pas un point" << endl;
	}
}

int main () {
	scenarioLecture();
	return 0;
}
