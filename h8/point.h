/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef POINT_mickey_H
#define POINT_mickey_H
#include <math.h>
class Point
{
public:
    ~Point( )
    {
        return;
    };
    Point( )
    {
        x = 0;
        y = 0;
        return;
    }
    Point( float x, float y )
    {
        this->x = x;
        this->y = y;
        return;
    }
    Point( double x, double y )
    {
        this->x = ( float ) x;
        this->y = ( float ) y;
        return;
    }
    void move( float dx, float dy )
    {
        x += dx;
        y += dy;
        return;
    }
    void zoom( float r )
    {
        x *= r;
        y *= r;
        return;
    }
    float getx( )
    {
        return x;
    }
    float gety( )
    {
        return y;
    }
    float length( Point a )
    {
        return sqrt( ( a.x - x ) * ( a.x - x ) + ( a.y - y ) * ( a.y - y ) );
    }

private:
    float x, y;
};

#endif