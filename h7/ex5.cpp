#include <bits/stdc++.h>
using namespace std;
static const char GRADES [] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A' };
class Grade
{
private:
    char ltr;
    char prct;

public:
    void printGrade( Grade *grade )
    {

        printf( "Grade: %d -> %c\n", grade->prct, grade->ltr );
    }
    void GradeLtr( Grade *grade, char ltr )
    {
        grade->ltr  = ltr;
        grade->prct = 100 - ( ltr - 'A' ) * 10 - 5;
    }
    void GradePrct( Grade *grade, int prct )
    {

        grade->prct = prct;
        grade->ltr  = GRADES [ prct / 10 ];
    }
};

int main( )
{
    Grade g;
    int   prct;

    printf( "Input two space seprated grades (1st in %%, 2nd in letter): " );
    cin >> prct;
    g.GradePrct( &g, prct );
    g.printGrade( &g );
    while ( cin.peek( ) == '\n' || cin.peek( ) == ' ' ) { cin.get( ); }
    g.GradeLtr( &g, ( char ) cin.get( ) );
    g.printGrade( &g );

    return 0;
}