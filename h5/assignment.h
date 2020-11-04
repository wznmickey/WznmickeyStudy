//
// Created by patri on 2016/6/18.
//
#ifndef H5
#define H5

#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define true 1
#define false 0
#define M_PI 3.14159265358979323846
#define SWAP( a, b )                                                                                                                                           \
    {                                                                                                                                                          \
        a ^= b;                                                                                                                                                \
        b ^= a;                                                                                                                                                \
        a ^= b;                                                                                                                                                \
    }

#ifdef __linux__
#define OS 0
#endif
#ifdef _WIN32
#define OS 1
#endif
#ifdef TARGET_OS_MAC
#define OS 2
#endif

// ex1
#define not_prime( i )   bitmap [ i >> 3 ] |= ( unsigned char ) ( ( unsigned int ) 1 << ( i & 0x07 ) )
#define check_prime( i ) ( bitmap [ i >> 3 ] & ( unsigned char ) ( ( unsigned int ) 1 << ( i & 0x07 ) ) )

// ex2
void ex2_print( int month );

// ex4
double fx( double x, double th2, double th1, double th0 );

// ex5
typedef struct scard
{
    int suit, rank;
} scard; // s(truct _)card
void card_init( struct scard card [] );
void disp( struct scard card [] );
void wait_player( char name [], char key );
void shuffle( scard *first, scard *last );
void swap_scard( scard *a, scard *b );
void srand_init( );
int  compare_scard( const void *a, const void *b );

// ex6
unsigned long int mult( unsigned long int a, unsigned long int b );
int               divide( unsigned long long x, int l, int r );

int getExerciseNumber( int argc, char *argv [] );
/* This function gets the exercise number to run from
 * 1. programe argument (for graders)
 * 2. student input prompt (for students)
 * To input the number from argument, call "outputFile.exe -exN"
 * for exercise N. Assume 0 < N < 10
 * To input it from prompt, enter an integer between 1 to 9
 * Wrong input will be prompt for re-input.
 *
 * Written by VG101_SU16TA/patrick
 */

extern void ex1( );
extern void ex2( );
extern void ex3( );
extern void ex4( );
extern void ex5( );
extern void ex6( );

#endif // H5
