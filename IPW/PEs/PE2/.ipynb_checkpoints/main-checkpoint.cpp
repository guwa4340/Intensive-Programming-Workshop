#include <iostream>
#include <vector>
#include "Point.h"

/*
CSCI 3010, PE 2 solution, Fall 2020
Gunther Wallach
Multi-dimensional point with Distance and Translate methods.

Use Makefile to compile. "make" will produce executable "main". Run (on unix systems) with "./main"
*/
using namespace std;
    
    
int main(int argc, char **argv){
	Point p1(4);
    vector<int> d = {1,1,1,1,1,1};
	Point p2(d);
    cout << "p1 = ";
    for(int i=0;i<p1.number_dimensions();i++){
        cout << p1.get(i);
    }
    cout << endl;
    //test using an array
    int a[] = {1,2,1,2};
    Point p4(a);
    cout << "p4 = ";
    for(int i=0;i<p4.number_dimensions();i++){
        cout << p4.get(i);
    }
    cout << endl;
    //test vector
    cout << "p2 = ";
    for(int i=0;i<p2.number_dimensions();i++){
        cout << p2.get(i);
    }
    cout << endl;
    //test set function
    p2.set(3,3);
    cout << "p2 = ";
    for(int i=0;i<p2.number_dimensions();i++){
        cout << p2.get(i);
    }
    cout << endl;
    //test distance function
    if (p1.Distance(p2) == -1){
        cout << "Dimensions are not applicable to finding distance" << endl;
    }
    //test distance function with working dims
    vector<int> d1 = {2,3,4,5,6,7};
    Point p3(d1);
    cout << "Distance =" << p2.Distance(p3) << endl;
    // test translate function
    p2.Translate(5);
    cout << "p2 Translated to = ";
    for(int i=0;i<p2.number_dimensions();i++){
        cout << p2.get(i);
    }
    cout << endl;
	return 0;
}
