/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef RECTANGLE_mickey_H
#define RECTANGLE_mickey_H
//矩形
#include "color.h"
#include "point.h"
#include "shape.h"
class Rectangle : public Shape
{
public:
    ~Rectangle( )
    {
        return;
    }

    Rectangle( )
    {
        p1      = Point( 0, 0 );
        p2      = Point( 0, 0 );
        this->c = Color( );
        return;
    }
    Rectangle( Point p1, Point p2 )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->c  = Color( );
        return;
    }
    Rectangle( Point p1, Point p2, Color c )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->c  = c;
        return;
    }
    void move( float dx, float dy )
    {
        p1.move( dx, dy );
        p2.move( dx, dy );
        return;
    }
    void zoom( float r )
    {
        p1.zoom( r );
        p2.zoom( r );
        return;
    }
    float area( )
    {
        return fabs( ( p1.getx( ) - p2.getx( ) ) ) * fabs( ( p1.gety( ) - p2.gety( ) ) );
    }
Point getp1( )
    {
        return p1;
    }
    Point getp2( )
    {
        return p2;
    }
    Color getc( )
    {
        return c;
    }
    void draw( );

private:
    Point p1, p2;
    Color c;
};

#endif