/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef TRIANGLE_mickey_H
#define TRIANGLE_mickey_H
#include "color.h"
#include "point.h"
#include "shape.h"
class Triangle : public Shape
{
public:
    ~Triangle( )
    {
        return;
    }

    Triangle( )
    {
        p1 = Point( 0, 0 );
        p2 = Point( 0, 0 );
        p3 = Point( 0, 0 );
        c  = Color( );
        return;
    }
    Triangle( Point p1, Point p2, Point p3 )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        c        = Color( );
        return;
    }
    Triangle( Point p1, Point p2, Point p3, Color c )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->c  = c;
        return;
    }
    void move( float dx, float dy )
    {
        p1.move( dx, dy );
        p2.move( dx, dy );
        p3.move( dx, dy );
        return;
    }
    void zoom( float r )
    {
        p1.zoom( r );
        p2.zoom( r );
        p3.zoom( r );
        return;
    }
    float area( )
    {
        // using Heron's formula
        float a = p1.length( p2 );
        float b = p2.length( p3 );
        float c = p3.length( p1 );
        float p = a + b + c;
        return sqrt( p * ( p - a ) * ( p - b ) * ( p - c ) );
    }
    void draw( );

private:
    Point p1, p2, p3;
    Color c;
};

#endif