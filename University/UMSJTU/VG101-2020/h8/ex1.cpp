/**********************************
    Written by WANGZINING
    blog: https://wznmickey.com
**********************************/

#include "assignment.h"
#include <bits/stdc++.h>
using namespace std;
#define MAX_LENGTH 5000
void ex1_reverse_array( )
{
    string input [ MAX_LENGTH ];
    string temp;
    int    i = 0;
    while ( cin >> temp )
    {
        input [ i ] = temp;
        i++;
    }
    i--;
    while ( i >= 0 )
    {
        cout << input [ i ] << " ";
        i--;
    }
    return;
}
void ex1_reverse_vector( )
{
    vector< string > input;
    string           temp;
    int              i = 0;
    while ( cin >> temp )
    {
        input.push_back( temp );
        i++;
    }
    i--;
    while ( i >= 0 )
    {
        cout << input [ ( unsigned long ) i ] << " ";
        i--;
    }
    return;
}
void ex1_reverse_stack( )
{
    stack< string > input;
    string          temp;
    while ( cin >> temp ) { input.push( temp ); }
    while ( ! input.empty( ) )
    {
        cout << input.top( ) << " ";
        input.pop( );
    }
    return;
}
void ex1_ordered_array( )
{
    string input [ MAX_LENGTH ];
    string temp;
    int    i = 0;
    while ( cin >> temp )
    {
        input [ i ] = temp;
        i++;
    }
    for ( int j = 0; j < i; j++ ) { cout << input [ j ] << " "; }
    return;
}
void ex1_ordered_vector( )
{
    vector< string > input;
    string           temp;
    int              i = 0;
    while ( cin >> temp )
    {
        input.push_back( temp );
        i++;
    }
    i--;
    for ( int j = 0; j <= i; j++ ) { cout << input [ ( unsigned long ) j ] << " "; }
    return;
}
void ex1_ordered_queue( )
{
    queue< string > input;
    string          temp;
    while ( cin >> temp ) { input.push( temp ); }
    while ( ! input.empty( ) )
    {
        cout << input.front( ) << " ";
        input.pop( );
    }
    return;
}