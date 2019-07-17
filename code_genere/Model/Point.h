/**
 * Project Untitled
 */


#ifndef _POINT_H
#define _POINT_H

class Point {
public: 
    string nom;
    double x;
    double y;
    
/**
 * @param p
 */
double distance(Point p);
    
/**
 * @param deltaX
 * @param deltaY
 */
void translater(double deltaX, double deltaY);
};

#endif //_POINT_H