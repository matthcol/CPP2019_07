/*
 * main.cpp
 *
 *  Created on: 15 juil. 2019
 *      Author: AELION
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void manipVariables() {
	unsigned int prix;
	prix = 3000000000;
	cout << prix << endl;

	double prix2 = 9.99;
	cout << prix2 << endl;

	double tailleUnivers = 1E308;
	double infiniPetit = 1E-308;
	cout << tailleUnivers << ", " << infiniPetit << endl;

	float prixBonbon = 0.1;
	float total = prixBonbon * 3;
	cout << "Total : " << setprecision(15) << total << " €" << endl;

	string ville = "Toulouse";
	char lettre = ville[0];
	cout << "Il fait beau à " << ville << endl;
	cout << ville << " commence par " << lettre << endl;
	lettre = 'Z';
	ville[0] = lettre;
	cout << ville << endl;

	bool beauTemps = true;
	cout << boolalpha << beauTemps << endl;
}

void manipOperateurs() {
	int prixCine = 10;
	int prixRestau = 25;
	int totalSoiree = prixCine + prixRestau;
	cout << totalSoiree << endl;

	int reduction = totalSoiree * 5 / 100;
	int reste = (totalSoiree * 5) % 100;
	cout << reduction << ", " << reste << endl;

	double reductionD = totalSoiree * 5 / 100.0;
	cout << reductionD << endl;

	cout << boolalpha << !(totalSoiree <= 30) << endl;

	totalSoiree++;
	cout << "ça augmente : " << totalSoiree << endl;
	cout << "ça augmente : " << (totalSoiree++) << endl;
	cout << "ça augmente : " << (++totalSoiree) << endl;
	cout << "au final : " << totalSoiree << endl;

	totalSoiree += 5; // totalSoiree = totalSoiree + 5

	string ville1 = "Toulouse";
	string ville2 = "Toulon";
	cout << (ville1 < ville2) << endl;
	cout << (ville1 + ville2) << endl;
	// cout << (ville1 * ville2) << endl; // * not possible for string x string
}

void manipControl() {
	int vitesse = 200;
	if (vitesse == 0) {
		cout << "à l'arrêt" << endl;
	} else if (vitesse < 80) {
		cout << "vitesse correcte sur nationale" << endl;
	} else if (vitesse < 130) {
		cout << "vitesse correcte sur autoroute" << endl;
	} else {
		cout << "vitesse excessif" << endl;
	}

	for (int i=1; i<=10; i++) {
		cout << i << " ";
	}
	cout << endl;

	int cpt = 10;  // ou 0
	while (cpt > 0) {
		cpt -= 2;
		cout << cpt << " ";
	}
	cout << endl;

	cpt = 10;  // ou 0
	do {
		cpt -= 2;
		cout << cpt << " ";
	} while (cpt > 0);
	cout << endl;

	int tableauPrix[] = {12, 25, 34, 77, 14};
	for (auto prix : tableauPrix) {		// c++11
		cout << "un prix : " << prix << endl;
	}

}

int main () {
	// manipVariables();
	// manipOperateurs();
	manipControl();
	return 0;
}



