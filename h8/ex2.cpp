/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#include "assignment.h"
#include "paint.h"
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

// Point class
Point::Point( )
{
    x = 0;
    y = 0;
    return;
}
Point::Point( double x, double y )
{
    this->x = x;
    this->y = y;
    return;
}
void Point::move( double dx, double dy )
{
    x += dx;
    y += dy;
    return;
}
void Point::zoom( double r )
{
    x *= r;
    y *= r;
    return;
}

// Triangle class
Triangle::Triangle( )
{
    p1 = Point( 0, 0 );
    p2 = Point( 0, 0 );
    p3 = Point( 0, 0 );
    return;
}
Triangle::Triangle( Point p1, Point p2, Point p3 )
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    return;
}
void Triangle::move( double dx, double dy )
{
    p1.move( dx, dy );
    p2.move( dx, dy );
    p3.move( dx, dy );
    return;
}
void Triangle::zoom( double r )
{
    p1.zoom( r );
    p2.zoom( r );
    p3.zoom( r );
    return;
}
double Triangle::area( )
{
    // using Heron's formula
    double a = p1.length( p2 );
    double b = p2.length( p3 );
    double c = p3.length( p1 );
    double p = a + b + c;
    return sqrt( p * ( p - a ) * ( p - b ) * ( p - c ) );
}
void Triangle::draw( )
{
    glColor3f( 255, 255, 255 );
    glBegin( GL_QUADS );
    glVertex2f( p1.getx( ), p1.gety( ) );
    glVertex2f( p2.getx( ), p2.gety( ) );
    glVertex2f( p3.getx( ), p3.gety( ) );
    glEnd( );
    return;
}

// Rectangle class
Rectangle::Rectangle( )
{
    p1 = Point( 0, 0 );
    p2 = Point( 0, 0 );
    return;
}
Rectangle::Rectangle( Point p1, Point p2 )
{
    this->p1 = p1;
    this->p2 = p2;
    return;
}
void Rectangle::move( double dx, double dy )
{
    p1.move( dx, dy );
    p2.move( dx, dy );
    return;
}
void Rectangle::zoom( double r )
{
    p1.zoom( r );
    p2.zoom( r );
    return;
}
double Rectangle::area( )
{
    return fabs( ( p1.getx( ) - p2.getx( ) ) ) * fabs( ( p1.gety( ) - p2.gety( ) ) );
}
void Rectangle::draw( )
{
    glColor3f( 255, 255, 255 );
    glBegin( GL_QUADS );
    glVertex2f( p1.getx( ), p1.gety( ) );
    glVertex2f( p2.getx( ), p1.gety( ) );
    glVertex2f( p2.getx( ), p2.gety( ) );
    glVertex2f( p1.getx( ), p2.gety( ) );
    glEnd( );
    return;
}

// Parallelogram class
Parallelogram::Parallelogram( )
{
    p1 = Point( 0, 0 );
    p2 = Point( 0, 0 );
    p3 = Point( 0, 0 );
    p4 = Point( 0, 0 );
    return;
}
Parallelogram::Parallelogram( Point p1, Point p2, Point p3, Point p4 )
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;
    return;
}
void Parallelogram::move( double dx, double dy )
{
    p1.move( dx, dy );
    p2.move( dx, dy );
    p3.move( dx, dy );
    p4.move( dx, dy );
    return;
}
void Parallelogram::zoom( double r )
{
    p1.zoom( r );
    p2.zoom( r );
    p3.zoom( r );
    p4.zoom( r );
    return;
}
double Parallelogram::area( )
{
    Triangle a, b;
    a = Triangle( p1, p2, p3 );
    b = Triangle( p2, p3, p4 );
    return a.area( ) + b.area( );
}
void Parallelogram::draw( )
{
    glColor3f( 255, 255, 255 );
    glBegin( GL_QUADS );
    glVertex2f( p1.getx( ), p1.gety( ) );
    glVertex2f( p2.getx( ), p2.gety( ) );
    glVertex2f( p3.getx( ), p3.gety( ) );
    glVertex2f( p4.getx( ), p4.gety( ) );
    glEnd( );
    return;
}

// Trapezium class
Trapezium::Trapezium( )
{
    p1 = Point( 0, 0 );
    p2 = Point( 0, 0 );
    p3 = Point( 0, 0 );
    p4 = Point( 0, 0 );
    return;
}
Trapezium::Trapezium( Point p1, Point p2, Point p3, Point p4 )
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;
    return;
}
void Trapezium::move( double dx, double dy )
{
    p1.move( dx, dy );
    p2.move( dx, dy );
    p3.move( dx, dy );
    p4.move( dx, dy );
    return;
}
void Trapezium::zoom( double r )
{
    p1.zoom( r );
    p2.zoom( r );
    p3.zoom( r );
    p4.zoom( r );
    return;
}
double Trapezium::area( )
{
    Triangle a, b;
    a = Triangle( p1, p2, p3 );
    b = Triangle( p2, p3, p4 );
    return a.area( ) + b.area( );
}
void Trapezium::draw( )
{
    glColor3f( 255, 255, 255 );
    glBegin( GL_QUADS );
    glVertex2f( p1.getx( ), p1.gety( ) );
    glVertex2f( p2.getx( ), p2.gety( ) );
    glVertex2f( p3.getx( ), p3.gety( ) );
    glVertex2f( p4.getx( ), p4.gety( ) );
    glEnd( );
    return;
}
void TimeStep( int n )
{
    glutTimerFunc( n, TimeStep, n );
    glutPostRedisplay( );
}
void glDraw( )
{
    double static width = 1, height = 1.5, owidth = .175;
    Trapezium zh( { 0, 25 }, { 0, 5 }, { 15, 25 }, { 15, 26 } );
    zh.zoom( 2 );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    zh.draw( );
    glutSwapBuffers( );
    glFlush( );
}
int main( int argc, char *argv [] )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE );
    glutCreateWindow( "Demo draw" );
    glClearColor( 1.0, 1.0, 1.0, 0.0 );
    glClear( GL_COLOR_BUFFER_BIT );
    glutDisplayFunc( glDraw );
    glutTimerFunc( 25, TimeStep, 25 );
    glutMainLoop( );
}