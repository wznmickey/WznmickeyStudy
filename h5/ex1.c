#include "assignment.h"
// ex. 1 function: disptach work to other functions for exercise 1
inline void ex1( )
{
    int          temp;
    int          get_ans = scanf( "%d", &temp );
    register int a       = temp;
    if ( get_ans == -1 ) return;
    if ( a <= 2 ) return;
    unsigned char *bitmap = ( unsigned char * ) calloc( ( unsigned long int ) ( ( a >> 3 ) + 1 ), sizeof( unsigned char ) );
    int            sq     = ( int ) sqrt( a );
    static int     ans [ 2000005 ]; // contain the prime ans
    int            index = 0;
    // avoid to check 2 and all even number
    ans [ 0 ] = 2;
    printf( "2" );
    if ( a == 3 ) return;
    register int i;
    for ( i = 3; i <= sq; i += 2 )
    {
        if ( ! check_prime( i ) )
        {
            for ( int j = i * i; j < a; j += i ) { not_prime( j ); }
            printf( " %d", i );
            ans [ index++ ] = i;
        }
    }
    for ( ; i < a; i += 2 )
    {
        if ( ! check_prime( i ) )
        {
            printf( " %d", i );
            ans [ index++ ] = i;
        }
    }
    free( bitmap );
    if ( true || ans [ 0 ] == 2 ) return; // avoid warning that ans is not used
}
#ifdef JOJ
int main( )
{
    ex1( );
    return 0;
}
#endif
