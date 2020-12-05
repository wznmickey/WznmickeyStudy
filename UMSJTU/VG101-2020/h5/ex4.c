#include "assignment.h"
// ex. 4 function: disptach work to other functions for exercise 4
void ex4( )
{
    double v, a, h, min, max;
    if ( scanf( "%lf%lf%lf%lf%lf", &v, &a, &h, &min, &max ) )
    {
        double th2 = -( 9.81 / ( 2 * v * v * cos( a / 180 * M_PI ) * cos( a / 180 * M_PI ) ) );
        double th1 = tan( a / 180 * M_PI );
        double th0 = h;
        while ( max - min > FLT_EPSILON )
        {
            double mid  = ( max + min ) / 2;
            double fmin = fx( min, th2, th1, th0 );
            double fmid = fx( mid, th2, th1, th0 );
            double fmax = fx( max, th2, th1, th0 );
            if ( fmin * fmid < 0 ) max = mid;
            else if ( fmax * fmid < 0 )
                min = mid;
            else if ( fabs( fmin ) <= FLT_EPSILON )
                printf( "%6lf", min );
            else if ( fabs( fmid ) <= FLT_EPSILON )
                printf( "%6lf", mid );
            else if ( fabs( fmax ) <= FLT_EPSILON )
                printf( "%6lf", max );
        }
        printf( "%6lf", max );
    }
    return;
}
inline double fx( double x, double th2, double th1, double th0 )
{
    return ( th2 * x * x + th1 * x + th0 );
}
#ifdef JOJ
int main( )
{
    ex4( );
    return 0;
}
#endif
