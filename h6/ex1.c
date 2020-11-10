#include "assignment.h"

// ex. 1 function: disptach work to other functions for exercise 1
void ex1( )
{
    function_ex1( );
    return;
}

#ifdef JOJ
int main( )
{
    ex1( );
    return 0;
}
#endif
void function_ex1( )
{
    int n;
    int get;
    int max_a = INT_MIN;
    get       = scanf( "%d", &n );
    int *a    = calloc( sizeof( int ), n );
    for ( int i = 0; i < n; i++ )
    {
        get = scanf( "%d", a + i );
        if ( max_a < a [ i ] ) max_a = a [ i ];
    }
    srand( time( NULL ) );
    int   r    = rand( ) % max_a;
    _Bool flag = false;
    for ( int i = 0; i < n; i++ )
    {
        if ( a [ i ] > r )
        {
            if ( flag == true ) { printf( " " ); }
            printf( "%d", a [ i ] );
            flag = true;
        }
    }
    free( a );
    return;
}