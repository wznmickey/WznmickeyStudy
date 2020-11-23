#include <bits/stdc++.h>
using namespace std;

static const char GRADES [] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A' };

typedef struct _Grade
{

    char ltr;
    int  prct;
} Grade;

void GradePrct( Grade *grade, int prct )
{

    grade->prct = prct;
    grade->ltr  = GRADES [ prct / 10 ];
}

void GradeLtr( Grade *grade, char ltr )
{
    grade->ltr  = ltr;
    grade->prct = 100 - ( ltr - 'A' ) * 10 - 5;
}

void printGrade( Grade *grade )
{

    printf( "Grade: %d -> %c\n", grade->prct, grade->ltr );
}

int main( )
{
    Grade g;
    int   prct;

    printf( "Input two space seprated grades (1st in %%, 2nd in letter): " );
    scanf( "%d", &prct );
    scanf( "\n" );

    GradePrct( &g, prct );
    printGrade( &g );

    GradeLtr( &g, getchar( ) );
    printGrade( &g );

    return 0;
}