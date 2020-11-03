#include "assignment.h"
// ex. 5 function: disptach work to other functions for exercise 5
void ex5( )
{
    srand_init( );
    scard card [ 52 ];

    // first deck
    card_init( card );
    disp( card );
    wait_player( "ENTER", '\n' );
    // second deck
    shuffle( card, card + 52 );
    disp( card );
    wait_player( "ENTER", '\n' );
    // third deck
    qsort( card, 52, sizeof( scard ), compare_scard );
    disp( card );
    wait_player( "ENTER", '\n' );

    return;
}
void srand_init( )
{
    srand( time( NULL ) );
    return;
}
void card_init( scard card [] )
{
    for ( int i = 0; i < 52; i++ )
    {
        card [ i ].rank = i % 13;
        card [ i ].suit = i / 13;
    }
    return;
}
void disp( scard card [] )
{
    char suit [ 4 ][ 9 ]  = { "Spades", "Hearts", "Diamonds", "Clubs" };                                      // MAX="Diamonds\0"
    char rank [ 13 ][ 6 ] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" }; // MAX="QUEEN\0"
    for ( int i = 0; i < 52; i++ ) { printf( "%s %s\n", suit [ card [ i ].suit ], rank [ card [ i ].rank ] ); }
    return;
}
void wait_player( char name [], char key )
{
    int c;
    printf( "\033[0;33mASK INPUT]PLEASE PRESS %s TO CONTINUE", name );
    while ( ( c = fgetc( stdin ) ) != EOF )
    {
        if ( c == key )
        {
            printf( "\033[0;32m[RECEIVE INPUT]YOU HAVE PRESSED %s", name );
            printf("\033[0m"); 
            return;
        }
    }
    return;
}
void shuffle( scard *first, scard *last )
{
    for ( scard *i = last - 1; i >= first; i-- )
    {
        int temp = rand( ) % ( ( i - first ) / sizeof( scard ) + 1 );
        swap_scard( i, first + temp );
    }
    return;
}
void swap_scard( scard *a, scard *b )
{
    scard temp = *a;
    *a         = *b;
    *b         = temp;
    return;
}
int compare_scard( const void *a, const void *b )
{
    scard arg1 = *( const scard * ) a;
    scard arg2 = *( const scard * ) b;

    if ( arg1.suit * 13 + arg1.rank < arg2.suit * 13 + arg2.rank ) return -1;
    if ( arg1.suit * 13 + arg1.rank > arg2.suit * 13 + arg2.rank ) return 1;
    return 0;
}
//#ifdef JOJ
int main( )
{
    ex5( );
    return 0;
}
//#endif
