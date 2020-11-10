#include "assignment.h"
#include "universal_set.h"
// ex. 5 function: disptach work to other functions for exercise 5
void ex5( )
{
    return;
}
void newSet( uset **set, int type )
{
    ( **set ).elem = calloc( INITSETSIZE, ( unsigned long ) type );
    ( **set ).type = type;
    ( **set ).card = 0;
    return;
}
void deletSet( uset **set )
{
    free( ( *set )->elem );
    free( *set );
    return;
}
void addElem( void *elem, uset *set )
{
    if ( check( elem, set ) != -1 ) return;
    if ( ( ( ( set->card ) % INITSETSIZE ) == 0 ) && ( set->card != 0 ) )
        set->elem = realloc( set->elem, ( unsigned long ) ( ( unsigned long ) set->card + INITSETSIZE ) * ( unsigned long ) ( set->type ) );
    set->card++;
    if ( ( ( *set ).type ) == CHAR ) { *( ( char * ) ( set->elem ) + ( ( set->card ) - 1 ) ) = *( char * ) elem; }
    if ( ( ( *set ).type ) == INT ) { *( ( int * ) ( set->elem ) + ( ( set->card ) - 1 ) ) = *( int * ) elem; }
    if ( ( ( *set ).type ) == DOUBLE ) { *( ( double * ) ( set->elem ) + ( ( set->card ) - 1 ) ) = *( double * ) elem; }
    return;
}
void remElem( void *elem, uset *set )
{
    if ( check( elem, set ) == -1 ) return;
    if ( ( ( *set ).type ) == CHAR ) { swap_char( ( ( char * ) ( set->elem ) + check( elem, set ) ), ( ( char * ) ( set->elem ) + ( ( set->card ) - 1 ) ) ); }
    if ( ( ( *set ).type ) == INT ) { swap_int( ( ( int * ) ( set->elem ) + check( elem, set ) ), ( ( int * ) ( set->elem ) + ( ( set->card ) - 1 ) ) ); }
    if ( ( ( *set ).type ) == DOUBLE )
    { swap_double( ( ( double * ) ( set->elem ) + check( elem, set ) ), ( ( double * ) ( set->elem ) + ( ( set->card ) - 1 ) ) ); }
    set->card--;
    if ( ( ( ( set->card ) % INITSETSIZE ) == 0 ) && ( set->card != 0 ) ) set->elem = realloc( set->elem, ( unsigned long ) ( set->card * ( set->type ) ) );
    return;
}
int check( void *x, uset *set )
{
    if ( ( ( *set ).type ) == CHAR )
    {
        for ( int i = 0; i < ( set )->card; i++ )
        {
            if ( ( *( char * ) x ) == *( ( char * ) ( ( set )->elem ) + i ) ) return i;
        }
    }
    if ( ( ( *set ).type ) == INT )
    {
        for ( int i = 0; i < ( set )->card; i++ )
        {
            if ( ( *( int * ) x ) == *( ( int * ) ( ( set )->elem ) + i ) ) return i;
        }
    }
    if ( ( *set ).type == DOUBLE )
    {
        for ( int i = 0; i < ( set )->card; i++ )
        {
            if ( ( *( double * ) x ) == *( ( double * ) ( ( set )->elem ) + i ) ) return i;
        }
    }
    return -1;
}
void swap_char( char *x, char *y )
{
    char temp = *x;
    *x        = *y;
    *y        = temp;
    return;
}
void swap_int( int *x, int *y )
{
    int temp = *x;
    *x       = *y;
    *y       = temp;
    return;
}
void swap_double( double *x, double *y )
{
    double temp = *x;
    *x          = *y;
    *y          = temp;
    return;
}
