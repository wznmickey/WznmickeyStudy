/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef RECTANGLE_mickey_H
#define RECTANGLE_mickey_H
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
        p1 = Point( 0, 0 );
        p2 = Point( 0, 0 );
        return;
    }
    Rectangle( Point p1, Point p2 )
    {
        this->p1 = p1;
        this->p2 = p2;
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

    void draw( );

private:
    Point p1, p2;
    Color c;
};

#endif