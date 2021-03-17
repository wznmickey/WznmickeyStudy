/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#ifndef DRAWCOLOR_mickey_H
#define DRAWCOLOR_mickey_H
#include "color.h"
#include <GL/glut.h>
void Color::set( )
{
    glColor4f( red, green, blue, alpha );
    return;
}
#endif