#include "p2_vector.h"
#include "p2_ass.h"
void newSet( cv **set, int x )
{
    ( **set ).elem = calloc( x, ( unsigned long ) sizeof( scard ) );
    ( **set ).card = 0;
    return;
}
void deletSet( cv **set )
{
    free( ( *set )->elem );
    free( *set );
    return;
}

void addElem( scard *elem, cv *set )
{
    // if ( check( elem, set ) != -1 ) return;
    if ( ( ( ( set->card ) % INITSETSIZE ) == 0 ) && ( set->card != 0 ) )
        set->elem = realloc( set->elem, ( unsigned long ) ( ( unsigned long ) set->card + INITSETSIZE ) * ( ( unsigned long ) ( sizeof( scard ) ) ) );
    set->card++;
    *( ( scard * ) ( set->elem ) + ( ( set->card ) - 1 ) ) = *( scard * ) elem;
    return;
}
void remElem( scard *elem, cv *set )
{
    if ( check( elem, set ) == -1 ) return;
    swap_scard( ( ( scard * ) ( set->elem ) + check( elem, set ) ), ( ( scard * ) ( set->elem ) + ( ( set->card ) - 1 ) ) );
    set->card--;
    if ( ( ( ( set->card ) % INITSETSIZE ) == 0 ) && ( set->card != 0 ) )
        set->elem = realloc( set->elem, ( unsigned long ) ( set->card * ( sizeof( scard ) ) ) );
    return;
}
int check( scard *x, cv *set )
{
    for ( int i = 0; i < ( set )->card; i++ )
    {
        if ( ( ( *( scard * ) x ).suit == ( *( ( scard * ) ( ( set )->elem ) + i ) ).suit )
             && ( ( *( scard * ) x ).suit == ( *( ( scard * ) ( ( set )->elem ) + i ) ).suit ) )
            return i;
    }
    return -1;
}
