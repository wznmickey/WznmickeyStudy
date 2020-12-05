/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef TRAPEZIUM_mickey_H
#define TRAPEZIUM_mickey_H

#include "color.h"
#include "point.h"
#include "shape.h"
#include "triangle.h"
class Trapezium : public Shape
{
public:
    ~Trapezium( )
    {
        return;
    }

    Trapezium( )
    {
        p1 = Point( 0, 0 );
        p2 = Point( 0, 0 );
        p3 = Point( 0, 0 );
        p4 = Point( 0, 0 );
        return;
    }
    Trapezium( Point p1, Point p2, Point p3, Point p4 )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
        return;
    }
    void move( float dx, float dy )
    {
        p1.move( dx, dy );
        p2.move( dx, dy );
        p3.move( dx, dy );
        p4.move( dx, dy );
        return;
    }
    void zoom( float r )
    {
        p1.zoom( r );
        p2.zoom( r );
        p3.zoom( r );
        p4.zoom( r );
        return;
    }
    float area( )
    {
        Triangle a, b;
        a = Triangle( p1, p2, p3 );
        b = Triangle( p2, p3, p4 );
        return a.area( ) + b.area( );
    }

    void draw( );

private:
    Point p1, p2, p3, p4;
    Color c;
};
#endif