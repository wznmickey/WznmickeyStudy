#include "devices.h"
#include <iostream>
using namespace std;
int main( )
{
    int x;
    cout << "Choose a device type(1. American 2.Asian 3.Australian 4.Australian): " << endl;
    cin >> x;
    if ( x == 1 )
    {
        cout << "Testing American device..." << endl;
        American devices = American( );
    }
    if ( x == 2 )
    {
        cout << "Testing Asian device..." << endl;
        Asian devices = Asian( );
    }
    if ( x == 3 )
    {
        cout << "Testing Australian device..." << endl;
        Australian devices = Australian( );
    }
    if ( x == 4 )
    {
        cout << "Testing Australian device..." << endl;
        Australian devices = Australian( );
    }
    return 0;
}