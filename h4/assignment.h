//
// Created by patri on 2016/6/18.
//
#ifndef CTEMPLATE_ASSIGNMENT_H
#define CTEMPLATE_ASSIGNMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
struct ComplexNum
{
	long long a,b;
};
struct ComplexNum plus(struct ComplexNum num1,struct ComplexNum num2);
struct ComplexNum times(struct ComplexNum num1,struct ComplexNum num2);
void print(struct ComplexNum ans);
struct ComplexNum init();
void swap(long long *a,long long *b);
long long gcd(long long a,long long b);
void check1(double a,double b);
void check2(double a,double b,double c);
void call_f1();
void call_f2();
long int mpow (int a, int b);
int quo (int a, int b) ;
int sum (int a, int b) ;
int prod (int a, int b);
int rem (int a, int b);
int getExerciseNumber(int argc, char* argv[]);
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

extern void ex1();
extern void ex2();
extern void ex3();
extern void ex4();
extern void ex5();
#endif //CTEMPLATE_ASSIGNMENT_H
