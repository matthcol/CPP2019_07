/*
 * main.cpp
 *
 *  Created on: 19 juil. 2019
 *      Author: AELION
 */
using namespace std;

#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <thread>

void somme(vector<double> * v, double *res) {
	double s = accumulate(v->begin(), v->end(), 0.0);
	*res = s;
}

int main() {
	// thread principal
	vector<double> *data = new vector<double>(1000000);
	double *d = new double;
	fill(data->begin(), data->end(), 1.0);
	//somme(data,d);
	// create un thread secondaire qui fait le calcul de la somme
	thread t(somme, data, d);
	// à répéter autant de fois qu'on veut

	// attendre la fin de chaque thread
	t.join();
	cout << "Somme = " << *d << endl;
	delete d;
	delete data;

	// 1 process contient 1 ou plusieurs thread(s)

}
