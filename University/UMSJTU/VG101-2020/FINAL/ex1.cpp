#include "assignment.h"
using namespace std;




/*void TimeStep( int n )
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
-lglut -lGL
*/