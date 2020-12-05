/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef EX3_CAR_mickey_H
#define EX3_CAR_mickey_H
#include "opengldraw.h"
class Car : public Shape
{
public:
    Car( )
    {
        lw        = Circle( Point( 0.4, 0.2 ), 0.05, Color( 0.7, 0.4, 0.5, 0.5 ) );
        rw        = Circle( Point( 0.6, 0.2 ), 0.05, Color( 0.7, 0.4, 0.5, 0.5 ) );
        r         = Rectangle( Point( 0.3, 0.4 ), Point( 0.7, 0.2 ), Color( 0.2, 0.4, 0.2 ) );
        t         = Trapezium( Point( 0.3, 0.4 ), Point( 0.35, 0.5 ), Point( 0.55, 0.5 ), Point( 0.65, 0.4 ), Color( 0.3, 0.15, 0 ) );
        direction = true;
        return;
    }
    ~Car( )
    {
        return;
    }
    void draw( )
    {
        r.draw( );
        t.draw( );
        lw.draw( );
        rw.draw( );
        return;
    }
    void move( float dx, float dy )
    {
        lw.move( dx, dy );
        rw.move( dx, dy );
        r.move( dx, dy );
        t.move( dx, dy );
    }
    void zoom( float x )
    {
        lw.zoom( x );
        rw.zoom( x );
        r.zoom( x );
        t.zoom( x );
    }
    float area( )
    {
        return lw.area( ) / 2 + rw.area( ) / 2 + r.area( ) + t.area( );
    }
    Point get( )
    {
        return r.getp1( );
    }
    void run( double x )
    {
        if ( direction == true ) move( ( float ) x, 0 );
        else
            move( ( float ) -x, 0 );
        return;
    }
    void reverse( )
    {
        direction = ! direction;
        return;
    }

private:
    Circle    lw, rw; // left wheel & right wheel
    Rectangle r;
    Trapezium t;
    bool      direction; // true-right false-left
};

#endif