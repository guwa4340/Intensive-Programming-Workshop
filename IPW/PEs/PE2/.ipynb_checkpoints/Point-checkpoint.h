#include <vector>
#ifndef _POINT_H_ // header guard
#define _POINT_H_

/*
CSCI 3010, PE 2 solution, Fall 2020
Gunther Wallach
Multi dimensional point with Distance and Translate methods.
*/

using namespace std;

class Point {
public: 
    Point(int n); // 1-argument constructor
    Point(int a[]); //array constructor
	Point(vector<int> d);  // vector constructor
	
	int get(int d);  // inline member function

    void set(int d, int v);  // inline member function

	double Distance(Point p);  // member function

	void Translate(const int amt);  // member function
    
    int number_dimensions(); //inline member function


 private:
  vector<int> dims;  // data member, attribute, field

};  // class Point

#endif  // _POINT_H_

