/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef CIRCLE_mickey_H
#define CIRCLE_mickey_H
#include "paint.h"
#include <GL/glut.h>
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
        return;
    }
    Circle( Point p1, float r )
    {
        this->p1 = p1;
        this->r  = r;
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
        return PI * r * r;
    }
    void draw( );

private:
    Point p1;
    float r;
};

#endif