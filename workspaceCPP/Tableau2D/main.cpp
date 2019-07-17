/*
 * main.cpp
 *
 *  Created on: 16 juil. 2019
 *      Author: AELION
 */
#include <iostream>
using namespace std;

template <unsigned int N>
void afficheCarre(int carre[][N]) {
	for (unsigned int i=0; i<N; i++) {
		for (unsigned int j=0; j<N; j++) {
			cout << carre[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int carre[][3] = {{2,7,6},{9,5,1},{4,3,8}};
	afficheCarre<3>(carre);
	//int sommeLigne = sommeLigne(carre,0);

}


