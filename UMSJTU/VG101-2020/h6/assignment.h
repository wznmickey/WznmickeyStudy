//
// Created by patri on 2016/6/18.
//
#ifndef H6
#define H6

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define true 1
#define false 0
#define PI acos( -1 )

// ex1
void function_ex1( );

// ex2
struct _complex_ab
{
    double a, b;
};
struct _complex_angel
{
    double r, t;
};
typedef struct _complex_ab    com1;
typedef struct _complex_angel com2;
void                          C2P( com1 *x, com2 *y, int n );
void                          P2C( com1 *x, com2 *y, int n );

// ex4
void swap_int( int *x, int *y );

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
extern void ex7( );
#endif // H6
