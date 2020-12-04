/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#include "assignment.h"
#include "paint.h"
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

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
void Triangle::move( float dx, float dy )
{
    p1.move( dx, dy );
    p2.move( dx, dy );
    p3.move( dx, dy );
    return;
}
void Triangle::zoom( float r )
{
    p1.zoom( r );
    p2.zoom( r );
    p3.zoom( r );
    return;
}
float Triangle::area( )
{
    // using Heron's formula
    float a = p1.length( p2 );
    float b = p2.length( p3 );
    float c = p3.length( p1 );
    float p = a + b + c;
    return sqrt( p * ( p - a ) * ( p - b ) * ( p - c ) );
}
void Triangle::draw( )
{
    glColor3f( 0.5, 0.5, 0.5 );
    glBegin( GL_POLYGON );
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
void Rectangle::move( float dx, float dy )
{
    p1.move( dx, dy );
    p2.move( dx, dy );
    return;
}
void Rectangle::zoom( float r )
{
    p1.zoom( r );
    p2.zoom( r );
    return;
}
float Rectangle::area( )
{
    return fabs( ( p1.getx( ) - p2.getx( ) ) ) * fabs( ( p1.gety( ) - p2.gety( ) ) );
}
void Rectangle::draw( )
{
    glColor3f( 0.5, 0.5, 0.5 );
    glBegin( GL_POLYGON );
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
void Parallelogram::move( float dx, float dy )
{
    p1.move( dx, dy );
    p2.move( dx, dy );
    p3.move( dx, dy );
    p4.move( dx, dy );
    return;
}
void Parallelogram::zoom( float r )
{
    p1.zoom( r );
    p2.zoom( r );
    p3.zoom( r );
    p4.zoom( r );
    return;
}
float Parallelogram::area( )
{
    Triangle a, b;
    a = Triangle( p1, p2, p3 );
    b = Triangle( p2, p3, p4 );
    return a.area( ) + b.area( );
}
void Parallelogram::draw( )
{
    glColor3f( 0.5, 0.5, 0.5 );
    glBegin( GL_POLYGON );
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
void Trapezium::move( float dx, float dy )
{
    p1.move( dx, dy );
    p2.move( dx, dy );
    p3.move( dx, dy );
    p4.move( dx, dy );
    return;
}
void Trapezium::zoom( float r )
{
    p1.zoom( r );
    p2.zoom( r );
    p3.zoom( r );
    p4.zoom( r );
    return;
}
float Trapezium::area( )
{
    Triangle a, b;
    a = Triangle( p1, p2, p3 );
    b = Triangle( p2, p3, p4 );
    return a.area( ) + b.area( );
}
void Trapezium::draw( )
{
    glColor3f( 0.5, 0.5, 0.5 );
    glBegin( GL_POLYGON );
    glVertex2f( p1.getx( ), p1.gety( ) );
    glVertex2f( p2.getx( ), p2.gety( ) );
    glVertex2f( p3.getx( ), p3.gety( ) );
    glVertex2f( p4.getx( ), p4.gety( ) );
    glEnd( );
    return;
}
void TimeStep( int n )
{
    glutTimerFunc( ( unsigned int ) n, TimeStep, ( int ) n );
    glutPostRedisplay( );
}
void glDraw( )
{
    Trapezium zh( { ( float ) 0.2, ( float ) 0.5 }, { ( float ) 0.2, ( float ) 0.2 }, { ( float ) 0.15, ( float ) 0.25 }, { ( float ) 0.15, ( float ) 0.5 } );
    zh.zoom( ( float ) 1.1 );
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
    return 0;
}