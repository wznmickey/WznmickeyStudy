#include "assignment.h"
// ex. 6 function: disptach work to other functions for exercise 6
void ex6( )
{
    static char ch [ 1100005 ];
    static char chans [ 1100005 ];
    int         ans [ 1100005 ] = { 0 };
    int         fans;
    printf( "Input a string: " );
    char      ch1, ch2;
    char      temp;
    long long i = 0;
    while ( ( temp = ( char ) fgetc( stdin ) ) )
    {
        if ( temp != '\n' )
        {
            ch [ i ] = temp;
            i++;
        }
        else
            break;
    }
    printf( "* Choose 1 to replace a character or 2 to delete a character:   " );
    scanf( "%d", &fans );
    if ( fans == 1 )
    {
        printf( "Replace character:   " );
        while ( ( ch1 = ( char ) fgetc( stdin ) ) == ' ' || ch1 == '\n' )
            ;
        printf( "with: " );
        while ( ( ch2 = ( char ) fgetc( stdin ) ) == ' ' || ch2 == '\n' )
            ;
        long long str = ( long long ) strlen( ch );
        for ( long long i = 0; i < str; i++ )
        {
            if ( ch [ i ] == ch1 ) { ch [ i ] = ch2; }
        }
        printf( "New string: %s", ch );
    }
    else
    {
        register long long j = 1;
        ans [ 0 ]            = -1;
        printf( "Delete character: " );
        while ( ( ch1 = ( char ) fgetc( stdin ) ) == ' ' || ch1 == '\n' )
            ;
        printf( "New string: " );
        long long str = ( long long ) strlen( ch );
        for ( long long i = 0; i < str; i++ )
        {
            if ( ch [ i ] == ch1 )
            {
                ans [ j ] = ( int ) i;
                j++;
            }
        }
        ans [ j ]      = ( int ) strlen( ch ) + 1;
        register int k = 0;
        for ( long long i = 0; i < j; i++ )
        {
            memcpy( chans + k, ch + ans [ i ] + 1, ( unsigned long ) ( ans [ i + 1 ] - ans [ i ] - 1 ) );
            k += ( ans [ i + 1 ] - ans [ i ] - 1 );
        }
        printf( "%s", chans );
    }
    return;
}
#ifdef JOJ
int main( )
{
    ex6( );
    return 0;
}
#endif
