/**
Gunther Wallach
PE1
main.cpp tests the Point class and functions
*/

#include "Point.h"
#include <iostream>

using namespace std;

int main(){
    Point p1(1,1);
    Point p2; //initilized at 0,0
    Point p3(-1,-1); //will test for negative
    //report coordinates of each point
    cout << "Coordinates of Point 1 =" << p1.get_x() << "," << p1.get_y() << endl;
    cout << "Coordinates of Point 2 =" << p2.get_x() << "," << p2.get_y() << endl;
    cout << "Coordinates of Point 3 =" << p3.get_x() << "," << p3.get_y() << endl;
    //report distances between coordinates
    cout << "Distance Between Point 1 and 2 = " << p1.Distance(p2);
    cout << "Distance Between Point 1 and 3 = " << p1.Distance(p3);
    cout << "Distance Between Point 2 and 3 = " << p2.Distance(p3);
    //translate all the points by a positive amount
    p1.Translate(2);
    p2.Translate(2);
    p3.Translate(2);
    //report coordinates for translated points
    cout << "Coordinates of Point 1 =" << p1.get_x() << "," << p1.get_y() << endl;
    cout << "Coordinates of Point 2 =" << p2.get_x() << "," << p2.get_y() << endl;
    cout << "Coordinates of Point 3 =" << p3.get_x() << "," << p3.get_y() << endl;
    //report distances between coordinates
    cout << "Distance Between Point 1 and 2 = " << p1.Distance(p2);
    cout << "Distance Between Point 1 and 3 = " << p1.Distance(p3);
    cout << "Distance Between Point 2 and 3 = " << p2.Distance(p3);
    //translate all the points by a negative amount
    p1.Translate(-2);
    p2.Translate(-2);
    p3.Translate(-2);
    //report coordinates for translated points
    cout << "Coordinates of Point 1 =" << p1.get_x() << "," << p1.get_y() << endl;
    cout << "Coordinates of Point 2 =" << p2.get_x() << "," << p2.get_y() << endl;
    cout << "Coordinates of Point 3 =" << p3.get_x() << "," << p3.get_y() << endl;
    //report distances between coordinates
    cout << "Distance Between Point 1 and 2 = " << p1.Distance(p2);
    cout << "Distance Between Point 1 and 3 = " << p1.Distance(p3);
    cout << "Distance Between Point 2 and 3 = " << p2.Distance(p3);
 }