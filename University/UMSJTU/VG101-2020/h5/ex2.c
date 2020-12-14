#include "assignment.h"

// ex. 2 function: disptach work to other functions for exercise 2

void ex2( )
{
    int  month, date;
    char week [ 5 ];
    int  month_date [ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // days in each month
    if ( scanf( "%d %s", &month, week ) )
    {
        ex2_print( month );
        /* deleted because of casuing warning in gcc and "not good for you" (https://piazza.com/class/kf3cejsqxny6js?cid=214)
        switch ( week [ 0 ] + week [ 1 ] + week [ 2 ] )
        {
            case 'S' + 'u' + 'n':
                date--;
            case 'M' + 'o' + 'n':
                date--;
            case 'T' + 'u' + 'e':
                date--;
            case 'W' + 'e' + 'd':
                date--;
            case 'T' + 'h' + 'u':
                date--;
            case 'F' + 'r' + 'i':
                date--;
            case 'S' + 'a' + 't':
                date--;
        }
        */
        if ( strcmp( week, "Sun" ) == 0 ) date = 0;
        if ( strcmp( week, "Mon" ) == 0 ) date = 1;
        if ( strcmp( week, "Tue" ) == 0 ) date = 2;
        if ( strcmp( week, "Wed" ) == 0 ) date = 3;
        if ( strcmp( week, "Thu" ) == 0 ) date = 4;
        if ( strcmp( week, "Fri" ) == 0 ) date = 5;
        if ( strcmp( week, "Sat" ) == 0 ) date = 6;
        printf( "Sun Mon Tue Wed Thu Fri Sat\n" );
        for ( int i = 0; i < date; i++ ) { printf( "    " ); } // print the days of previous month
        for ( int i = 1; i <= month_date [ month ]; i++ )
        {
            printf( "%3d", i );
            if ( ( date + i - 1 ) % 7 == 6 ) printf( "\n" );
            else
                printf( " " );
        }
    }
    return;
}
void ex2_print( int month )
{
    if ( month == 1 ) printf( "January" );
    if ( month == 2 ) printf( "February" );
    if ( month == 3 ) printf( "March" );
    if ( month == 4 ) printf( "April" );
    if ( month == 5 ) printf( "May" );
    if ( month == 6 ) printf( "June" );
    if ( month == 7 ) printf( "July" );
    if ( month == 8 ) printf( "August" );
    if ( month == 9 ) printf( "September" );
    if ( month == 10 ) printf( "October" );
    if ( month == 11 ) printf( "November" );
    if ( month == 12 ) printf( "December" );
    printf( "\n" );
    return;
}
#ifdef JOJ
int main( )
{
    ex2( );
    return 0;
}
#endif
