/**
Gunther Wallach
PE1
Point.cpp includes function implementations for every
function in the Point class. 
*/

#include <math.h>
#include <iostream>
#include "Point.h"

using namespace std;

//define the functions


/** contructor function with no parameters that sets point to (0,0) */
Point::Point(){
    x = 0;
    y = 0;
}
/** contructor function with parameters that sets point to parameters */
Point::Point(float x1, float y1){
    x = x1;
    y = y1;
}
/** function fetches x value of point through print statement and return statement */
float Point::get_x(){
    cout << "x =" << x << endl;
    return x;
}
/** function fetches y value of point through print statement and return statement */
float Point::get_y(){
    cout << "y =" << y << endl;
    return y;
}
/** function changes the x value of the point to the given parameter*/
void Point::set_x(float v){
    x = v;
    cout << "x set to" << x << endl;
}
/** function changes the y value of the point to the given parameter*/
void Point::set_y(float v){
    y = v;
    cout << "y set to" << y << endl;
}
/** function that calculates the distance between the declared point with the distance formula */
float Point::Distance(Point c){
    float dist = sqrt(((x-c.x)*(x-c.x)) + ((y-c.y)*(y-c.y)));
    cout << "Distance =" << dist << endl;
    return dist;
    
}
/** function that moves the x and y value of the given point by the passed in parameter */
void Point::Translate(int trans){
    float new_x = x + trans;
    float new_y = y + trans;
    x = new_x;
    y = new_y;
    cout << "Point Translated by" << trans << endl;
}