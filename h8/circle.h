/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef CIRCLE_mickey_H
#define CIRCLE_mickey_H
//圆
#include "color.h"
#include "point.h"
#include "shape.h"

#define PI            3.1415926
#define CIRCLE_LENGTH 50
class Circle : public Shape
{
public:
    ~Circle( )
    {
        return;
    }
    Circle( )
    {
        p1 = Point( 0, 0 );
        r  = ( float ) 1.0;
        c  = Color( );
        return;
    }
    Circle( Point p1, float r )
    {
        this->p1 = p1;
        this->r  = r;
        this->c  = Color( );
        return;
    }
    Circle( Point p1, float r, Color c )
    {
        this->p1 = p1;
        this->r  = r;
        this->c  = c;
        return;
    }
    void move( float dx, float dy )
    {
        p1.move( dx, dy );
        return;
    }
    void zoom( float r )
    {
        this->r *= r;
        return;
    }
    float area( )
    {
        return (float)PI * r * r;
    }
    float getr( )
    {
        return r;
    }
    Point getp()
    {
        return p1;
    }
    Color getc()
    {
        return c;
    }
    void draw( );

private:
    Point p1;
    float r;
    Color c;
};

#endif