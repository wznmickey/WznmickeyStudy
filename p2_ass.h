#ifndef P2_ASS
#define P2_ASS

#define true 1
#define false 0

#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef __linux__
#define OS 0
#endif
#ifdef _WIN32
#define OS 1
#endif
#ifdef TARGET_OS_MAC
#define OS 2
#endif

typedef struct scard
{
    int suit, rank;
} scard; // s(truct _)card
typedef struct _player
{
    // int       no;
    long long score;
    int       num_card;
    scard     card [ 10 * 52 + 1 ];
} splayer; // s(truct _)player
typedef struct _options
{
    _Bool auto_run, help;
    int   n, c, d, r;
    char  filename [ FILENAME_MAX + 10 ];
} options;
typedef struct _deck
{
    /*
    -1  -wait to be owned
    -2 -be played
    x  -be owned by player
    */
    char  no;
    int   num;
    scard card [];
} sdeck; // s(truct _)deck
options get_info( int argc, char *argv [] );
options option_init( );
void    card_init( scard card [], int d );
void    disp( scard card [], int n );
void    wait_player( char name [], char key );
void    shuffle( scard *first, scard *last );
void    swap_scard( scard *a, scard *b );
void    srand_init( );
int     compare_scard( const void *a, const void *b );
int     check_first( splayer player [], int n, sdeck *unhave );
void    player_init( splayer player [], int n );
scard   take_card( splayer *player, sdeck *unhave );
int     get_card_no( scard card );
void    player_get_card( splayer player [], int n, int c, sdeck *unhave );
#endif