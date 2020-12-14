#include "assignment.h"

// ex. 2 function: disptach work to other functions for exercise 2
void ex2( )
{
    com1 Cartesian [ 6 ] = { { 3, 4.0 / 5.0 }, { 0, log( 4 ) }, { 45.245, 0.235 } };
    com2 Polar [ 6 ]     = { { 3, 4.0 / 5.0 }, { 0, log( 4 ) }, { 45.245, 0.235 }, { 3, PI / 17 }, { 4, PI / 9 }, { 1, PI / 12 } };
    C2P( Cartesian, Polar, 3 );
    P2C( Cartesian, Polar, 6 );
    for ( int i = 0; i < 3; i++ )
    {
        if ( Cartesian [ i ].b > 0 ) printf( "%.5lf+%.5lfi", Cartesian [ i ].a, Cartesian [ i ].b );
        else
            printf( "%.5lf%.5lfi", Cartesian [ i ].a, Cartesian [ i ].b );
        printf( " " );
        printf( "%.5lfe%.5lfi", Polar [ i ].r, Polar [ i ].t );
        printf( "\n" );
    }
    for ( int i = 3; i < 6; i++ )
    {
        if ( i == 4 )
        {
            if ( Cartesian [ i ].b > 0 ) printf( "%.5lf+%.5lfi", Cartesian [ i ].a, Cartesian [ i ].b );
            else
                printf( "%.5lf%.5lfi", Cartesian [ i ].a, Cartesian [ i ].b );
            printf( " " );
            printf( "%.5lfe%.5lfi", Polar [ i ].r, Polar [ i ].t );
            printf( "\n" );
        }
        else
        {
            printf( "%.5lfe%.5lfi", Polar [ i ].r, Polar [ i ].t );
            printf( " " );
            if ( Cartesian [ i ].b > 0 ) printf( "%.5lf+%.5lfi", Cartesian [ i ].a, Cartesian [ i ].b );
            else
                printf( "%.5lf%.5lfi", Cartesian [ i ].a, Cartesian [ i ].b );
            printf( "\n" );
        }
    }
    return;
}

#ifdef JOJ
int main( )
{
    ex2( );
    return 0;
}
#endif

void C2P( com1 *x, com2 *y, int n )
{
    for ( int i = 0; i < n; i++ )
    {
        double r  = sqrt( x [ i ].a * x [ i ].a + x [ i ].b * x [ i ].b );
        double t  = atan( x [ i ].b / x [ i ].a );
        y [ i ].r = r;
        y [ i ].t = t;
    }
    return;
}
void P2C( com1 *x, com2 *y, int n )
{
    for ( int i = 0; i < n; i++ )
    {
        double a  = y [ i ].r * cos( y [ i ].t );
        double b  = y [ i ].r * sin( y [ i ].t );
        x [ i ].a = a;
        x [ i ].b = b;
    }
    return;
}
