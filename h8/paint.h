/*******************************
    Written by WANGZINING
    blog: https://wznmickey.com
*******************************/
#ifndef PAINT
#define PAINT

class Point
{
public:
    double x, y
};
class Triangle
{
public:
    Triangle( );
    Triangle( Point p1, Point p2, Point p3 );
    ~Triangle( );
    void  move( double dx, double dy );
    void  zoom( double x );
    float area( );

private:
    Point p1, Point p2, Point p3;
};
class Rectangle
#endif