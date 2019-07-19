/*
 * utils.h
 *
 *  Created on: 19 juil. 2019
 *      Author: AELION
 */

#ifndef UTILS_H_
#define UTILS_H_
using namespace std;

#include <vector>
#include "Point.h"
#include "Figure.h"

template<class T>
void displayVector(const vector<T> &aVector);

template<class InputIterator>
void enregistrerData(InputIterator first, InputIterator last, const string &filename);

template<class Conteneur>
void enregistrerData(const Conteneur &conteneur, const string &filename);

void clearData(vector<Point*> *ppoints);

Point *lirePoint(string pointStr);

vector<Point*> *lirePoints(string filename);

#include "utils.tpp"

#endif /* UTILS_H_ */
