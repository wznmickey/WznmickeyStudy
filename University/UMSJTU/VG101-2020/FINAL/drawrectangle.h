/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef DRAWRECTANGLE_mickey_H
#define DRAWRECTANGLE_mickey_H
#include "drawcolor.h"
#include "rectangle.h"
#include <GL/glut.h>
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

#endif