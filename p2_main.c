#include "p2_ass.h"

int main( int argc, char *argv [] )
{

    options input_option = get_info( argc, argv );
    sdeck * unhave       = ( sdeck * ) malloc( sizeof( sdeck ) + 52 * input_option.d * sizeof( scard ) );
    unhave->no           = -1;
    unhave->num          = input_option.d * 52;
    splayer player [ input_option.n ];
    for ( int i = 0; i < input_option.n; i++ ) { player [ i ].score = 0; }
    srand_init( );

    printf( "########################\n# #\n# Welcome to One Card! #\n# #\n########################\n---- Initial setup ----\n" );
    printf( "Number of rounds: %d\nNumber of decks: %d\nNumber of players: %d\n", input_option.r, input_option.d, input_option.n );
    printf( "\n" );
    FILE *filename = fopen( input_option.filename, "w" );
    fprintf( filename, "########################\n# #\n# Welcome to One Card! #\n# #\n########################\n---- Initial setup ----\n" );
    fprintf( filename, "Number of rounds: %d\nNumber of decks: %d\nNumber of players: %d\n", input_option.r, input_option.d, input_option.n );
    fprintf( filename, "\n" );
    for ( int round = 0; round < input_option.r; round++ )
    {
        card_init( unhave->card, unhave->num );
        player_init( player, input_option.n );
        splayer ondesk;
        ondesk.num_card = 0;
        printf( "Shuffling cards...\n" );
        fprintf( filename, "Shuffling cards...\n" );
        fprintf( filename, "Shuffle result: \n" ); //# shuffle result only displayed in log and demo mode
        // Spades 2, Spades 10, Hearts 2, Diamonds A, Clubs 3
        shuffle( unhave->card, unhave->card + unhave->num );
        fdisp( unhave->card, unhave->num, filename );
        player_get_card( player, input_option.n, input_option.c, unhave );
        printf( "Dealing cards...\n" );
        fprintf( filename, "Dealing cards...\n" );
        int     now_player = check_first( player, input_option.n, unhave );
        scard   now_card   = take_card( &ondesk, unhave );
        scard before_card_flag;
        before_card_flag.suit = 100;
        before_card_flag.rank = 100;
        seffect now_effect = get_effect( now_card ,before_card_flag);
        printf( "---- Game start ---\n" );
        printf( "First card:" );
        disp( &now_card, 1 );
        printf( "\n" );
        _Bool win     = false;
        _Bool reverse = false;
        
        // disp( unhave->card, unhave->num );
        while ( ! win )
        {

            if ( OS == 0 ) system( "clear" );
            if ( OS == 1 ) system( "cls" );
            if ( OS == 2 ) system( "clear" );
            win                          = win_check( player, input_option.n );
            now_effect                   = get_effect( now_card, before_card_flag );
            before_card_flag             = now_card;
            unhave->card [ unhave->num ] = now_card;
            unhave->num++;
            shuffle( unhave->card, unhave->card + unhave->num );
            printf( "now card:\n" );
            disp( &now_card, 1 );
            printf( "\n" );
            int temp_int;
            if ( now_effect.reverse == true ) reverse = ( ! reverse );
            if ( now_effect.skip == true )
            {

                printf( "SKIP\n" );
                if ( reverse == false ) now_player = ( now_player + 1 ) % input_option.n;
                else
                    now_player = ( now_player - 1 + input_option.n ) % input_option.n;
                continue;
            }
            if ( now_effect.get2 == true || now_effect.get3 == true )
            {
                if ( check_defense( player [ now_player ], &now_card ) == true )
                {
                    printf( "Next player\n" );
                    if ( reverse == false ) now_player = ( now_player + 1 ) % input_option.n;
                    else
                        now_player = ( now_player - 1 + input_option.n ) % input_option.n;
                    continue;
                }
                {
                    if ( now_effect.get2 == true ) s_player_get_card( player, now_player, 2, unhave );
                    if ( now_effect.get3 == true ) s_player_get_card( player, now_player, 3, unhave );
                    continue;
                }
                // printf("\nPlayer %d:You are required to draw cards. You have those card,plese choose one\n",now_player);
            }
            _Bool flag = false;
            while ( flag == false )
            {
                printf( "\nPlayer %d:you have those card,plese choose one\n", now_player + 1 );
                disp( ( player [ now_player ].card ), player [ now_player ].num_card );
                printf( "\nfrom 1 to %d, 0 to abandon", player [ now_player ].num_card );
                scanf( "%d", &temp_int );
                temp_int--;
                if ( temp_int == -1 )
                {
                    s_player_get_card( player, now_player, 1, unhave );
                    printf( "NEXT\n" );
                    flag = true;
                }
                else
                {
                    if ( check_okay( now_card, player [ now_player ].card [ temp_int ] ) == true )
                    {
                        now_card = player [ now_player ].card [ temp_int ];
                        card_remove( player [ now_player ].card, now_card, &player [ now_player ].num_card );
                        flag = true;
                    }
                    else
                    {
                        printf( "wrong\n" );
                    }
                }
            }
            if ( reverse == false ) now_player = ( now_player + 1 ) % input_option.n;
            else
                now_player = ( now_player - 1 + input_option.n ) % input_option.n;
        }
        printf( "----Stats--\n" );
        printf( "--Round %d result：\n", round + 1 );
        for ( int i = 0; i < input_option.n; i++ ) { printf( "Player %d:%d, total: %d\n", i + 1, player [ i ].last_score, player [ i ].score ); }
        printf( "\n round %d ends.\n", round + 1 );
    }
    free( unhave );
    fclose( filename );
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
    // scard card [ n ];
    // for ( int i = 0; i < n; i++ ) { card [ i ] = temp [ i ]; }
    char suit [ 4 ][ 9 ]  = { "Spades", "Hearts", "Diamonds", "Clubs" };                                      // MAX="Diamonds\0"
    char rank [ 13 ][ 6 ] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" }; // MAX="QUEEN\0"
    qsort( card, n, sizeof( scard ), compare_scard );
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
    return;
}
seffect get_effect( scard x, scard y )
{
    seffect ans;
    ans.get2    = false;
    ans.get3    = false;
    ans.reverse = false;
    ans.skip    = false;
    if ( ( x.suit == y.suit ) && ( x.rank == y.rank ) ) return ans;
    if ( x.rank == 0 ) ans.get2 = true;
    if ( x.rank == 1 ) ans.get2 = true;
    if ( x.rank == 5 )
    {
        ans.get2 = false;
        ans.get3 = false;
    }
    if ( x.rank == 10 ) ans.reverse = true;
    if ( x.rank == 9 ) ans.skip = true;
    return ans;
}
_Bool check_defense( splayer x, scard *card )
{
    int ans = 0;
    for ( int i = 0; i < x.num_card; i++ )
    {
        if ( x.card [ i ].rank == 5 ) { ans++; }
    }
    if ( ans == 0 ) return false;
    printf( "\n You can defend by following cards. input 0 to abandon, int from 1 to %d to play\n", ans );
    scard temp [ x.num_card ];
    int   index = 0;
    for ( int i = 0; i < x.num_card; i++ )
    {
        if ( x.card [ i ].rank == 5 )
        {
            temp [ index ] = x.card [ i ];
            index++;
        }
    }
    disp( temp, index - 1 );
    scanf( "%d", &index );
    index--;
    if ( index == -1 ) return false;
    *card = temp [ index ];
    card_remove( x.card, temp [ index ], &x.num_card );
    return true;
}
void card_remove( scard x [], scard ans, int *n )
{
    for ( int i = 0; i < ( *n ); i++ )
    {
        if ( ( x [ i ].suit == ans.suit ) && ( x [ i ].rank == ans.rank ) )
        {
            printf( "You played" );
            disp( &x [ ( *n ) - 1 ], 1 );
            printf( "\n" );
            swap_scard( &x [ ( *n ) - 1 ], &x [ i ] );
            ( *n )--;
            return;
        }
    }
    return;
}
void s_player_get_card( splayer player [], int n, int c, sdeck *unhave )
{
    printf( "Player %d draws:", n + 1 );
    scard card [ c ];
    for ( int j = 0; j < c; j++ ) { card [ j ] = take_card( &player [ n ], unhave ); }
    disp( card, c );
    printf( "\n" );
    return;
}
_Bool win_check( splayer x [], int n )
{
    _Bool ans = false;
    for ( int i = 0; i < n; i++ )
    {
        if ( x [ i ].num_card == 0 )
        {
            ans = true;
            printf( "player %d ", i + 1 );
        }
    }
    if ( ans == false ) return ans;
    printf( "wins!\n" );

    for ( int i = 0; i < n; i++ )
    {
        x [ i ].score -= x [ i ].num_card;
        x [ i ].last_score = -x [ i ].num_card;
    }
    return true;
}
_Bool check_okay( scard x, scard y )
{
    if ( ( x.suit == y.suit ) || ( x.rank == y.rank ) ) return true;
    return false;
}
void fdisp( scard card [], int n, FILE *x )
{
    // scard card [ n ];
    // for ( int i = 0; i < n; i++ ) { card [ i ] = temp [ i ]; }
    char suit [ 4 ][ 9 ]  = { "Spades", "Hearts", "Diamonds", "Clubs" };                          // MAX="Diamonds\0"
    char rank [ 13 ][ 3 ] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" }; // MAX="10\0"
    // qsort( card, n, sizeof( scard ), compare_scard );
    for ( int i = 0; i < n - 1; i++ ) { fprintf( x, "%s %s,", suit [ card [ i ].suit ], rank [ card [ i ].rank ] ); }
    fprintf( x, "%s %s", suit [ card [ n - 1 ].suit ], rank [ card [ n - 1 ].rank ] );
    return;
}