#include "p2_ass.h"

int main( int argc, char *argv [] )
{
    options input_option = get_info( argc, argv );
    if ( input_option.help == true )
    {
        printf(
            "-h|--help print this help message\n--log filename write the logs in filename (default: onecard.log)\n-n n|--player-number=n n players, n must be "
            "larger than 2 (default: 4)\n-c c|--initial-cards=c deal c cards per player, c must be at least 2 (default: 5)\n-d d|--decks=d use d decks 52 "
            "cards each, d must be at least 2 (default: 2)\n-r r|--rounds=r play r rounds, r must be at least 1 (default: 1)\n-a|--auto run in demo mode" );
        return 0;
    }
    FILE *filename;
    filename = fopen( input_option.filename, "w" );
    printf( "########################\n#                      #\n# Welcome to One Card! #\n#                      #\n########################\n" );
    fprintf( filename, "########################\n#                      #\n# Welcome to One Card! #\n#                      #\n########################\n" );
    sdeck *unhave   = ( sdeck * ) malloc( sizeof( sdeck ) + 52 * ( unsigned long long ) input_option.d * sizeof( scard ) );
    unhave->no      = -1;
    unhave->num     = input_option.d * 52;
    splayer *player = ( splayer * ) malloc( sizeof( splayer ) * ( unsigned long long ) input_option.n );
    for ( int i = 0; i < input_option.n; i++ )
    { player [ i ].card = ( scard * ) malloc( sizeof( scard ) * ( unsigned long long ) input_option.r * ( unsigned long long ) 52 ); }
    player_init( player, input_option.n );
    for ( int round = 0; round < input_option.r; round++ ) { oneround( input_option, filename, unhave, player, round ); }
    for ( int i = 0; i < input_option.n; i++ ) { free( player [ i ].card ); }
    free( unhave );
    free( player );
    fclose( filename );
    return 0;
}

void srand_init( )
{
    srand( ( unsigned int ) time( NULL ) );
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
    qsort( card, ( unsigned long int ) n, sizeof( scard ), compare_scard );
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
                input_option.help = true;
                break;
            case 'l':
                printf( "file name=%s\n", optarg );
                strcpy( input_option.filename, optarg );
                break;
            case 'n':
                input_option.n = ( int ) atol( optarg );
                printf( "number=%d\n", input_option.n );
                break;
            case 'c':
                input_option.c = ( int ) atol( optarg );
                printf( "cards=%d\n", input_option.c );
                break;
            case 'd':
                input_option.d = ( int ) atol( optarg );
                printf( "decks=%d\n", input_option.d );
                break;
            case 'r':
                input_option.r = ( int ) atol( optarg );
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
int check_first( splayer player [], int n, sdeck *unhave, FILE *x )
{
    struct _temp
    {
        int no, player;
    } temp;
    temp.no     = 100;
    temp.player = 0;
    printf( "Determining the playing order...\n" );
    fprintf( x, "Determining the playing order...\n" );
    for ( int i = 0; i < n; i++ )
    {
        scard card = take_card( &player [ i ], unhave );
        printf( "Player %d: ", i + 1 );
        fprintf( x, "Player %d: ", i + 1 );
        disp( &card, 1 );
        fdisp( &card, 1, x );
        if ( card.rank < temp.no )
        {
            temp.no     = card.rank;
            temp.player = i;
        }
        printf( "\n" );
        fprintf( x, "\n" );
    }
    printf( "The game will start with player %d\n", temp.player + 1 );
    fprintf( x, "The game will start with player %d\n", temp.player + 1 );
    return temp.player;
}
void player_init( splayer player [], int n )
{
    for ( int i = 0; i < n; i++ )
    {
        player [ i ].num_card   = 0;
        player [ i ].last_score = 0;
        player [ i ].score      = 0;
    }
    return;
}
scard take_card( splayer *player, sdeck *unhave )
{
    scard card;
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
        scard *card = ( scard * ) malloc( sizeof( scard ) * ( unsigned long long ) c );
        for ( int j = 0; j < c; j++ ) { card [ j ] = take_card( &player [ i ], unhave ); }
        disp( card, c );
        printf( "\n" );
        free( card );
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
_Bool check_defense( splayer x, scard *card, options input_option )
{
    int ans = 0;
    for ( int i = 0; i < x.num_card; i++ )
    {
        if ( x.card [ i ].rank == 5 ) { ans++; }
    }
    if ( ans == 0 ) return false;
    printf( "\nYou can defend by following cards. input 0 to abandon, int from 1 to %d to play\n", ans );
    scard *temp  = ( scard * ) malloc( sizeof( scard ) * ( unsigned long long ) x.num_card );
    int    index = 0;
    for ( int i = 0; i < x.num_card; i++ )
    {
        if ( x.card [ i ].rank == 5 )
        {
            temp [ index ] = x.card [ i ];
            index++;
        }
    }
    disp( temp, index );
    printf( "\n" );
    index = 1;
    if ( input_option.auto_run == false )
    {
        while ( scanf( "%d", &index ) )
        {
            if ( ( index >= 0 ) && ( index <= ans ) ) { break; }
            printf( "wrong number,again\n" );
        }
    }
    index--;
    if ( index == -1 )
    {
        free( temp );
        return false;
    }
    *card = temp [ index ];
    card_remove( x.card, temp [ index ], &x.num_card );
    free( temp );
    return true;
}
void card_remove( scard x [], scard ans, int *n )
{
    for ( int i = 0; i < ( *n ); i++ )
    {
        if ( ( x [ i ].suit == ans.suit ) && ( x [ i ].rank == ans.rank ) )
        {
            printf( "You played " );
            disp( &x [ ( *n ) - 1 ], 1 );
            printf( "\n" );
            swap_scard( &x [ ( *n ) - 1 ], &x [ i ] );
            ( *n )--;
            return;
        }
    }
    return;
}
void s_player_get_card( splayer player [], int n, int c, sdeck *unhave, FILE *x )
{
    printf( "Player %d draws: ", n + 1 );
    fprintf( x, "Player %d draws: ", n + 1 );
    scard *card = ( scard * ) malloc( sizeof( scard ) * ( unsigned long long ) c );
    for ( int j = 0; j < c; j++ ) { card [ j ] = take_card( &player [ n ], unhave ); }
    disp( card, c );
    fdisp( card, c, x );
    printf( "\n" );
    fprintf( x, "\n" );
    free( card );
    printf( "Your cards: " );
    disp( player [ n ].card, player [ n ].num_card );
    printf( "\n" );
    fprintf( x, "Player %d cards: ", n + 1 );
    fdisp( player [ n ].card, player [ n ].num_card, x );
    fprintf( x, "\n" );
    return;
}
_Bool win_check( splayer x [], int n, FILE *file )
{
    _Bool ans = false;
    for ( int i = 0; i < n; i++ )
    {
        if ( x [ i ].num_card == 0 )
        {
            ans = true;
            printf( "player %d ", i + 1 );
            fprintf( file, "player %d ", i + 1 );
        }
    }
    if ( ans == false ) return ans;
    printf( "wins!\n" );
    fprintf( file, "wins!\n" );
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
    char suit [ 4 ][ 9 ]  = { "Spades", "Hearts", "Diamonds", "Clubs" };                          // MAX="Diamonds\0"
    char rank [ 13 ][ 3 ] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" }; // MAX="10\0"
    for ( int i = 0; i < n - 1; i++ ) { fprintf( x, "%s %s,", suit [ card [ i ].suit ], rank [ card [ i ].rank ] ); }
    fprintf( x, "%s %s", suit [ card [ n - 1 ].suit ], rank [ card [ n - 1 ].rank ] );
    return;
}
void clean( )
{
    if ( OS == 0 )
        if ( system( "clear" ) ) { }
    if ( OS == 1 )
        if ( system( "cls" ) ) { }
    if ( OS == 2 )
        if ( system( "clear" ) ) { }
    return;
}
void init_game( options input_option, splayer player [], FILE *filename, int round )
{
    for ( int i = 0; i < input_option.n; i++ ) { player [ i ].num_card = 0; }
    srand_init( );
    printf( "---- Initial setup ----\n" );
    printf( "Number of rounds: %d\nNumber of decks: %d\nNumber of players: %d\n", round + 1, input_option.d, input_option.n );
    printf( "\n" );
    fprintf( filename, "---- Initial setup ----\n" );
    fprintf( filename, "Number of rounds: %d\nNumber of decks: %d\nNumber of players: %d\n", round + 1, input_option.d, input_option.n );
    fprintf( filename, "\n" );
    return;
}
void oneround( options input_option, FILE *filename, sdeck *unhave, splayer *player, int round )
{
    init_game( input_option, player, filename, round );
    card_init( unhave->card, unhave->num );
    // for ( int i = 0; i < input_option.n; i++ ) { player [ i ].num_card = 0; }
    printf( "Shuffling cards...\n" );
    fprintf( filename, "Shuffling cards...\n" );
    fprintf( filename, "Shuffle result: \n" );
    shuffle( unhave->card, unhave->card + unhave->num );
    fdisp( unhave->card, unhave->num, filename );
    player_get_card( player, input_option.n, input_option.c, unhave );
    printf( "\nDealing cards...\n" );
    fprintf( filename, "\nDealing cards...\n" );
    for ( int i = 0; i < input_option.n; i++ )
    {
        fprintf( filename, "Player %d: ", i + 1 );
        qsort( player [ i ].card, ( unsigned long int ) player [ i ].num_card, sizeof( scard ), compare_scard );
        fdisp( player [ i ].card, player [ i ].num_card, filename );
        fprintf( filename, "\n" );
    }
    int     now_player = check_first( player, input_option.n, unhave, filename );
    splayer ondesk;
    ondesk.card     = ( scard * ) malloc( sizeof( scard ) * ( unsigned long long ) input_option.r * ( unsigned long long ) 52 );
    ondesk.num_card = 0;
    scard now_card  = take_card( &ondesk, unhave );
    scard before_card_flag;
    before_card_flag.suit = 100;
    before_card_flag.rank = 100;
    seffect now_effect    = get_effect( now_card, before_card_flag );
    printf( "\n---- Game start ----\n" );
    printf( "First card: " );
    fprintf( filename, "\n---- Game start ----\n" );
    fprintf( filename, "First card: " );
    disp( &now_card, 1 );
    fdisp( &now_card, 1, filename );
    printf( "\n" );
    fprintf( filename, "\n" );
    _Bool win     = false;
    _Bool reverse = false;
    free( ondesk.card );
    while ( ! win ) { oneplayer( input_option, filename, unhave, player, &now_player, &now_card, &before_card_flag, &now_effect, &win, &reverse ); }
    printf( "\n---Stats---\n" );
    printf( "Round %d result:\n", round + 1 );
    for ( int i = 0; i < input_option.n; i++ ) { printf( "Player %d:%d, total: %d\n", i + 1, player [ i ].last_score, player [ i ].score ); }
    printf( "Round %d ends.\n", round + 1 );
    fprintf( filename, "\n---Stats---\n" );
    fprintf( filename, "Round %d result:\n", round + 1 );
    for ( int i = 0; i < input_option.n; i++ ) { fprintf( filename, "Player %d:%d, total: %d\n", i + 1, player [ i ].last_score, player [ i ].score ); }
    fprintf( filename, "Round %d ends.\n", round + 1 );
    return;
}
void oneplayer( options  input_option,
                FILE *   filename,
                sdeck *  unhave,
                splayer *player,
                int *    now_player,
                scard *  now_card,
                scard *  before_card_flag,
                seffect *now_effect,
                _Bool *  win,
                _Bool *  reverse )
{
    clean( );
    *now_effect                  = get_effect( ( *now_card ), ( *before_card_flag ) );
    *before_card_flag            = ( *now_card );
    unhave->card [ unhave->num ] = ( *now_card );
    shuffle( unhave->card, unhave->card + unhave->num );
    printf( "now card:\n" );
    disp( ( now_card ), 1 );
    printf( "\n" );
    int temp_int;
    if ( ( *now_effect ).reverse == true ) *reverse = ( ! ( *reverse ) );
    if ( ( *now_effect ).skip == true )
    {
        fprintf( filename, "Player %d is skiped.\nPlayer %d cards: ", *now_player + 1, *now_player + 1 );
        printf( "You are skiped.\nYour cards: " );
        disp( player [ *now_player ].card, player [ *now_player ].num_card );
        fdisp( player [ *now_player ].card, player [ *now_player ].num_card, filename );
        fprintf( filename, "\n" );
        printf( "\n" );
        if ( ( *reverse ) == false ) *now_player = ( *now_player + 1 ) % input_option.n;
        else
            *now_player = ( *now_player - 1 + input_option.n ) % input_option.n;
        return;
    }
    if ( ( *now_effect ).get2 == true || ( *now_effect ).get3 == true )
    {
        if ( check_defense( player [ *now_player ], now_card, input_option ) == true )
        {
            printf( "Next player\n" );
            if ( ( *reverse ) == false ) *now_player = ( *now_player + 1 ) % input_option.n;
            else
                *now_player = ( *now_player - 1 + input_option.n ) % input_option.n;
            return;
        }
        {
            if ( ( *now_effect ).get2 == true ) s_player_get_card( player, ( *now_player ), 2, unhave, filename );
            if ( ( *now_effect ).get3 == true ) s_player_get_card( player, ( *now_player ), 3, unhave, filename );
            return;
        }
    }
    _Bool flag = false;
    temp_int   = player [ ( *now_player ) ].num_card;
    while ( flag == false )
    {
        printf( "Player %d:you have those card,plese choose one\n", ( *now_player ) + 1 );
        printf( "from 1 to %d, 0 to abandon\n", player [ ( *now_player ) ].num_card );
        disp( ( player [ ( *now_player ) ].card ), player [ ( *now_player ) ].num_card );
        printf( "\n" );
        if ( input_option.auto_run == false )
        {
            while ( scanf( "%d", &temp_int ) )
            {
                if ( ( temp_int >= 0 ) && ( temp_int <= player [ ( *now_player ) ].num_card ) ) break;
                printf( "wrong number,again\n" );
            }
        }
        temp_int--;
        if ( temp_int == -1 )
        {
            s_player_get_card( player, ( *now_player ), 1, unhave, filename );
            printf( "NEXT\n" );
            flag = true;
        }
        else
        {
            if ( check_okay( ( *now_card ), player [ ( *now_player ) ].card [ temp_int ] ) == true )
            {
                ( *now_card ) = player [ ( *now_player ) ].card [ temp_int ];
                fprintf( filename, "Player %d plays: ", ( *now_player ) + 1 );
                fdisp( now_card, 1, filename );
                fprintf( filename, "\n" );
                card_remove( player [ ( *now_player ) ].card, ( *now_card ), &player [ ( *now_player ) ].num_card );
                if ( player [ ( *now_player ) ].num_card == 0 )
                {
                    printf( "player %d ", ( *now_player ) + 1 );
                    fprintf( filename, "player %d ", ( *now_player ) + 1 );
                    printf( "wins!\n" );
                    fprintf( filename, "wins!\n" );
                    for ( int i = 0; i < input_option.n; i++ )
                    {
                        player [ i ].score -= player [ i ].num_card;
                        player [ i ].last_score = -player [ i ].num_card;
                    }
                    ( *win ) = true;
                    break;
                }
                printf( "Your cards: " );
                disp( player [ ( *now_player ) ].card, player [ ( *now_player ) ].num_card );
                printf( "\n" );
                fprintf( filename, "Player %d cards: ", ( *now_player ) + 1 );
                fdisp( player [ ( *now_player ) ].card, player [ ( *now_player ) ].num_card, filename );
                fprintf( filename, "\n" );
                flag = true;
            }
            else
            {
                printf( "wrong number,again\n" );
            }
        }
    }
    if ( ( *reverse ) == false ) ( *now_player ) = ( ( *now_player ) + 1 ) % input_option.n;
    else
        ( *now_player ) = ( ( *now_player ) - 1 + input_option.n ) % input_option.n;
    return;
}