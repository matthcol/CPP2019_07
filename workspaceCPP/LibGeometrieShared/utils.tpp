#include <fstream>
#include <iostream>
#include <regex>

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