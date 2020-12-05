/***********************************
    Written by WANGZINING
    blog: https://wznmickey.com
***********************************/
#include "assignment.h"
#include "ex3_car.h"
#include "opengldraw.h"
using namespace std;

void TimeStep( int n )
{
    glutTimerFunc( ( unsigned int ) n, TimeStep, ( int ) n );
    glutPostRedisplay( );
}
void glDraw( )
{
    static Car  car  = Car( );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    car.draw( );
    glutSwapBuffers( );
    glFlush( );
    if ( car.get( ).getx( ) >= 0.55 ) car.reverse();
    if ( car.get( ).getx( ) <= -0.9 ) car.reverse();
    car.run(0.01);
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