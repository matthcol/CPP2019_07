/*
 * main.cpp
 *
 *  Created on: 15 juil. 2019
 *      Author: AELION
 */
#include <iostream>
#include <iterator>
using namespace std;

int pgcd(int a, int b) {
	// intermediaire
	int r;
	do {
		r = a % b;
		a = b;
		b = r;
	} while (b!=0);
	return a;
}

void euclide() {
	// entrees
	int a = 15;
	int b = 12;
	int p = pgcd(a, b);
	cout << "pgcd de " << a << " et " << b << " = " << p << endl;
}

int rechercheValeur(double tableau[], int longueur, double valeur)  {
// int rechercheValeur(double tableau[], double valeur)  {
	// reponse
	int pos = -1;   // position de la valeur trouvée ou -1
	//
	//int lon = size(tableau);
	for (int i=0; i<longueur; i++) {
		if (valeur == tableau[i]) {
			pos = i;
			break;
		}
	}
	return pos;
}

void recherche() {
	// entrees
	double tableauPrix[] = {12.5, 45.3, 69.7, 36.1, 16.9, 7563.4};
	int longueur = 6;
	double prix = 36.1;
	// reponse
	int pos = rechercheValeur(tableauPrix, size(tableauPrix), prix);
	//int pos = rechercheValeur(tableauPrix, longueur, prix);
	cout << "position trouvée (ou pas) : " << pos << endl;
}


void rechercheDichotomique() {
	// entrees : tableau trié
	double tableauPrix[] = {12.5, 16.75, 36.125, 45.75, 69.625};
	double prix = 45.3;
	// intermediaire
	int debut = 0; // position 1ere valeur incluse
	int fin = 5;   // position derniere valeur excluse
	int milieu;   // position de l'element du milieu
	// recherche
	int pos = -1;
	while (debut < fin) {
		milieu = (debut + fin) / 2;
		if (prix == tableauPrix[milieu]) {
			pos = milieu;
			break;
		} else if (prix < tableauPrix[milieu]) {
			fin = milieu;
		} else {	// prix > tableauPrix[milieu]
			debut = milieu + 1;
		}
	}
	cout << "position trouvée (ou pas) : " << pos << endl;

	// cout << std::size(tableauPrix);
}

int main() {
	 // euclide();
	recherche();

	// rechercheDichotomique();
}

