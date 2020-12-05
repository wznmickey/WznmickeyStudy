/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef DRAWTRIANGLE_mickey_H
#define DRAWTRIANGLE_mickey_H
#include "drawcolor.h"
#include "triangle.h"
#include <GL/glut.h>
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

#endif