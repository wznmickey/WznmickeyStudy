/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef PAINT
#define PAINT
#include <math.h>
class Point
{
public:
    Point( );
    ~Point( )
    {
        return;
    };
    Point( float x, float y );
    void   move( float dx, float dy );
    void   zoom( float r );
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

class Shape
{
public:
    virtual ~Shape( )                           = 0;
    virtual void   move( float dx, float dy ) = 0;
    virtual void   zoom( float x )             = 0;
    virtual float area( )                      = 0;
    virtual void   draw( )                      = 0;
};

class Triangle : public Shape
{
public:
    Triangle( );
    Triangle( Point p1, Point p2, Point p3 );
    ~Triangle( )
    {
        return;
    }
    void   move( float dx, float dy );
    void   zoom( float x );
    float area( );
    void   draw( );

private:
    Point p1, p2, p3;
};

class Rectangle : public Shape
{
public:
    Rectangle( );
    Rectangle( Point p1, Point p2 );
    ~Rectangle( )
    {
        return;
    }
    void   move( float dx, float dy );
    void   zoom( float x );
    float area( );
    void   draw( );

private:
    Point p1, p2;
};

class Parallelogram : public Shape
{
public:
    Parallelogram( );
    Parallelogram( Point p1, Point p2, Point p3, Point p4 );
    ~Parallelogram( )
    {
        return;
    }
    void   move( float dx, float dy );
    void   zoom( float x );
    float area( );
    void   draw( );

private:
    Point p1, p2, p3, p4;
};

class Trapezium : public Shape
{
public:
    Trapezium( );
    Trapezium( Point p1, Point p2, Point p3, Point p4 );
    ~Trapezium( )
    {
        return;
    }
    void   move( float dx, float dy );
    void   zoom( float x );
    float area( );
    void   draw( );

private:
    Point p1, p2, p3, p4;
};
#endif // PAINT