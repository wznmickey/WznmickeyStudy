#ifndef P2_ASS
#define P2_ASS

#define true 1
#define false 0
#define bool _Bool

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
#ifdef __APPLE__
#define OS 2
#endif

typedef struct struct_card
{
    int suit, rank;
} scard; // s(truct _)card
typedef struct struct_player
{
    // int       no;
    int   score;
    int   num_card;
    int   last_score;
    scard card [ 10 * 52 + 1 ];
} splayer; // s(truct _)player
typedef struct struct_options
{
    _Bool auto_run, help;
    int   n, c, d, r;
    char  filename [ FILENAME_MAX + 10 ];
} options;
typedef struct struct_deck
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
typedef struct struct_effect
{
    _Bool get2, get3, reverse, skip;
} seffect;
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
_Bool   check_okay( scard x, scard y );
_Bool   win_check( splayer x [], int n );
void    s_player_get_card( splayer player [], int n, int c, sdeck *unhave );
void    card_remove( scard x [], scard ans, int *n );
_Bool   check_defense( splayer x, scard *card );
seffect get_effect( scard x, scard y );
void fdisp( scard card [], int n, FILE *x );
#endif