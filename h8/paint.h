/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef PAINT
#define PAINT
#include<math.h>
class Point
{
public:
    Point( );
    ~Point( )
    {
        return;
    };
    Point( double x, double y );
    void   move( double dx, double dy );
    void   zoom( double r );
    double getx( )
    {
        return x;
    }
    double gety( )
    {
        return y;
    }
    double length( Point a )
    {
        return sqrt( ( a.x - x ) * ( a.x - x ) + ( a.y - y ) * ( a.y - y ) );
    }

private:
    double x, y;
};

class Shape
{
public:
    virtual ~Shape( ) = 0;
    virtual void   move( double dx, double dy );
    virtual void   zoom( double x );
    virtual double area( );
    virtual void   draw( );
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
    void   move( double dx, double dy );
    void   zoom( double x );
    double area( );
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
    void   move( double dx, double dy );
    void   zoom( double x );
    double area( );
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
    void   move( double dx, double dy );
    void   zoom( double x );
    double area( );
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
    void   move( double dx, double dy );
    void   zoom( double x );
    double area( );
    void   draw( );

private:
    Point p1, p2, p3, p4;
};
#endif // PAINT