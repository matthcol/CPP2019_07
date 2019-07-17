/*
 * main.cpp
 *
 *  Created on: 16 juil. 2019
 *      Author: AELION
 */


#include <iostream>
#include <iterator>
using namespace std;

void afficheTableau(double *tableau, int longueur) {
//void afficheTableau(double tableau[], int longueur) {
	for (int i=0; i<longueur; i++) {
		cout << tableau[i] << " ";
	}
	cout << endl;
}

void afficheTableau3(double tableau[3]) {
	for (int i=0; i<3; i++) {
		cout << tableau[i] << " ";
	}
	cout << endl;
}

template<unsigned int N>
void afficheTableauN(double tableau[N]) {
	for (unsigned int i=0; i<N; i++) {
		cout << tableau[i] << " ";
	}
	cout << endl;
	//cout << size(tableau);
}



int main() {
	// tableaux statiques
	double prix[] = { 12.3, 45.6, 78.9 };// initialise statiquement
	double pressions[3];  // 3 cases avec contenu aléatoire
	pressions[0] = 12.6;
	pressions[1] = 45.3;
	pressions[2] = 25.6;

	// tableau dynamique
	int n = 4;  // valeur issue d'un calcul ou d'un saisie
	double *vitesses = new double[n];  // dynamique
	for (int i=0; i<n; i++) {
		vitesses[i] = 4.7 * i;
	}

	// affichages
	afficheTableau(prix, 3); // size(prix));
	afficheTableau(pressions, 3); // size(pressions));
	afficheTableau(vitesses, n);
	afficheTableau(vitesses+1, n-1);  // arithmetique sur les pointeurs
	afficheTableau(prix+1, 2);
	afficheTableau3(prix);
	afficheTableau3(pressions);
	afficheTableau3(vitesses);
	afficheTableauN<4>(vitesses);
	afficheTableauN<3>(vitesses);

	// nettoyer le tas
	delete [] vitesses;
}
