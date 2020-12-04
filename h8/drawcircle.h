/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef DRAWCIRCLE_mickey_H
#define DRAWCIRCLE_mickey_H

#include "circle.h"
void Circle::draw( )
{
    glColor3f( 0.5, 0.5, 0.5 );
    glBegin( GL_POLYGON );
    for ( int i = 0; i < CIRCLE_LENGTH; i++ )
    { glVertex2f( p1.getx( ) + r * cos( 2 * PI / CIRCLE_LENGTH * i ), p1.gety( ) + r * sin( 2 * PI / CIRCLE_LENGTH * i ) ); }
    glEnd( );
    return;
}

#endif
