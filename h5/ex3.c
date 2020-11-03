#include "assignment.h"
// ex. 3 function: disptach work to other functions for exercise 3
void ex3( )
{
    char  s [ 10010 ]; // avoid potential out of memory
    char  w [ 10010 ]; // avoid potential out of memory
    char *get_1 = fgets( s, 10010, stdin );
    int   get_2 = scanf( "%s", w );
    if ( *get_1 == 0 && get_2 == -1 ) return;
    int   index_s = 0;
    int   index_w = 0;
    int   ls      = ( int ) strlen( s ); // MAX==10000
    int   lw      = ( int ) strlen( w ); // MAX==10000
    _Bool flag;
    int   ans = 0;
    /*delete because of misunderstanding the requirement
    for ( int i = 0; i < ls; i++ )
        if ( s [ i ] >= 'A' && s [ i ] <= 'Z' ) s [ i ] = ( char ) ( s [ i ] - 'A' + 'a' );
    for ( int i = 0; i < lw; i++ )
        if ( word [ i ] >= 'A' && word [ i ] <= 'Z' ) word [ i ] = ( char ) ( word [ i ] - 'A' + 'a' );
    int ans      = 0;
    s [ ls - 1 ] = ' '; // avoid to compare with none defined data
    s [ ls ]     = '\0';
    for ( index_s = 0; index_s < ls; index_s++ )
    {
        if ( s [ index_s ] != word [ index_w ] )
        {
            while ( s [ index_s ] != ' ' ) index_s++;
            index_w = 0;
        }
        else
        {
            if ( ( index_w == lw - 1 ) && ! ( ( s [ index_s + 1 ] <= 'z' ) && ( s [ index_s + 1 ] >= 'a' ) ) )
            {
                ans++;
                index_w = 0;
            }
            else
                index_w++;
        }
    }
    */
    for ( index_s = 0; index_s < ls; index_s++ )
    {
        flag = true;
        for ( index_w = 0; index_w < lw; index_w++ )
        {
            if ( ( index_s + index_w < ls ) && ( s [ index_s + index_w ] != w [ index_w ] ) )
            {
                flag = false;
                break;
            }
        }
        if ( flag ) ans++;
    }
    printf( "The string '%s' occurs %d times", w, ans );
    return;
}
#ifdef JOJ
int main( )
{
    ex3( );
    return 0;
}
#endif
