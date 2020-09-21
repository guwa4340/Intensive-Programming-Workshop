/**
Gunther Wallach
PE1
Point.h includes definition of the Point class, as well as function headers. 
*/

#include <math.h>
#ifndef POINT
#define POINT

class Point{
    public:
        
        //constructors
        Point();
        Point(float x, float y);
        
        //functions to get the point values:
        float get_x();
        float get_y();
        //functions to set values
        void set_x(float v);
        void set_y(float v);
        float Distance(Point c);
        void Translate(int trans);
        float x;
        float y;
};

#endif