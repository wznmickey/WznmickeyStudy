/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#include "assignment.h"
#include <GL/glut.h>
#include <math.h>
using namespace std;
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
    Point( int x, int y )
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
class Color
{
public:
    Color( )
    {
        this->red   = 0;
        this->green = 0;
        this->blue  = 0;
        this->alpha = 1;
        return;
    }
    ~Color( )
    {
        return;
    }
    Color( double r, double g, double b )
    {
        this->red   = ( float ) r;
        this->green = ( float ) g;
        this->blue  = ( float ) b;
        this->alpha = ( float ) 1;
        return;
    }
    Color( double r, double g, double b, double a )
    {
        this->red   = ( float ) r;
        this->green = ( float ) g;
        this->blue  = ( float ) b;
        this->alpha = ( float ) a;
        return;
    }
    float getr( )
    {
        return red;
    }
    float getg( )
    {
        return green;
    }
    float getb( )
    {
        return blue;
    }
    float geta( )
    {
        return alpha;
    }
    void changer( float r )
    {
        this->red = r;
        return;
    }
    void changeg( float g )
    {
        this->green = g;
        return;
    }
    void changeb( float b )
    {
        this->blue = b;
        return;
    }
    void changea( float a )
    {
        this->alpha = a;
        return;
    }
    void set( );

private:
    float red, green, blue, alpha;
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
    Circle( Point p1, double r )
    {
        this->p1 = p1;
        this->r  = ( float ) r;
        this->c  = Color( );
        return;
    }
    Circle( Point p1, int r )
    {
        this->p1 = p1;
        this->r  = ( float ) r;
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
    Circle( Point p1, double r, Color c )
    {
        this->p1 = p1;
        this->r  = ( float ) r;
        this->c  = c;
        return;
    }
    Circle( Point p1, int r, Color c )
    {
        this->p1 = p1;
        this->r  = ( float ) r;
        this->c  = c;
        return;
    }
    void move( float dx, float dy )
    {
        p1.move( ( float ) dx, ( float ) dy );
        return;
    }
    void zoom( float r )
    {
        this->r *= r;
        return;
    }
    float area( )
    {
        return ( float ) PI * r * r;
    }
    float getr( )
    {
        return r;
    }
    Point getp( )
    {
        return p1;
    }
    Color getc( )
    {
        return c;
    }
    void draw( );

private:
    Point p1;
    float r;
    Color c;
};
void Circle::draw( )
{
    c.set( );
    glBegin( GL_POLYGON );
    for ( int i = 0; i < CIRCLE_LENGTH; i++ )
    {
        glVertex2f( p1.getx( ) + ( float ) r * ( float ) cos( 2 * PI / CIRCLE_LENGTH * i ),
                    p1.gety( ) + ( float ) r * ( float ) sin( 2 * PI / CIRCLE_LENGTH * i ) );
    }
    glEnd( );
    return;
}
class Triangle : public Shape
{
public:
    ~Triangle( )
    {
        return;
    }

    Triangle( )
    {
        p1 = Point( 0, 0 );
        p2 = Point( 0, 0 );
        p3 = Point( 0, 0 );
        c  = Color( );
        return;
    }
    Triangle( Point p1, Point p2, Point p3 )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        c        = Color( );
        return;
    }
    Triangle( Point p1, Point p2, Point p3, Color c )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->c  = c;
        return;
    }
    void move( float dx, float dy )
    {
        p1.move( dx, dy );
        p2.move( dx, dy );
        p3.move( dx, dy );
        return;
    }
    void zoom( float r )
    {
        p1.zoom( r );
        p2.zoom( r );
        p3.zoom( r );
        return;
    }
    float area( )
    {
        // using Heron's formula
        float a = p1.length( p2 );
        float b = p2.length( p3 );
        float c = p3.length( p1 );
        float p = a + b + c;
        return sqrt( p * ( p - a ) * ( p - b ) * ( p - c ) );
    }
    Point getp1( )
    {
        return p1;
    }
    Point getp2( )
    {
        return p2;
    }
    Point getp3( )
    {
        return p3;
    }
    Color getc( )
    {
        return c;
    }
    void draw( );

private:
    Point p1, p2, p3;
    Color c;
};
class Trapezium : public Shape
{
public:
    ~Trapezium( )
    {
        return;
    }

    Trapezium( )
    {
        p1 = Point( 0, 0 );
        p2 = Point( 0, 0 );
        p3 = Point( 0, 0 );
        p4 = Point( 0, 0 );
        c  = Color( );
        return;
    }
    Trapezium( Point p1, Point p2, Point p3, Point p4 )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
        c        = Color( );
        return;
    }
    Trapezium( Point p1, Point p2, Point p3, Point p4, Color c )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
        this->c  = c;
        return;
    }
    void move( float dx, float dy )
    {
        p1.move( dx, dy );
        p2.move( dx, dy );
        p3.move( dx, dy );
        p4.move( dx, dy );
        return;
    }
    void zoom( float r )
    {
        p1.zoom( r );
        p2.zoom( r );
        p3.zoom( r );
        p4.zoom( r );
        return;
    }
    float area( )
    {
        Triangle a, b;
        a = Triangle( p1, p2, p3 );
        b = Triangle( p2, p3, p4 );
        return a.area( ) + b.area( );
    }
    Point getp1( )
    {
        return p1;
    }
    Point getp2( )
    {
        return p2;
    }
    Point getp3( )
    {
        return p3;
    }
    Point getp4( )
    {
        return p4;
    }
    Color getc( )
    {
        return c;
    }
    void draw( );

private:
    Point p1, p2, p3, p4;
    Color c;
};
class Rectangle : public Shape
{
public:
    ~Rectangle( )
    {
        return;
    }

    Rectangle( )
    {
        p1      = Point( 0, 0 );
        p2      = Point( 0, 0 );
        this->c = Color( );
        return;
    }
    Rectangle( Point p1, Point p2 )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->c  = Color( );
        return;
    }
    Rectangle( Point p1, Point p2, Color c )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->c  = c;
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
    Point getp1( )
    {
        return p1;
    }
    Point getp2( )
    {
        return p2;
    }
    Color getc( )
    {
        return c;
    }
    void draw( );

private:
    Point p1, p2;
    Color c;
};
class Parallelogram : public Shape
{
public:
    ~Parallelogram( )
    {
        return;
    }

    Parallelogram( )
    {
        p1 = Point( 0, 0 );
        p2 = Point( 0, 0 );
        p3 = Point( 0, 0 );
        p4 = Point( 0, 0 );
        c  = Color( );
        return;
    }
    Parallelogram( Point p1, Point p2, Point p3, Point p4 )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
        this->c  = Color( );
        return;
    }
    Parallelogram( Point p1, Point p2, Point p3, Point p4, Color c )
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;
        this->c  = c;
        return;
    }
    void move( float dx, float dy )
    {
        p1.move( dx, dy );
        p2.move( dx, dy );
        p3.move( dx, dy );
        p4.move( dx, dy );
        return;
    }
    void zoom( float r )
    {
        p1.zoom( r );
        p2.zoom( r );
        p3.zoom( r );
        p4.zoom( r );
        return;
    }
    float area( )
    {
        Triangle a, b;
        a = Triangle( p1, p2, p3 );
        b = Triangle( p2, p3, p4 );
        return a.area( ) + b.area( );
    }
    Point getp1( )
    {
        return p1;
    }
    Point getp2( )
    {
        return p2;
    }
    Point getp3( )
    {
        return p3;
    }
    Point getp4( )
    {
        return p4;
    }
    Color getc( )
    {
        return c;
    }
    void draw( );

private:
    Point p1, p2, p3, p4;
    Color c;
};
void Triangle::draw( )
{
    c.set( );
    glBegin( GL_POLYGON );
    glVertex2f( p1.getx( ), p1.gety( ) );
    glVertex2f( p2.getx( ), p2.gety( ) );
    glVertex2f( p3.getx( ), p3.gety( ) );
    glEnd( );
    return;
}
void Color::set( )
{
    glColor4f( red, green, blue, alpha );
    return;
}
void Rectangle::draw( )
{
    c.set( );
    glBegin( GL_POLYGON );
    glVertex2f( p1.getx( ), p1.gety( ) );
    glVertex2f( p2.getx( ), p1.gety( ) );
    glVertex2f( p2.getx( ), p2.gety( ) );
    glVertex2f( p1.getx( ), p2.gety( ) );
    glEnd( );
    return;
}
void Trapezium::draw( )
{
    c.set( );
    glBegin( GL_POLYGON );
    glVertex2f( p1.getx( ), p1.gety( ) );
    glVertex2f( p2.getx( ), p2.gety( ) );
    glVertex2f( p3.getx( ), p3.gety( ) );
    glVertex2f( p4.getx( ), p4.gety( ) );
    glEnd( );
    return;
}
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
void TimeStep( int n )
{
    glutTimerFunc( ( unsigned int ) n, TimeStep, ( int ) n );
    glutPostRedisplay( );
}
void glDraw( )
{
    static Car car = Car( );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    car.draw( );
    glutSwapBuffers( );
    glFlush( );
    if ( car.get( ).getx( ) >= 0.55 ) car.reverse( );
    if ( car.get( ).getx( ) <= -0.9 ) car.reverse( );
    car.run( 0.01 );
}
int main( int argc, char *argv [] )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE );
    glutCreateWindow( "Demo draw" );
    glClearColor( 1.0, 1.0, 1.0, 0.0 );
    glClear( GL_COLOR_BUFFER_BIT );
    glutDisplayFunc( glDraw );
    glutTimerFunc( 50, TimeStep, 50 );
    glutMainLoop( );
    return 0;
}