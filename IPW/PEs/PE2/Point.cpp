#include <cmath>
#include <vector>
#include <iostream>
#include "Point.h"

/*
CSCI 3010, PE 2 solution, Fall 2020
Gunther Wallach
Multi-dimensional point with Distance and Translate methods.
*/
using namespace std;
/**
  Creates a new Point object with coordinates all zeros for the number of dimensions
*/
Point::Point(int n) {
    for(int i = 0; i < n; i++){
        dims.push_back(0);
  }
}

/**
  Creates a new Point where the dimensions can be passed in as an array
*/
Point::Point(int a[]){
    int size = (sizeof(a)*2)/sizeof(a[0]);
    cout << size << endl;
    for(int i = 0; i < size;i++){
        dims.push_back(a[i]);
    }
}

/*creates a point from a vector */
Point::Point(vector<int> d) {
    for(int i=0;i<d.size();i++){
        dims.push_back(d[i]);
    }
}

/*getter function that retreives dimension at given number of dimension*/
int Point::get(int d){
    return (dims[d]);
}
/*setter function that sets dimension at given number of dimension*/
void Point::set(int d, int v){
    dims[d] = v;
}

/**
  Calculates the distance between this point and another Point.
  @param other Point object to calculate the distance to
*/
double Point::Distance(Point p){
    if (dims.size() != p.dims.size()){
        return -1;
    }
    double distance = 0;
    for (int i = 0; i < dims.size();i++){
        distance += (dims[i] - p.get(i)) * (dims[i] - p.get(i));
    }
    return sqrt(distance);
}
    

/**
  Moves this Point's coordinates by the amount given.
  @param amt int amount by which to move the coordinates of this Point.
*/
void Point::Translate(const int amt) {
    for(int i=0;i<dims.size();i++){
        dims[i] = dims[i] + amt;
    }
}

//just gets the size of the dimensions
int Point::number_dimensions(){
    return (dims.size());
}
