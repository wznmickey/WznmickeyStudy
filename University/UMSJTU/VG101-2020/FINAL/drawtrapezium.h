/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef DRAWTRAPEZIUM_mickey_H
#define DRAWTRAPEZIUM_mickey_H

#include "drawcolor.h"
#include "trapezium.h"
#include <GL/glut.h>
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
#endif