/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef PAINT_mickey_H
#define PAINT_mickey_H
#include "color.h"
#include <bits/stdc++.h>
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

class Shape
{
public:
    ~Shape( )
    {
        return;
    }
    virtual void  move( float dx, float dy ) = 0;
    virtual void  zoom( float x )            = 0;
    virtual float area( )                    = 0;
    virtual void  draw( )                    = 0;
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
    void  move( float dx, float dy );
    void  zoom( float x );
    float area( );
    void  draw( );

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
    void  move( float dx, float dy );
    void  zoom( float x );
    float area( );
    void  draw( );

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
    void  move( float dx, float dy );
    void  zoom( float x );
    float area( );
    void  draw( );

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
    void  move( float dx, float dy );
    void  zoom( float x );
    float area( );
    void  draw( );

private:
    Point p1, p2, p3, p4;
};

#endif