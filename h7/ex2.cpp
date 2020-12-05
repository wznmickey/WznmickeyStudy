#include "assignment.h"
#include <bits/stdc++.h>
using namespace std;
void ex2( )
{

    int    check, p;
    double before, after;
    scanf( "%d", &check );
    cin >> before;
    scanf( "%d", &p );
    if ( check == 1 ) { after = before * 6.20350; }
    else
    {
        after = before / 6.20350;
    }
    // cout << after;
    int x = 0;
    // for (i = 0; i < p; i++)
    //{
    while ( after > 1 )
    {
        after = after / 10;
        x++;
    }
    for ( int i = 0; i < x; i++ ) { after = after * 10; }
    cout << fixed << showpoint << setprecision( p - x ) << after << endl;
    /*
    cout << round( 6203.5 ) << endl;
    cout << after << endl;
    cout << round( after ) << endl;

    cout << endl << endl << endl;
    after = round( after );
    cout << endl << endl << endl;
    // after = round(after);
    cout << after << endl;
    for ( int i = 0; i < p; i++ ) { after = after / 10; }
    if ( x >= 1 )
    {
        for ( int i = 0; i < p; i++ )
        {
            after = after * 10;     // cout<<after<<endl;
            cout << floor( after ); //<<endl;
            after -= floor( after );
            if ( x == i + 1 ) printf( "." );
        }
    }
    else
    {
        cout << "0.";
        for ( int i = 0; i < p; i++ )
        {
            after = after * 10;     // cout<<after<<endl;
            cout << floor( after ); //<<endl;
            after -= floor( after );
        }
    }
    //}
    // cout << fixed << setprecision(p) << after;
    */
    return;
}
#ifdef JOJ
int main( )
{
    ex2( );
    return 0;
}
#endif
