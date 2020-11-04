#include "p2_ass.h"

int main( int argc, char *argv [] )
{

    options input_option = get_info( argc, argv );
    sdeck * unhave       = ( sdeck * ) malloc( sizeof( sdeck ) + 52 * input_option.d * sizeof( scard ) );
    unhave->no           = -1;
    unhave->num          = input_option.d * 52;
    splayer player [ input_option.n ];

    srand_init( );
    card_init( unhave->card, unhave->num );
    player_init( player, input_option.n );

    splayer ondesk;
    ondesk.num_card = 0;

    shuffle( unhave->card, unhave->card + unhave->num );
    player_get_card( player, input_option.n, input_option.c, unhave );
    int   now_player = check_first( player, input_option.n, unhave );
    scard now_card   = take_card( &ondesk, unhave );
    printf( "First card:" );
    disp( &now_card, 1 );
    printf( "\n" );
    _Bool win = false;
    while ( ! win ) { now_player = ( now_player + 1 ) % input_option.n; }
    // disp( unhave->card, unhave->num );
    free( unhave );
    return 0;
}

void srand_init( )
{
    srand( time( NULL ) );
    return;
}
void card_init( scard card [], int d )
{

    for ( int i = 0; i < d; i++ )
    {
        card [ i ].rank = i % 13;
        card [ i ].suit = i / 13 % 4;
    }
    return;
}
void disp( scard card [], int n )
{
    char suit [ 4 ][ 9 ]  = { "Spades", "Hearts", "Diamonds", "Clubs" };                                      // MAX="Diamonds\0"
    char rank [ 13 ][ 6 ] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" }; // MAX="QUEEN\0"
    for ( int i = 0; i < n - 1; i++ ) { printf( "%s %s,", suit [ card [ i ].suit ], rank [ card [ i ].rank ] ); }
    printf( "%s %s", suit [ card [ n - 1 ].suit ], rank [ card [ n - 1 ].rank ] );
    return;
}
void wait_player( char name [], char key )
{
    int c;
    if ( OS == 0 ) printf( "\033[0;33m" );
    printf( "[ASK INPUT]PLEASE PRESS %s TO CONTINUE", name );
    while ( ( c = fgetc( stdin ) ) != EOF )
    {
        if ( c == key )
        {
            if ( OS == 0 ) printf( "\033[0;32m" );
            printf( "[RECEIVE INPUT]YOU HAVE PRESSED %s\n", name );
            if ( OS == 0 ) printf( "\033[0m" );
            return;
        }
    }
    return;
}
void shuffle( scard *first, scard *last )
{
    for ( scard *i = first; i < last; i++ ) { swap_scard( i, rand( ) % ( ( last - i ) ) + i ); }
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
    if ( get_card_no( arg1 ) < get_card_no( arg2 ) ) return -1;
    if ( get_card_no( arg1 ) > get_card_no( arg2 ) ) return 1;
    return 0;
}
options option_init( )
{
    options temp;
    temp.auto_run = false;
    temp.help     = false;
    temp.c        = 5;
    temp.d        = 2;
    temp.n        = 4;
    temp.r        = 1;
    strcpy( temp.filename, "onecard.log" );
    return temp;
}
options get_info( int argc, char *argv [] )
{
    int           get_index;
    int           option_index       = 0;
    options       input_option       = option_init( );
    struct option long_options [ 8 ] = {
        { "auto", 0, NULL, 'a' },
        { "help", 0, NULL, 'h' },
        { "log", 1, NULL, 'l' },
        { "player-number", 1, NULL, 'n' },
        { "initial-cards", 1, NULL, 'c' },
        { "decks", 1, NULL, 'd' },
        { "rounds", 1, NULL, 'r' },
        { 0, 0, 0, 0 },
    };
    while ( ( get_index = getopt_long( argc, argv, "ahn:c:d:r:", long_options, &option_index ) ) != -1 )
    {
        switch ( get_index )
        {
            case 'a':
                printf( "Start auto mode.\n" );
                input_option.auto_run = true;
                break;
            case 'h':
                printf( "Open help.\n" );
                input_option.help = true;
                break;
            case 'l':
                printf( "file name=%s\n", optarg );
                strcpy( input_option.filename, optarg );
                break;
            case 'n':
                input_option.n = atol( optarg );
                printf( "number=%d\n", input_option.n );
                break;
            case 'c':
                input_option.c = atol( optarg );
                printf( "cards=%d\n", input_option.c );
                break;
            case 'd':
                input_option.d = atol( optarg );
                printf( "decks=%d\n", input_option.d );
                break;
            case 'r':
                input_option.r = atol( optarg );
                printf( "rounds=%d\n", input_option.r );
                break;
            default:
                if ( OS == 0 ) printf( "\033[0;31m" );
                printf( "WRONG OPTION(s) \n" );
                if ( OS == 0 ) printf( "\033[0m" );
                break;
        }
    }
    return input_option;
}
int check_first( splayer player [], int n, sdeck *unhave )
{
    struct _temp
    {
        int no, player;
    } temp;
    temp.no     = 100;
    temp.player = 0;
    printf( "Determining the playing order...\n" );
    for ( int i = 0; i < n; i++ )
    {
        scard card = take_card( &player [ i ], unhave );
        printf( "Player %d:", i + 1 );
        disp( &card, 1 );
        if ( card.rank < temp.no )
        {
            temp.no     = card.rank;
            temp.player = i;
        }
        printf( "\n" );
    }
    printf( "The game will start with player %d\n", temp.player + 1 );
    return temp.player;
}
void player_init( splayer player [], int n )
{
    for ( int i = 0; i < n; i++ ) { player [ i ].num_card = 0; }
    return;
}
scard take_card( splayer *player, sdeck *unhave )
{
    scard card;
    // if (unhave->num==0) reset(unhave,);
    card = unhave->card [ unhave->num - 1 ];
    unhave->num--;
    player->card [ player->num_card++ ] = card;
    return card;
}
int get_card_no( scard card )
{
    return ( card.suit * 13 + card.rank );
}
void player_get_card( splayer player [], int n, int c, sdeck *unhave )
{
    printf( "Dealing cards...\n" );
    for ( int i = 0; i < n; i++ )
    {
        printf( "Player %d:", i + 1 );
        scard card [ n ];
        for ( int j = 0; j < c; j++ ) { card [ j ] = take_card( &player [ i ], unhave ); }
        disp( card, c );
        printf( "\n" );
    }
}