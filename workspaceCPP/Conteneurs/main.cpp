/*
 * main.cpp
 *
 *  Created on: 18 juil. 2019
 *      Author: AELION
 */
#include <iostream>

#include <vector>
#include <list>
#include <array>
#include <map>
#include <cmath>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

void memory(){
	int x;
	int y;
	vector<int> * pvector = new vector<int>();
	cout << &x << ", " << &y << ", " << &pvector << ", " << pvector << endl;
	delete pvector;
}

double produit(double d1, double d2) {
	return d1*d2;
}

template <class InputIterator>
void displayContainer(InputIterator first, InputIterator last, char bullet='.') {
	for (; first!= last; ++first) {
		cout << bullet << ' ' << *first << endl;
	}
}

template <class Container>
void displayContainer(const Container &container, char bullet='.') {
	auto it = begin(container);
	auto last = end(container);
	for (; it != last ; ++it) {
		cout << bullet << ' ' << *it << endl;
	}
}

int main(){
	vector<double> pressions = {12.5, 16.7, 36.74, 14.36, 15.47, 639.1};
//	for (const auto &p : pressions) {
//		cout << "* 1 pression : " << p << endl;
//	}
	displayContainer(pressions);
	cout << "pression à l'index 1 : " << pressions[1] << endl;

	auto it = pressions.begin();
	auto fin = pressions.end();
//	for (it+=2; it != (fin-1); ++it) {   // ++it à préférer à it++, avancer d'une case
//		cout << "- valeur courante : " << *it << endl;
//	}
	displayContainer(it+2, fin-1, '-');
	list<double> qqsPressions(pressions.begin()+2, pressions.end()-1);
//	for (const auto &p : qqsPressions) {
//		cout << "% 1 pression : " << p << endl;
//	}
	displayContainer(qqsPressions, '%');
	auto position = qqsPressions.begin();
	++(++position);
	qqsPressions.insert(position, pressions.begin(), pressions.end());
	displayContainer(pressions.begin(), pressions.end(), '#');

//	double pressionTotaleQqsPressions = 0.0;
//	for (const auto &p: qqsPressions) {
//		pressionTotaleQqsPressions += p;
//	}
	double pressionTotaleQqsPressions = accumulate(
			qqsPressions.begin(), qqsPressions.end(), 0.0);
	cout << "Total des quelques pressions : " << pressionTotaleQqsPressions << endl;

	double produitQqsPressions = accumulate(
				qqsPressions.begin(), qqsPressions.end(), 1.0, multiplies<double>());
		cout << "Produit des quelques pressions : " << produitQqsPressions << endl;

	// <algorithm>
	// 1. trouver le minimum de qqs pressions
	// 2. trier les pressions de qqs pressions par ordre croissant
	// 3. obtenir un nouveau vecteur avec chaque pression élevée au carré
	// 4. remplir les cases de qqs pressions avec la valeur 10.0 à partir de la 3e
	double x = 3.0;
	vector<double> pressionsCarre(qqsPressions.size());
	transform(qqsPressions.begin(), qqsPressions.end(), pressionsCarre.begin(),
			 [](auto &p){return pow(p,2);}); 		// p -> p²
			// [x](auto &p){return pow(p,2) + x;});	// p -> p² + x
	displayContainer(pressionsCarre, '^');

	cout << "Tous les carrés > 100 : " << boolalpha <<
			all_of(pressionsCarre.begin(), pressionsCarre.end(),
					[](auto &p){return p > 100;}) << endl;
	cout << "Tous les carrés > 1000 : " << boolalpha <<
				all_of(pressionsCarre.begin(), pressionsCarre.end(),
						[](auto &p){return p > 1000;}) << endl;
	cout << "Au moins un carré > 1000 : " << boolalpha <<
					any_of(pressionsCarre.begin(), pressionsCarre.end(),
							[](auto &p){return p > 1000;}) << endl;

	sort(pressions.begin(), pressions.end()); // utilise less<double> i.e. <
	displayContainer(pressions, '<');
	sort(pressions.begin(), pressions.end(), greater<double>());
	displayContainer(pressions, '>');
	return 0;
}












