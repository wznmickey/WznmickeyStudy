/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef PARALLELOGRAM_mickey_H
#define PARALLELOGRAM_mickey_H
//平行四边形
#include "color.h"
#include "point.h"
#include "shape.h"
#include "triangle.h"
class Parallelogram : public Shape
{
public:
    ~Parallelogram( )
    {
        return;
    }

    Parallelogram( )
    {
        p1 = Point( 0, 0 );
        p2 = Point( 0, 0 );
        p3 = Point( 0, 0 );
        p4 = Point( 0, 0 );
        c  = Color( );
        return;
    }
    Parallelogram( Point p1, Point p2, Point p3, Point p4 )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
        this->c  = Color( );
        return;
    }
    Parallelogram( Point p1, Point p2, Point p3, Point p4, Color c )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
        this->c  = c;
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
Point getp1( )
    {
        return p1;
    }
    Point getp2( )
    {
        return p2;
    }
    Point getp3( )
    {
        return p3;
    }
    Point getp4( )
    {
        return p4;
    }
    Color getc( )
    {
        return c;
    }
    void draw( );

private:
    Point p1, p2, p3, p4;
    Color c;
};
#endif