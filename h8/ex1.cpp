#include "assignment.h"
#include <bits/stdc++.h>
using namespace std;
void ex1_reverse_array( )
{
    string input [ 100 ];
    int    i = 0;
    while ( cin >> input [ i ] ) i++;
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
int main( )
{
    ex1_reverse_vector( );
    return 0;
}