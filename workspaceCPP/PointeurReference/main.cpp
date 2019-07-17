/*
 * main.cpp
 *
 *  Created on: 16 juil. 2019
 *      Author: AELION
 */


#include <iostream>
using namespace std;

void introReferencePointeur() {
	int x = 4;
	int *px;
	int &rx = x;

	px = &x; // adresse de x
	x++;
	cout << x << "," << px << "," << *px << "," << rx << endl;
	cout << &x << "," << &px << "," << &rx << endl;

	rx++;
	cout << x << "," << px << "," << *px << "," << rx << endl;

	(*px)++;
	cout << x << "," << px << "," << *px << "," << rx << endl;
}

void echange(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void echangeParPointeur(int *px, int *py) {
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void testEchanges() {
	int x = 5;
	int y = 7;
	echange(x, y);
	cout << x << ", " << y << endl;
	echangeParPointeur(&x, &y);
	cout << x << ", " << y << endl;
}


void changeNomVille(string &ville) {
	ville[0] = 'Z';
}

void jouerAvecVille(const string &ville) {
	cout << "jouer à " << ville << " : " << endl;
	cout << "\t- recherche : " << ville.find("ou") << endl;
	cout << "\t- extrait : " << ville.substr(3,3) << endl;
	cout << "\t- longueur : " << ville.length() << endl;
	// ville += " ville rose";  => interdit
}

void testRefPointerString() {
	string ville = "Toulouse";
	changeNomVille(ville);
	cout << "Nouveau nom de ville : " << ville << endl;
	jouerAvecVille(ville);
	cout << "Au final : " << ville << endl;
}


int main() {
	// introReferencePointeur();
    // testEchanges();
	testRefPointerString();
}

