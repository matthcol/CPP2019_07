/**
 * Project Untitled
 */


#ifndef _CERCLE_H
#define _CERCLE_H

#include "Point.h"


class Cercle {
public: 
    double rayon;
    double diametre;
    double aire;
    double perimetre;
    Point centre;
    
/**
 * @param p
 */
void contient(Point p);
};

#endif //_CERCLE_H