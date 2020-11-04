#include "assignment.h"                                                                                         // add the library of ex6
void ex6( )                                                                                                     // define the function
{                                                                                                               // start of the function
    unsigned long int a, b;                                                                                     // define 2 num as the input
    srand( time( NULL ) );                                                                                      // prepare for get random number
#ifndef TEST                                                                                                    // In the fisrt case
    a = rand( );                                                                                                // get first num
    b = rand( );                                                                                                // get second num
    printf( "%ld*%ld=%ld %ld\n", a, b, mult( a, b ), RAND_MAX );                                                // print the result
#endif                                                                                                          // end of the first case
#ifdef TEST * /                                                                                                 // In the second case
    int i;                                                                                                      // define i as loop var
    for ( i = 0; i < 1000000; i++ )                                                                             // control the loop
    {                                                                                                           // start of the loop
        a = rand( );                                                                                            // get first num
        b = rand( );                                                                                            // get second num
        if ( mult( a, b ) != a * b )                                                                            // check the correctness
        {                                                                                                       // start of the wrong case
            fprintf( stderr, "Error (%d): a=%ld, b=%ld, a*b=%ld, k(a,b)=%ld\n", i, a, b, a * b, mult( a, b ) ); // print result that something wrong happened
            exit( -1 );                                                                                         // stop running
        }                                                                                                       // end of checking
    }                                                                                                           // end of loop
#endif                                                                                                          // end of the second case
    return;                                                                                                     // give the return value
} // end of the function
int divide( unsigned long long x, int l, int r )
{
    if ( r - l == 1 ) return l;
    int mid = ( l + r ) / 2;
    if ( ( 1 << mid ) > x ) return divide( x, l, mid );
    else
        return divide( x, mid, r );
}
unsigned long int mult( unsigned long int a, unsigned long int b )
{
    int               i, n, N;
    unsigned long int x0, y0, z0, z1 = 1;
    if ( a < b ) SWAP( a, b );
    if ( b == 0 ) return 0;
    n = divide( b, 0, 32 );
    i = 1 << ( n + 1 );
    for ( N = n; i <= a; i <<= 1, N++ )
        ;
    y0 = b & ( ( 1 << n ) - 1 );
    x0 = a & ( ( 1 << N ) - 1 );
    z0 = mult( x0, y0 );
    i  = N + n;
    return ( ( z1 << i ) + ( x0 << n ) + ( y0 << N ) + z0 );
}

/* original code
unsigned long int mult( unsigned long int a, unsigned long int b ) // define the function
{                                                                  // start of the function
    int               i, n, N;                                     // define vars used in the following code
    unsigned long int x0, y0, z0, z1 = 1;                          // define vars used in the following code
    if ( a < b ) SWAP( a, b );                                     // let a>=b
    if ( b == 0 ) return 0;                                        // * times 0 equal to 0;('*' refers to any number)
    for ( n = -1, i = 1; i <= b; i <<= 1, n++ )                    // calculate that which n make b==2^n+k(k>0,k<=2^n)
        ;                                                          // calculate that which n make b==2^n+k(k>0,k<=2^n)
    for ( N = n; i <= a; i <<= 1, N++ )                            // caculate that which N make a=2^N+k(k>0,k<-2^N)
        ;                                                          // caculate that which N make a=2^N+k(k>0,k<-2^N)
    y0 = b & ( ( 1 << n ) - 1 );                                   // calculate the third part
    x0 = a & ( ( 1 << N ) - 1 );                                   // calculate the second part
    z0 = mult( x0, y0 );                                           // calculate the first part
    i  = N + n;                                                    // calculate the final digit
    return ( ( z1 << i ) + ( x0 << n ) + ( y0 << N ) + z0 );       // calculate the result
} // end of the function
*/

#ifdef JOJ
int main( )
{
    ex6( );
    return 0;
}
#endif
